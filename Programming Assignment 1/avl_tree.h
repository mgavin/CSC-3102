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

template <typename T>
class AVLTree
{
 public:
    AVLTree();
    ~AVLTree();

 private:
    T* data;
    Node* nodes[2];
}

#endif
