#include "time_utils.h"

double getElapsedTimeInSeconds(struct timeval start, struct timeval end) {
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    // Convert the total elapsed time to double precision seconds
    double elapsed = seconds + microseconds / 1e6;
    return elapsed;
}
