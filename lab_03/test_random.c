#include "rand_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize the seed for deterministic random number generation
    initializeRandomSeed(12345);

    // Generate an array of 10 random numbers
    int numElements = 10;
    float *randomNumbers = generateRandomNumbers(numElements);

    if (!randomNumbers) {
        fprintf(stderr, "Failed to allocate memory for random numbers.\n");
        return 1;
    }

    // Print the generated random numbers
    for (int i = 0; i < numElements; i++) {
        printf("%f\n", randomNumbers[i]);
    }

    // Free the allocated memory
    free(randomNumbers);

    return 0;
}
