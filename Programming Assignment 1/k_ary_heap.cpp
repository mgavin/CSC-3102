/*****
 *   Matthew Gavin
 *   Joshua Springer
 *   CSC 3102, Fall 2012, Section 1
 *   Programming Homework #1
 *
 *   Description:
 *       Defines the KAryHeap class.
 *   
 *****/ 
#include <algorithm>
#include "k_ary_heap.hpp"

template <typename T, int size, typename compare>
KAryHeap<T, size, compare>::KAryHeap()
{
    for (int i = 0; i < size; ++i)
    {
        children[i] = NULL;
    }
}

template <typename T, int size, typename compare>
KAryHeap<T, size, compare>::KAryHeap(KAryHeap<T, size, compare>* parent) : parent(parent)
{
    for (int i = 0; i < size; ++i)
    {
        children[i] = NULL;
    }
}

template <typename T, int size, typename compare>
KAryHeap<T, size, compare>::~KAryHeap()
{
    delete data;
    delete [] children;

    data = NULL;
    for (int i = 0; i < size; ++i)
        children[i] = NULL;
}

template <typename T, int size, typename compare>
void KAryHeap<T, size, compare>::insert(const T& x)
{
    /*
    if (data == NULL)
    {
        //no data yet, so take it.
        data = new T;
        *data = x;
    }
    else
    {
        
        if (children[i] == NULL)
        {
            children[i] = new KAryHeap<T, size>(this);
            children[i]->insert(x);
        }
        else
            children[i]->insert(x);
            

    }
    reconfig<T, size>(node);*/

}

template <typename T, int size, typename compare>
T KAryHeap<T, size, compare>::extract_min()
{
    //take from the top
    T return_val = *data;
    delete data;
    data = NULL;
    //reconfig<T, size>(this);

    return return_val;
}
/*
template <typename T, int size = 2, typename compare = std::less<T> >
void KAryHeap<T, size>::reconfig(KAryHeap<T, size>* node)
{
    for (int i = 0; i < size; ++i)
    {
        if (children[i]->data != NULL && children[i]->data < *data)
        {
            std::swap(this->data, children[i]->data);
            reconfig<T, size>(children[i]);
        }
        else if (children[i]->data == NULL)
            delete children[i];
    }
}
*/
