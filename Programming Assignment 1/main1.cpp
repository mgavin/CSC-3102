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

#include "k_ary_heap.hpp"
#include "timer.hpp"

using namespace std;

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

template <typename T, int size>
void process(KAryHeap<T, size>& heap)
{
    if (fin.is_open() && !fin.eof())
    {
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
                insert<int, size>(heap, value);
            }
            else if (command == "EX")
            {
                fout << "Extract: " << extract<int, size>(heap) << endl;
            }
            sst.clear();
        }
    }
}

int main(int argc, char* argv[])
{
    CStopWatch timer;
    
    //invoke the program like:
    //   ./main1 infile outfile
    if (argc != 3)
        return -1;
    
    fin.open(argv[1], ios::in);
    fout.open(argv[2], ios::out);
    
    KAryHeap<int, 2> int_heap_2;
    KAryHeap<int, 4> int_heap_4;
    KAryHeap<int, 6> int_heap_6;
    KAryHeap<int, 8> int_heap_8;
    KAryHeap<int, 10> int_heap_10;

    fout << "Heap Operations" << endl << endl;

    timer.startTimer();
    process<int, 2>(int_heap_2);
    timer.stopTimer();
    fout << "KAryHeap<int, 2>: " << timer.getElapsedTime() << endl;
    timer.refreshTimer();
    fin.seekg(0);

    timer.startTimer();
    process<int, 4>(int_heap_4);
    timer.stopTimer();
    fout << "KAryHeap<int, 4>: " << timer.getElapsedTime() << endl;
    timer.refreshTimer();
    fin.seekg(0);

    timer.startTimer();
    process<int, 6>(int_heap_6);
    timer.stopTimer();
    fout << "KAryHeap<int, 6>: " << timer.getElapsedTime() << endl;
    timer.refreshTimer();
    fin.seekg(0);

    timer.startTimer();
    process<int, 8>(int_heap_8);
    timer.stopTimer();
    fout << "KAryHeap<int, 8>: " << timer.getElapsedTime() << endl;
    timer.refreshTimer();
    fin.seekg(0);

    timer.startTimer();
    process<int, 10>(int_heap_10);
    timer.stopTimer();
    fout << "KAryHeap<int, 10>: " << timer.getElapsedTime() << endl;
    timer.refreshTimer();
    fin.seekg(0);

    
    fin.close();
    fout.close();
    
    return 0;
}
