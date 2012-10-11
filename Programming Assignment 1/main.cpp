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
#include "k_ary_heap.h"

using namespace std;

int main(int argc, char* argv[])
{
    ifstream in("in_file", "r");
    ofstream out("out_file", "w");
    
    KAryHeap<int, 3> int_heap_s3;

    return 0;
}
