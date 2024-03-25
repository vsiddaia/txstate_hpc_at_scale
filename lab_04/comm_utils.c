#include "comm_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gatherAndPrintHostnames(int rank, int nproc) {
    char hostname[MPI_MAX_PROCESSOR_NAME];
    int namelen;
    MPI_Get_processor_name(hostname, &namelen);
    hostname[namelen] = '\0'; // Ensure null termination

    if (rank == 0) {
        MPI_Request recv_req[nproc - 1];
        char hostnames[nproc - 1][MPI_MAX_PROCESSOR_NAME];

        for (int i = 1; i < nproc; i++) {
            MPI_Irecv(hostnames[i - 1], MPI_MAX_PROCESSOR_NAME, MPI_CHAR, i, 0, MPI_COMM_WORLD, &recv_req[i - 1]);
        }

        // Placeholder for process 0's additional computation/work

        for (int i = 1; i < nproc; i++) {
            int index;
            MPI_Status status;
            MPI_Waitany(nproc - 1, recv_req, &index, &status);
            printf("Received a message from process %d on %s\n", status.MPI_SOURCE, hostnames[index]);
        }
    } else {
        MPI_Send(hostname, namelen + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }
}
