/*
 *  timer.cpp
 *  InvertedIndex
 *
 *  Created by Manish Patil on 12/5/09.
 *  
 *
 */

#include "timer.hpp"

#if defined(WIN32)
double CStopWatch::LIToSecs( LARGE_INTEGER & L) 
{
	return ((double)L.QuadPart /(double)frequency.QuadPart);
}

CStopWatch::CStopWatch()
{
	timer.start.QuadPart=0;
	timer.stop.QuadPart=0;
	QueryPerformanceFrequency( &frequency );
}

void CStopWatch::startTimer( ) 
{
	QueryPerformanceCounter(&timer.start);
}

void CStopWatch::stopTimer( ) 
{
	QueryPerformanceCounter(&timer.stop);
}

void CStopWatch::refreshTimer( ) 
{
	timer.start.QuadPart=0;
	timer.stop.QuadPart=0;
	QueryPerformanceFrequency( &frequency );
}

double CStopWatch::getElapsedTime() 
{
	LARGE_INTEGER time;
	time.QuadPart = timer.stop.QuadPart - timer.start.QuadPart;
	return LIToSecs( time) *1000000;
}
#endif
#if defined(unix)|| defined(__APPLE__)

CStopWatch::CStopWatch(){ }

void CStopWatch::startTimer( ) 
{
	gettimeofday(&start, &tz);
}

void CStopWatch::stopTimer( ) 
{
	gettimeofday(&end, &tz);
}

void CStopWatch::refreshTimer( ) {}

double CStopWatch::getElapsedTime() 
{
	return time_total=(end.tv_sec-start.tv_sec)*1000000+((double)(end.tv_usec-start.tv_usec));
}
#endif
