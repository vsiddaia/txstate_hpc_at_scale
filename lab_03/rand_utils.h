#ifndef RAND_UTILS_H
#define RAND_UTILS_H

/**
 * Initializes the random number generator with a specified seed.
 * This function should be called before generateRandomNumbers to ensure
 * deterministic output.
 * 
 * @param seed The seed value for initializing the random number generator.
 */
void initializeRandomSeed(unsigned int seed);

/**
 * Generates an array of random floats. Each number has a value from 0 to 1.
 * The array must be freed by the caller to avoid memory leaks.
 * 
 * @param numElements The number of random elements to generate.
 * @return Pointer to the array of random floats, or NULL if memory allocation fails.
 */
float *generateRandomNumbers(int numElements);

#endif // RAND_UTILS_H
