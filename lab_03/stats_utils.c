#include "stats_utils.h"
#include <mpi.h>
#include <math.h>

float computeMean(float *array, int numElements) {
    float sum = 0.0;
    for (int i = 0; i < numElements; i++) {
        sum += array[i];
    }
    float globalSum;
    MPI_Allreduce(&sum, &globalSum, 1, MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD);
    int worldSize;
    MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
    return globalSum / (worldSize * numElements);
}

float computeStdDev(float *array, int numElements, float mean) {
    float sqSum = 0.0;
    for (int i = 0; i < numElements; i++) {
        sqSum += (array[i] - mean) * (array[i] - mean);
    }
    float globalSqSum;
    MPI_Allreduce(&sqSum, &globalSqSum, 1, MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD);
    int worldSize;
    MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
    return sqrt(globalSqSum / (worldSize * numElements));
}
