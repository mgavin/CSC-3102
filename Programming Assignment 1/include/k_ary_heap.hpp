/*****
 *   Matthew Gavin
 *   Joshua Springer
 *   CSC 3102, Fall 2012, Section 1
 *   Programming Homework #1
 *
 *   Description:
 *       Header file to define the class for the data structures that will be used.
 *   
 *****/
#ifndef KARYHEAP
#define KARYHEAP

#include <functional>

template <typename T, int size = 2, typename compare = std::less<T> >
class KAryHeap
{
    //min heap properties
public:
    KAryHeap();
    ~KAryHeap();
    
    void insert(const T& x);
    T extract_min();
    
protected:
    KAryHeap(KAryHeap<T, size, compare>* parent);
    
private:
    void reconfig(KAryHeap<T, size, compare>* node);
    
    KAryHeap<T, size>* parent;
    KAryHeap<T, size>* children[size];
    
    T* data;
};

#endif
