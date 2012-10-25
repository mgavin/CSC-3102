/*****
 *   Matthew Gavin
 *   Joshua Springer
 *   CSC 3102, Fall 2012, Section 1
 *   Programming Homework #1
 *
 *   Description:
 *       The main file for processing input and providing input for our
 *       data structures that will be used.
 *   
 *****/

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <iomanip>
#include <ctime>
#include <functional>

#include "k_ary_heap.hpp"
#include "avl_tree.hpp"
#include "sorts.hpp"
#include "timer.hpp"
#include "debug.hpp"

using namespace std;

static KAryHeap<int, 3> int_heap_s3;
static AVLTree<int> int_avl_tree;

template <typename T>
void insert(KAryHeap<T>& heap, const T& data)
{
    heap.insert(data);
}

template <typename T>
T& extract_min(KAryHeap<T>& heap)
{
    return heap.extract();
}

template <typename T>
void insert(AVLTree<T>& avl_tree, const T& data)
{
    avl_tree.insert(data);
}

template <typename T>
AVLTree<T>* min(AVLTree<T>& avl_tree, const T& data)
{
    return avl_tree.min();
}

template <typename T>
AVLTree<T>* max(AVLTree<T>& avl_tree, const T& data)
{
    return avl_tree.max();
}


template <typename T>
void inorder_traversal(AVLTree<T>& avl_tree, const ofstream& out_file)
{
    if (out_file.is_open())
        avl_tree.inorder(out_file);
}


template <typename T>
bool search(AVLTree<T>& avl_tree, const T& data)
{
    return avl_tree.search(data);
}


template <typename T>
AVLTree<T>* successor(AVLTree<T>& avl_tree, const T& data)
{
    return avl_tree.successor(data);
}

template <typename T>
AVLTree<T>* predecessor(AVLTree<T>& avl_tree, const T& data)
{
    return avl_tree.predecessor(data);
}

template <typename T>
AVLTree<T>* select(AVLTree<T>& avl_tree, const T& data)
{
    return avl_tree.select(data);
}

template <typename T>
int rank(AVLTree<T>& avl_tree, const T& data)
{
    return avl_tree.rank(data);
}

bool getInput(const ifstream& fin)
{
    if (fin.is_open())
    {
        


    }
    else
        return false;
}



int main(int argc, char* argv[])
{
    ifstream in(argv[1], "r");
    ofstream out(argv[2], "w");
    
    CStopWatch stopWatch;
    
    int A[9] = {5, 12, 4, 6, 10, 45, 3, 12, 11};

    stopWatch.startTimer();
    merge_sort<int>(A, 9);
    stopWatch.stopTimer();
    cout << std::fixed << stopWatch.getElapsedTime() << endl;

    for (int i = 0; i < 9; ++i)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
