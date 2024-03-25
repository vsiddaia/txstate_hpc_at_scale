#ifndef COMM_UTILS_H
#define COMM_UTILS_H

#include <mpi.h>

// Gather hostnames from all processes and print them on process 0
void gatherAndPrintHostnames(int rank, int nproc);

#endif // COMM_UTILS_H
