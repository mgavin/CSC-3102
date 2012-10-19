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

#include "k_ary_heap.hpp"
#include "sorts.hpp"
#include "timer.hpp"
#include "debug.hpp"

using namespace std;

void heap_ops()
{
    KAryHeap<int, 3> v;
    v.insert(3);
    v.insert(2);
    v.insert(1);
    int d = 0;
    try
    {
        while (d < 5)
        {
            cout << v.extract() << endl;
            ++d;
        }
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
}


int main(int argc, char* argv[])
{
    /*ifstream in("in_file", "r");
    ofstream out("out_file", "w");
    
    //KAryHeap<int, 3> int_heap_s3;*/

    heap_ops();
    
    CStopWatch stopWatch;
    timespec nanoSleep = {0, 30000};
    
    int A[9] = {5, 12, 4, 6, 10, 45, 3, 12, 11};

    stopWatch.startTimer();
    nanosleep(&nanoSleep, NULL);
    merge_sort<int>(A, 9);
    stopWatch.stopTimer();
    cout << std::fixed << stopWatch.getElapsedTime() << endl;

    for (int i = 0; i < 9; ++i)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
