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

AVLTree<int>* int_avl_tree = NULL;

static ofstream fout;
static ifstream fin;

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
        avl_tree.inorder(&avl_tree, fout);
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

void process()
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
                timer.startTimer();
                if (int_avl_tree == NULL)
                    int_avl_tree = new AVLTree<int>(value);
                else
                    insert<int>(*int_avl_tree, value);
                timer.stopTimer();
                fout << "Insert (" << value << ") : " << timer.getElapsedTime() << endl;
                timer.refreshTimer();
            }
            else if (command == "MI")
            {
                int m;
                timer.startTimer();
                m = min<int>(*int_avl_tree);
                timer.stopTimer();
                fout << "Min (" << m << ") : " << timer.getElapsedTime() << endl;
                timer.refreshTimer();
            }
            else if (command == "MA")
            {
                int m;
                timer.startTimer();
                m = max<int>(*int_avl_tree);
                timer.stopTimer();
                fout << "Max (" << m << ") : " << timer.getElapsedTime() << endl;
                timer.refreshTimer();
            }
            else if (command == "TR")
            {
                timer.startTimer();
                inorder_traversal<int>(*int_avl_tree);
                timer.stopTimer();
                fout << " <- Inorder Traversal : " << timer.getElapsedTime() << endl;
                timer.refreshTimer();
            }
            else if (command == "SR")
            {
                sst >> value;
                bool found = false;
                timer.startTimer();
                found = search<int>(*int_avl_tree, value);
                timer.stopTimer();
                fout << "Search (" << value << "), found? " << found << " : " << timer.getElapsedTime() << endl;
                timer.refreshTimer();
            }
            else if (command == "SC")
            {
                sst >> value;
                int m;
                timer.startTimer();
                m = successor<int>(*int_avl_tree, value)->get_data();
                timer.stopTimer();
                fout << "Successor (" << value << ") = " << m << " : " << timer.getElapsedTime() << endl;
                timer.refreshTimer();
            }
            else if (command == "PR")
            {
                sst >> value;
                int m;
                timer.startTimer();
                m = predecessor<int>(*int_avl_tree, value)->get_data();
                timer.stopTimer();
                fout << "Predecessor (" << value << ") = " << m << " : " << timer.getElapsedTime() << endl;
                timer.refreshTimer();
            }
            else if (command == "SE")
            {
                sst >> value;
                int m;
                timer.startTimer();
                m = select<int>(*int_avl_tree, value)->get_data();
                timer.stopTimer();
                fout << "Select (" << value << ") = " << m << " : " << timer.getElapsedTime() << endl;
                timer.refreshTimer();
                
            }
            else if (command == "RA")
            {
                sst >> value;
                int m;
                timer.startTimer();
                m = rank<int>(*int_avl_tree, value);
                timer.stopTimer();
                fout << "Rank (" << value << ") = " << m << " : " << timer.getElapsedTime() << endl;
                timer.refreshTimer();
            }
            sst.clear();
        }
    }
}

int main(int argc, char* argv[])
{
    //invoke the program like:
    //   ./main infile outfile
    if (argc != 3)
        return -1;

    fin.open(argv[1], ios::in);
    fout.open(argv[2], ios::out);

    process();
    delete int_avl_tree;
    return 0;
}
