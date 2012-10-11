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

#include "k_ary_heap.h"
#include "sorts.h"
#include "timer.h"
#include "debug.h"

using namespace std;

int main(int argc, char* argv[])
{
    /*ifstream in("in_file", "r");
    ofstream out("out_file", "w");
    
    //KAryHeap<int, 3> int_heap_s3;*/

    CStopWatch stopWatch;
    timespec nanoSleep = {0, 30000};
    
    int A[10] = {5, 12, 4, 6, 10, 45, 3, 12, 11, 7};

    stopWatch.startTimer();
    nanosleep(&nanoSleep, NULL);
    merge_sort<int>(A, 10);
    stopWatch.stopTimer();
    cout << std::fixed << stopWatch.getElapsedTime() << endl;

    for (int i = 0; i < 10; ++i)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
