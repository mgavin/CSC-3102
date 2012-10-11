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
#ifndef K_ARY_HEAP
#define K_ARY_HEAP

template <typename T, int size>
class k_ary_heap
{
    //min heap properties
 public:
    k_ary_heap();
    k_ary_heap(k_ary_heap<T, size>* parent);
    ~k_ary_heap();

    void insert(const T& x);
    T extract_min();
    
 private:
    void reconfig(k_ary_heap<T, size>* node);
    
    k_ary_heap<T, size>* parent;
    T* children[size];
    
    T* data;
};

#endif
