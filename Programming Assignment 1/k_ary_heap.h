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



template <typename T, int size>
class KAryHeap
{
    //min heap properties
 public:
    KAryHeap();
    KAryHeap(KAryHeap<T, size>* parent);
    ~KAryHeap();

    void insert(const T& x);
    T extract_min();
    
 private:
    void reconfig(KAryHeap<T, size>* node);
    
    KAryHeap<T, size>* parent;
    KAryHeap<T, size>* children[size];
    
    T* data;
};

#endif
