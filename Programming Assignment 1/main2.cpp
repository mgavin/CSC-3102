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
#include <iomanip>
#include <functional>
#include <sstream>

#include "avl_tree.hpp"
#include "timer.hpp"
#include "debug.hpp"

using namespace std;

AVLTree<int> int_avl_tree(0);

static ofstream fout;
static ifstream fin;

template <typename T, int size>
void insert(KAryHeap<T, size>& heap, const T& data)
{
    heap.insert(data);
}

template <typename T, int size>
T extract(KAryHeap<T, size>& heap)
{
    return heap.extract();
}

template <typename T>
void insert(AVLTree<T>& avl_tree, const T& data)
{
    avl_tree.insert(data);
}

template <typename T>
AVLTree<T>* min(AVLTree<T>& avl_tree)
{
    return avl_tree.min();
}

template <typename T>
AVLTree<T>* max(AVLTree<T>& avl_tree)
{
    return avl_tree.max();
}


template <typename T>
void inorder_traversal(AVLTree<T>& avl_tree)
{
    if (fout.is_open())
        avl_tree.inorder(fout);
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
    return avl_tree.select(&avl_tree, data);
}

template <typename T>
int rank(AVLTree<T>& avl_tree, const T& data)
{
    return avl_tree.rank(&avl_tree, data);
}

void conduct_experiments()
{
    //do merge sort and heap sort operations
    CStopWatch timer;

}

bool getInput(bool using_avl)
{
    if (fin.is_open() && !fin.eof())
    {
        CStopWatch timer;
        string line, command;
        int value;
        istringstream sst;
        while (!fin.eof())
        {
            getline(fin, line);
            sst.str(line);
            sst >> command;

            if (command == "IN")
            {
                sst >> value;
                if (using_avl)
                    insert<int>(int_avl_tree, value);
                else
                    insert<int>(int_heap_s3, value);
            }
            else if (command == "EX")
            {
                fout << extract<int>(int_heap_s3) << endl;
            }
            else if (command == "MI")
            {
                fout << min<int>(int_avl_tree) << endl;
            }
            else if (command == "MA")
            {
                fout << max<int>(int_avl_tree) << endl;
            }
            else if (command == "TR")
            {
                inorder_traversal<int>(int_avl_tree);
            }
            else if (command == "SR")
            {
                sst >> value;
                fout << search<int>(int_avl_tree, value) << endl;
            }
            else if (command == "SC")
            {
                sst >> value;
                fout << successor<int>(int_avl_tree, value)->get_data() << endl;
            }
            else if (command == "PR")
            {
                sst >> value;
                fout << predecessor<int>(int_avl_tree, value)->get_data() << endl;
            }
            else if (command == "SE")
            {
                sst >> value;
                fout << select<int>(int_avl_tree, value)->get_data() << endl;
            }
            else if (command == "RA")
            {
                sst >> value;
                fout << rank<int>(int_avl_tree, value) << endl;
            }
            sst.clear();
        }
        return true;
    }
    else
        return false;
}

int main(int argc, char* argv[])
{
    //invoke the program like:
    //   ./main infile outfile heap|avltree
    if (argc != 4)
        return -1;

    string ops_name(argv[3]);
    
    fin.open(argv[1], ios::in);
    fout.open(argv[2], ios::out);

    if (ops_name == "heap")
        while (getInput(0)); //heap
    else if (ops_name == "avltree")
        while (getInput(1)); //avl tree   

    //merge sort + heap sort operations
    conduct_experiments();
    
    return 0;
}
