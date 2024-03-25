#include <mpi.h>
#include <stdio.h>
#include <stddef.h>
#include "comm_utils.h"
#include "time_utils.h"

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, nproc;
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    gatherAndPrintHostnames(rank, nproc);

    MPI_Finalize();
    gettimeofday(&end_time, NULL);

    if(rank==0) {
        double time_secs = getElapsedTimeInSeconds(start_time, end_time);
	printf("---------------------------------------\n");
        printf("Time taken to complete = %2.8lf secs\n", time_secs);
	printf("---------------------------------------\n");
    }

    return 0;
}
