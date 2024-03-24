#include "rand_utils.h"
#include <stdlib.h>
#include <assert.h>

void initializeRandomSeed(unsigned int seed) {
    srand(seed);
}

float *generateRandomNumbers(int numElements) {
    // Allocate memory for the array of random numbers
    float *randNums = (float *)malloc(sizeof(float) * numElements);
    
    // Check if memory allocation was successful
    if (!randNums) {
        // Memory allocation failed, return NULL
        return NULL;
    }

    // Generate random numbers between 0 and 1
    for (int i = 0; i < numElements; i++) {
        randNums[i] = rand() / (float)RAND_MAX;
    }
    
    return randNums;
}
