/*****
 *   Matthew Gavin
 *   Joshua Springer
 *   CSC 3102, Fall 2012, Section 1
 *   Programming Homework #1
 *
 *   Description:
 *       Declares the AVL tree.
 *   
 *****/

#ifndef AVL_TREE
#define AVL_TREE

#include <functional>
#include "debug.hpp"

template <typename T, typename compare = std::less<T> >
class AVLTree
{
    
private:
    T data;
    AVLTree<T, compare>* parent;
    AVLTree<T, compare>* left;
    AVLTree<T, compare>* right;

    void transplant(AVLTree<T, compare>* x, AVLTree<T, compare>* y);
    void insert(AVLTree<T, compare>* root, AVLTree<T, compare>* z);
    AVLTree<T, compare>* find(const T& data);
public:
    AVLTree(T data);
    ~AVLTree();

    void insert(const T& data);
    void remove(AVLTree<T, compare>* x);
    void inorder();
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
    AVLTree<T>* node = new AVLTree<T, compare>;
    node->data = data;
    insert(this, node);
}

template <typename T, typename compare>
void AVLTree<T, compare>::transplant(AVLTree<T, compare>* x, AVLTree<T, compare>* y)
{
    if (x->parent == NULL)
    {
        x = y;
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
        AVLTree<T>* y = min( x->right );
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
    if (find(k) != NULL)
        return true;
    return false;
}

template <typename T, typename compare>
AVLTree<T, compare>* AVLTree<T, compare>::find(const T& k)
{
    if ( x == NULL )
        return NULL;
    if ( x->data == k )
        return x;
    if ( x->data > k )
        return find( x->left, k );
    return find( x->right, k );
}

template <typename T, typename compare>
AVLTree<T, compare>* AVLTree<T, compare>::predecessor(const T& data)
{
    AVLTree<T>* x = find(data);
    if ( x->left != NULL )
        return max( x->left );
    y = x->parent;
    while ( y != NULL && x == y->left )
    {
        x = y;
        y = y->parent;
    }
    return y;
}

template <typename T, typename compare>
AVLTree<T, compare>* AVLTree<T, compare>::successor(const T& data)
{
    AVLTree<T>* x = find(data);
    if ( x->right != NULL )
        return min( x->right );
    y = x->parent;
    while ( y != NULL && x == y->right )
    {
        x = y;
        y = y->parent;
    }
    return y;
}

#endif
