/*****
 *   Matthew Gavin
 *   Joshua Springer
 *   CSC 3102, Fall 2012, Section 1
 *   Programming Homework #1
 *
 *   Description:
 *       Header file to define the class for the data structures that will be used.
 *       We define the KAryHeap class as well. Good ol' templates.
 *   
 *****/
#ifndef KARYHEAP
#define KARYHEAP

#include <exception>
#include <functional>
#include <algorithm>
#include <cstring>
#include <vector>
#include <limits>
#include "debug.hpp"

using std::swap;
using std::copy;
using std::vector;
using std::numeric_limits;

template <typename T, int size = 2, typename compare = std::less<T> >
class KAryHeap
{
private:
    void heapify(int idx);
    void heap_inc_key(int idx, T key);

    vector<T> data;
    
    //exceptions
    class EUnderflow : public std::exception
    {
        const char* what() const throw() {
            return "Heap Underflow";
        }
    };
    
public:
    KAryHeap();
    KAryHeap(const vector<T>& A);
    ~KAryHeap() {}
    
    void insert(const T& x);
    T extract() throw(EUnderflow);
    void print();
protected:

};


template <typename T, int size, typename compare>
KAryHeap<T, size, compare>::KAryHeap()
{
    
}

template <typename T, int size, typename compare>
KAryHeap<T, size, compare>::KAryHeap(const vector<T>& A)
{
    data.resize(A.size());
    copy(A.begin(), A.end(), data.begin());
    for (int i = A.size()/size; i >= 0; --i)
        heapify(i);
}

template <typename T, int size, typename compare>
void KAryHeap<T, size, compare>::heapify(int idx)
{
    int child_idx = idx*size;
    int comp_idx = idx;
    for (int i = 1; i <= size && child_idx+i < data.size(); ++i)
    {
        if (compare()(data[child_idx+i], data[comp_idx]))
        {
            comp_idx = child_idx+i;
        }
        debug(data[child_idx+i], TAB); debug(data[comp_idx], std::endl);
        debug(comp_idx, TAB); debug(idx, std::endl);
    }
    if (comp_idx != idx)
    {
        swap(data[comp_idx], data[idx]);
        heapify(comp_idx);
    }
}
   
template <typename T, int size, typename compare>
T KAryHeap<T, size, compare>::extract() throw(EUnderflow)
{
    if (data.size() < 1)
        throw EUnderflow();
    T top = *data.begin();
    *data.begin() = *data.rbegin();
    data.pop_back();
    heapify(0);
    return top;
}

template <typename T, int size, typename compare>
void KAryHeap<T, size, compare>::heap_inc_key(int idx, T key)
{
    if (compare()(key, data[idx]))
    {
        dbg(std::cout << "in heap_inc_key\t");
        int parent = idx / size; //floored by integer division
        data[idx] = key;
        debug(idx, TAB); debug(key, TAB); debug(data[idx], std::endl);
        while (idx != parent && idx >= 0 &&
               compare()(data[idx],data[parent])) //1 index parent problem
        {
            swap(data[idx], data[parent]);
            debug(data[idx], TAB); debug(data[parent], TAB);
            idx = parent;
            parent /= size;
            debug(idx, TAB); debug(data[parent], std::endl);
        }
    }
}

template <typename T, int size, typename compare>
void KAryHeap<T, size, compare>::insert(const T& x)
{
    T t;
    if (compare()(numeric_limits<T>::max(), numeric_limits<T>::min()))
        t = numeric_limits<T>::min();
    else
        t = numeric_limits<T>::max();
    
    //memset((void*)&t, 0, sizeof(T));
    debug(t, std::endl);
    data.push_back(t);
    heap_inc_key(data.size()-1, x);
}

template <typename T, int size, typename compare>
void KAryHeap<T, size, compare>::print()
{
    for (typename vector<T>::iterator it = data.begin(); it != data.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

#endif
