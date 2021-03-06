/*****
 *   Matthew Gavin
 *   Joshua Springer
 *   CSC 3102, Fall 2012, Section 1
 *   Programming Homework #1
 *
 *   Description:
 *       Defines debugging statements.
 *   
 *****/ 

#ifndef DEBUGHPP
#define DEBUGHPP

#ifdef NODEBUG

#define dbg(a)
#define debug(a, end)

#elif !defined (DEBUG)

#define DEBUG
#include <iostream>
#define TAB "\t"
#define dbg(a) a
#define debug(a, end) std::cout << #a << ": " << a << end

#endif

#endif
