/*****
 *   Matthew Gavin
 *   Joshua Springer
 *   CSC 3102, Fall 2012, Section 1
 *   Programming Homework #1
 *
 *   Description:
 *       Declares and defines the AVL tree.
 *   
 *****/

#ifndef AVL_TREE
#define AVL_TREE

#include <functional>
#include <fstream>
#include "debug.hpp"

template <typename T, typename compare = std::less<T> >
class AVLTree
{
    
private:
    T data;
    int balance_factor, height ;
    AVLTree<T, compare>* parent;
    AVLTree<T, compare>* left;
    AVLTree<T, compare>* right;

    void transplant(AVLTree<T, compare>* x, AVLTree<T, compare>* y);
    void insert(AVLTree<T, compare>* root, AVLTree<T, compare>* z);
    AVLTree<T, compare>* find(AVLTree<T, compare>* node, const T& data);
    AVLTree<T, compare>* find_closest(AVLTree<T, compare>* node, const T& k);
        
public:
    AVLTree(T data);
    ~AVLTree();

    void insert(const T& data);
    void remove(AVLTree<T, compare>* x);
    void inorder(const std::ofstream& fout);
    AVLTree<T, compare>* min();
    AVLTree<T, compare>* max();
    AVLTree<T, compare>* predecessor(const T& data);
    AVLTree<T, compare>* successor(const T& data);
    int rank(const T& data);
    bool search(const T& data);

    AVLTree<T, compare>* (*select)(const T& data);
};

template <typename T, typename compare>
AVLTree<T, compare>::AVLTree(T data):data(data)
{
    parent = left = right = NULL;
    select = find;
}

template <typename T, typename compare>
AVLTree<T, compare>::~AVLTree()
{
    if (left != NULL)
        delete left;
    if (right != NULL)
        delete right;
}

template <typename T, typename compare>
void AVLTree<T, compare>::insert(AVLTree<T, compare>* root, AVLTree<T, compare>* z)
{
    if (root->data == z->data) return;
    if (compare()(root->data, z->data))
    {
        if (root->left) insert(root->left, z);
        else {
            root->left = z;
            z->parent = root;
        }
    }
    else
    {
        if (root->right) insert(root->right, z);
        else {
            root->right = z;
            z->parent = root;
        }
    }
}

template <typename T, typename compare>
void AVLTree<T, compare>::insert(const T& data)
{
    if (this->data == data) return;
    AVLTree<T, compare>* node = new AVLTree<T, compare>;
    node->data = data;
    insert(this, node);
}

template <typename T, typename compare>
void AVLTree<T, compare>::transplant(AVLTree<T, compare>* x, AVLTree<T, compare>* y)
{
    if (x->parent == NULL) //x is root
    {
        x.data = y.data;
        x->left = y->left;
        x->right = y->right;
    }
    else if (x->parent->left == x)
    {
        x->parent->left = y;
    }
    else
        x->parent->right = y;
    if (y != NULL)
        y->parent = x->parent;
}

template <typename T, typename compare>
void AVLTree<T, compare>::remove(AVLTree<T, compare>* x)
{
    if ( !x->left && !x->right ) 
        transplant( x, NULL );
    else if ( x->left == NULL )
        transplant( x, x->right ) ;
    else if ( x->right == NULL )
        transplant( x, x->left ) ; 
    else
    {  
        AVLTree<T, compare>* y = min( x->right );
        if ( y->parent == x )
        {
            transplant( x, y );
            y->left = x->left;
            x->left->parent = y;
        }
        else
        {
            transplant( y, y->right ); 
            transplant( x, y );
            y->right = x->right;
            y->left = x->left;
            x->right->parent = x->left->parent = y;
        }
    }
}

template <typename T, typename compare>
AVLTree<T, compare>* AVLTree<T, compare>::min()
{
    while ( x->left != NULL )
        x = x->left;
    return x;
}

template <typename T, typename compare>
AVLTree<T, compare>* AVLTree<T, compare>::max()
{
    while ( x->right != NULL )
        x = x->right;
    return x;
}

template <typename T, typename compare>
bool AVLTree<T, compare>::search(const T& k)
{
    if (find(this, k) != NULL)
        return true;
    return false;
}

