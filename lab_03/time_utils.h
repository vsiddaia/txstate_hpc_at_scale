#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <sys/time.h> // For struct timeval

// Calculates the elapsed time in seconds with double precision
// Parameters:
// - start: The start time
// - end: The end time
// Returns: Elapsed time in seconds (including fractions for milliseconds)
double getElapsedTimeInSeconds(struct timeval start, struct timeval end);

#endif // TIME_UTILS_H
