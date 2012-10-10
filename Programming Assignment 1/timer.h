/*
 *  timer.h
 *  InvertedIndex
 *
 *  Created by Manish Patil on 12/5/09.
 *  Copyright 2009 Louisiana State University. All rights reserved.
 *
 */

#if defined(WIN32)
#include <windows.h>
#endif
#if defined(unix)|| defined(__APPLE__)
#include <sys/time.h>
#include <unistd.h>
#endif

#if defined(WIN32)
typedef struct 
{
    LARGE_INTEGER start;
    LARGE_INTEGER stop;
} stopWatch;
#endif

class CStopWatch 
{	
private:
#if defined(WIN32)
	stopWatch timer;
	LARGE_INTEGER frequency;
	double LIToSecs( LARGE_INTEGER & L);
#endif
#if defined(unix)|| defined(__APPLE__)
	struct timeval start,end;
	struct timezone tz;
	double time_total;
#endif
public:
	CStopWatch();
	void startTimer( );
	void stopTimer( );
	double getElapsedTime();
	void refreshTimer( );
};
