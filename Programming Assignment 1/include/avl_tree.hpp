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
    int balance_factor, height;
    AVLTree<T, compare>* parent;
    AVLTree<T, compare>* left;
    AVLTree<T, compare>* right;

    void transplant(AVLTree<T, compare>* x, AVLTree<T, compare>* y);
    void insert(AVLTree<T, compare>* root, AVLTree<T, compare>* z);
    AVLTree<T, compare>* find(AVLTree<T, compare>* node, const T& data);
    AVLTree<T, compare>* find_closest(AVLTree<T, compare>* node, const T& k);
    void r_rotate(AVLTree<T, compare>* x);
    void l_rotate(AVLTree<T, compare>* x);
    void rl_rotate(AVLTree<T, compare>* x);
    void lr_rotate(AVLTree<T, compare>* x);
    
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
    int rank(AVLTree<T, compare>* x, const T& data);
    bool search(const T& data);
    T get_data() const { return data; }

    AVLTree<T, compare>* select(AVLTree<T, compare>* node, const T& data);
};

template <typename T, typename compare>
AVLTree<T, compare>::AVLTree(T data):data(data)
{
    parent = left = right = NULL;
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
void AVLTree<T, compare>::insert(const T& data)
{
    if (this->data == data) return;
    AVLTree<T, compare>* node = new AVLTree<T, compare>(data);
    insert(this, node);
}

template <typename T, typename compare>
void AVLTree<T, compare>::transplant(AVLTree<T, compare>* x, AVLTree<T, compare>* y)
{
    if (x->parent == NULL) //x is root
    {
        x->data = y->data;
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
    AVLTree<T, compare>* node = this;
    while ( node->left != NULL )
        node = node->left;
    return node;
}

template <typename T, typename compare>
AVLTree<T, compare>* AVLTree<T, compare>::max()
{
    AVLTree<T, compare>* node = this;
    while ( node->right != NULL )
        node = node->right;
    return node;
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
        return x->left->max();
    
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
        return x->right->min();
    
    AVLTree<T, compare>* y = x->parent;
    while (y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

// Assume *x has left child
template <typename T, typename compare>
void AVLTree<T, compare>::r_rotate(AVLTree<T, compare>* x)
{
    AVLTree<T, compare>* y = x->left;  
    y->parent = x->parent;
    AVLTree<T, compare>* z = y->right;
    y->right = x;
    x->parent = y;
    x->left = z; 
    if (z != NULL) z->parent = x; 
    x->height = 1 + x->parent->height;
    y->height = 1 + y->parent->height;
}

// Assume *x has right child
template <typename T, typename compare>
void AVLTree<T, compare>::l_rotate(AVLTree<T, compare>* x)
{
    AVLTree<T, compare>* y = x->right;
    transplant( y, y->left );
    transplant( x, y );
    y->left = x;
    x->parent = y;
}

// Assume *x has left child 
// and *(x->left) has right child
template <typename T, typename compare>
void AVLTree<T, compare>::lr_rotate(AVLTree<T, compare>* x)
{
    l_rotate( x->left ) ;
    r_rotate( x );
}

template <typename T, typename compare>
void AVLTree<T, compare>::rl_rotate(AVLTree<T, compare>* x)
{
    r_rotate( x );
    l_rotate( x->left ) ;
}

template <typename T, typename compare>
void AVLTree<T, compare>::insert(AVLTree<T, compare>* root, AVLTree<T, compare>* z)
{
    bool height_inc = false;
    if ( root->data < z->data )
    {
        if ( root->right )
            insert( root->right, z );
        else
        {
            root->right = z ;
            z->balance_factor = 0 ;   	
            height_inc = true ;
        }
        if ( height_inc )
        {
            /* Case 2.1 */   
            if ( root->balance_factor == 0 )  
                root->balance_factor = -1 ;
            /* Case 2.2 */
            else if ( root->balance_factor == 1 )
            {
                root->balance_factor = 0 ;
                height_inc = false;
            }
            /* Case 2.3 */ 
            else
            {
                /* First Subcase */
                if ( root->right->balance_factor == -1 )
                {
                    l_rotate( root );  
                    root->balance_factor = root->parent->balance_factor = 0 ;
                    height_inc = false ;
                }
                // Second Subcase
                else if ( root->right->balance_factor == 1 )
                {
                    int b = root->right->left->balance_factor ;       
                    lr_rotate( root );
                    root->parent->balance_factor = 0;
                    if ( b == 0 )
                    {
                        root->balance_factor = root->parent->right->balance_factor = 0;
                    }
                    else if ( b == 1 )
                    {
                        root->balance_factor = 0;
                        root->parent->right->balance_factor = -1;
                    }
                    else if ( b == -1 )
                    {
                        root->balance_factor = 1;
                        root->parent->right->balance_factor = 0;
                    }
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
    if (data < x->data)
        return (rank(x->left, data));
    if (data == x->data)
        return (x->left->height + 1);
    return (x->left->height + 1 + rank(x->right,data));
}

template <typename T, typename compare>
void AVLTree<T, compare>::inorder(const std::ofstream& fout)
{
    //left
    //print
    //right
}

template <typename T, typename compare>
AVLTree<T, compare>* AVLTree<T, compare>::select(AVLTree<T, compare>* x, const T& data)
{
    if (x == NULL)
        return NULL; 
    if (x->left->height >= data)
        return select(x->left, data);
    if (x->left->height + 1 == data) 
        return x;
    return select(x->right , data - 1 - (x->left->height));
}

#endif