template <typename T, typename compare>
AVLTree<T, compare>* AVLTree<T, compare>::find(AVLTree<T, compare>* node, const T& k)
{
    if ( node == NULL )
        return NULL;
    if ( node->data == k )
        return node;
    if ( node->data > k )
        return find( node->left, k );
    return find( node->right, k );
}

template <typename T, typename compare>
AVLTree<T, compare>* AVLTree<T, compare>::find_closest(AVLTree<T, compare>* node, const T& k)
{
    if ( node == NULL )
        return NULL;
    if ( node->data == k )
        return node;
    if ( node->data > k && node->left != NULL)
        return find_closest( node->left, k );
    else if (node->right != NULL)
        return find_closest( node->right, k );
    return node;
}

template <typename T, typename compare>
AVLTree<T, compare>* AVLTree<T, compare>::predecessor(const T& data)
{
    AVLTree<T, compare>* x = find_closest(this, data);
    if (x == NULL)
        return NULL;
    if (x->left != NULL)
        return max( x->left );
    
    AVLTree<T, compare>* y = x->parent;
    while (y != NULL && x == y->left)
    {
        x = y;
        y = y->parent;
    }
    
    return y;
}

template <typename T, typename compare>
AVLTree<T, compare>* AVLTree<T, compare>::successor(const T& data)
{
    AVLTree<T, compare>* x = find_closest(this, data);
    if (x == NULL)
        return NULL;
    if (x->right != NULL )
        return min( x->right );
    
    AVLTree<T, compare>* y = x->parent;
    while (y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

// Assume *x has left child
Node * r_rotate( Node *x )
{
   y = x->left ;
   Transplant( y, y->right );
   Transplant( x, y );
   y->right = x ;
   x->parent = y ;
 }

 // Assume *x has left child 
 // and *(x->left) has right child
 Node * lr_rotate( Node *x ) {
   L_rotate( x->left ) ;
   R_rotate( x );
 }

void Insert( Node *x, Node *z ) {
  if ( x->key < z->key ) {
    if ( x->right )  Insert( x->right, z );
    else x->right = z ;       
  } 
  else ...
}

void Insert( Node *x, Node *z )
{
    bool height_inc = false;
    if ( x->key < z->key )
    {
        if ( x->right )
            insert( x->right, z );
        else
        {
            x->right = z ;
            z->bf = 0 ;   	
            height_inc = true ;
        }
        if ( height_inc )
        {
            /* Case 2.1 */   
            if ( x->bf == 0 )  
                x->bf = -1 ;
            /* Case 2.2 */
            else if ( x->bf == 1 )
            {
                x->bf = 0 ;
                height_inc = false;
            }
            /* Case 2.3 */ 
            else {
                /* First Subcase */
                if ( x->right->bf == -1 ) {
                    L_rotate( x );  
                    x->bf = x->parent->bf = 0 ;
                    height_inc = false ;
                }
                // Second Subcase
                else if ( x->right->bf == 1 ) {
                    int b = x->right->left->bf ;       
                    LR_rotate( x );  x->parent->bf = 0;
                    if ( b == 0 )
                    { x->bf = x->parent->right->bf = 0; }
                    else if ( b == 1 )
                    { x->bf = 0; x->parent->right->bf = -1; }
                    else if ( b == -1 )
                    { x->bf = 1; x->parent->right->bf = 0; }
                    height_inc = false ;
                }
            }
        }
    }
}

template <typename T, typename compare>
int AVLTree<T, compare>::rank(AVLTree<T, compare>* x, const T& data)
{ 
    if (x == NULL)
        return 0;
    if (k < x->key)
        return(rank(x->left,k));              
    if (k = x->key)
        return (x->left->size+1);
    return(x->left->size+1+rank(x->right,k));
}

template <typename T, typename compare>
AVLTree<T, compare>* AVLTree<T, compare>::select(AVLTree<T, compare>* x, const T& data)
{
     if (x == NULL)
         return NULL; 
     if (x->left->size >= data)
         return select(x->left,i);
     if (x->left->size +1 == data) 
         return x;
     return select(x->right,data-1-(x->left->size));
}

#endif
