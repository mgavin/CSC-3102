/*****
 *   Matthew Gavin
 *   Joshua Springer
 *   CSC 3102, Fall 2012, Section 1
 *   Programming Homework #1
 *
 *   Description:
 *       Templatized functions are defined in the header file.
 *   
 *****/ 
#ifndef SORTS
#define SORTS

#define NODEBUG

#include <iostream>
#include "k_ary_heap.hpp"
#include "debug.hpp"

template <typename T>
void merge_sort(T* A, int size)
{
    //Modifies A to be the final sorted array.
    if (size == 1) return;

    T B[size/2], C[(size+1)/2];
    for (int i = 0; i < size/2; ++i)
        B[i] = A[i];

    for (int i = 0; i < (size+1)/2; ++i)
        C[i] = A[i+size/2];

    dbg(
        for (int i = 0; i < size/2; ++i)
            debug(B[i], TAB);

        for (int i = 0; i < (size+1)/2; ++i)
            debug(C[i], TAB);
        std::cout << std::endl;
        )
    
    merge_sort(B, size/2);
    merge_sort(C, (size+1)/2);

    int bindex = 0, cindex = 0, index = 0;
    while (index != size)
    {
        if (bindex >= size/2)
            A[index++] = C[cindex++];
        else if (cindex >= (size+1)/2)
            A[index++] = B[bindex++];
        else
        {
            if (B[bindex] < C[cindex])
                A[index++] = B[bindex++];
            else
                A[index++] = C[cindex++];
        }
        debug(A[index-1], std::endl);
    }
}

template <typename T, int sz>
void heap_sort(T* A, int size)
{
    //Modifies the array A to be the final sorted array
    KAryHeap<T, sz> heap;
    for (int i = 0; i < size; ++i)
        heap.insert(A[i]);         //heapify

    for (int i = 0; i < size; ++i)
        A[i] = heap.extract_min(); //extract until empty
}

#endif
