#ifndef STATS_UTILS_H
#define STATS_UTILS_H

// Computes the mean (average) of an array of floats.
float computeMean(float *array, int numElements);

// Computes the standard deviation of an array of floats.
float computeStdDev(float *array, int numElements, float mean);

#endif // STATS_UTILS_H
