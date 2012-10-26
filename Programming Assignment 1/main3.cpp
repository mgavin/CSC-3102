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
#include <vector>
#include <functional>
#include <sstream>
#include <ctime>

#include "sorts.hpp"
#include "timer.hpp"
#include "debug.hpp"

using namespace std;

KAryHeap<int, 3> int_heap_s3;

int ms_a[128000];

static ofstream fout;
static ifstream fin;

void populate(int* a, int upper_bound)
{
    srand(time(NULL));
    int r;
    vector<int> v;

    for (int i = 1; i <= upper_bound; ++i)
    {
        v.push_back(i);
    }
    
    for (int i = 1; i <= upper_bound; ++i)
    {
        r = (rand() % (upper_bound-i+1));        
        a[i-1] = v[r];
        int_heap_s3.insert(v[r]);
        v.erase(v.begin()+r);
    }
}

void conduct_experiments()
{
    //do merge sort and heap sort operations
    CStopWatch timer;

    populate(ms_a, 1000);
    timer.startTimer();
    merge_sort<int>(ms_a, 1000);
    timer.stopTimer();
    fout << "1000 elements" << endl << "merge sort: ";
    fout << timer.getElapsedTime() << endl;
    timer.refreshTimer();
    timer.startTimer();
    for (int i = 0; i < 1000; ++i)
        int_heap_s3.extract();
    timer.stopTimer();
    fout << "heap sort: " << timer.getElapsedTime() << endl << endl;
    timer.refreshTimer();
    
    populate(ms_a, 2000);
    timer.startTimer();
    merge_sort<int>(ms_a, 2000);
    timer.stopTimer();
    fout << "2000 elements" << endl << "merge sort: ";
    fout << timer.getElapsedTime() << endl;
    timer.refreshTimer();
    timer.startTimer();
    for (int i = 0; i < 2000; ++i)
        int_heap_s3.extract();
    timer.stopTimer();
    fout << "heap sort: " << timer.getElapsedTime() << endl << endl;
    timer.refreshTimer();
    
    populate(ms_a, 4000);
    timer.startTimer();
    merge_sort<int>(ms_a, 4000);
    timer.stopTimer();
    fout << "4000 elements" << endl << "merge sort: ";
    fout << timer.getElapsedTime() << endl;
    timer.refreshTimer();
    timer.startTimer();
    for (int i = 0; i < 4000; ++i)
        int_heap_s3.extract();
    timer.stopTimer();
    fout << "heap sort: " << timer.getElapsedTime() << endl << endl;
    timer.refreshTimer();

    populate(ms_a, 8000);
    timer.startTimer();
    merge_sort<int>(ms_a, 8000);
    timer.stopTimer();
    fout << "8000 elements" << endl << "merge sort: ";
    fout << timer.getElapsedTime() << endl;
    timer.refreshTimer();
    timer.startTimer();
    for (int i = 0; i < 8000; ++i)
        int_heap_s3.extract();
    timer.stopTimer();
    fout << "heap sort: " << timer.getElapsedTime() << endl << endl;
    timer.refreshTimer();

    populate(ms_a, 16000);
    timer.startTimer();
    merge_sort<int>(ms_a, 16000);
    timer.stopTimer();
    fout << "16000 elements" << endl << "merge sort: ";
    fout << timer.getElapsedTime() << endl;
    timer.refreshTimer();
    timer.startTimer();
    for (int i = 0; i < 16000; ++i)
        int_heap_s3.extract();
    timer.stopTimer();
    fout << "heap sort: " << timer.getElapsedTime() << endl << endl;
    timer.refreshTimer();
    
    populate(ms_a, 32000);
    timer.startTimer();
    merge_sort<int>(ms_a, 32000);
    timer.stopTimer();
    fout << "32000 elements" << endl << "merge sort: ";
    fout << timer.getElapsedTime() << endl;
    timer.refreshTimer();
    timer.startTimer();
    for (int i = 0; i < 32000; ++i)
        int_heap_s3.extract();
    timer.stopTimer();
    fout << "heap sort: " << timer.getElapsedTime() << endl << endl;
    timer.refreshTimer();

    
    populate(ms_a, 64000);
    timer.startTimer();
    merge_sort<int>(ms_a, 64000);
    timer.stopTimer();
    fout << "64000 elements" << endl << "merge sort: ";
    fout << timer.getElapsedTime() << endl;
    timer.refreshTimer();
    timer.startTimer();
    for (int i = 0; i < 64000; ++i)
        int_heap_s3.extract();
    timer.stopTimer();
    fout << "heap sort: " << timer.getElapsedTime() << endl << endl;
    timer.refreshTimer();

    
    populate(ms_a, 128000);
    timer.startTimer();
    merge_sort<int>(ms_a, 128000);
    timer.stopTimer();
    fout << "128000 elements" << endl << "merge sort: ";
    fout << timer.getElapsedTime() << endl;
    timer.refreshTimer();
    timer.startTimer();
    for (int i = 0; i < 128000; ++i)
        int_heap_s3.extract();
    timer.stopTimer();
    fout << "heap sort: " << timer.getElapsedTime() << endl << endl;
    timer.refreshTimer();
}

int main(int argc, char* argv[])
{
    //invoke the program like:
    //   ./main2 outfile
    if (argc != 2)
        return -1;

    fout.open(argv[1], ios::out);
    fout << "Merge Sort vs Heap Sort" << endl << endl;
    
    //merge sort + heap sort operations
    conduct_experiments();
    fout.close();
    
    return 0;
}
