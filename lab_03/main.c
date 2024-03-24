#include "rand_utils.h"
#include "stats_utils.h"
#include "time_utils.h"
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "json_serializer.h"

int main(int argc, char **argv) {
        MPI_Init(&argc, &argv);
        if (argc != 5) {
                fprintf(stderr, "Usage: mpi_run -np <num_procs> ./mpi_app_gcc <seed_value> <num_elements_per_proc> <mpi_proc> <json_file>\n");
                MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
                }
        int rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);		
        //srand(time(NULL) + rank); // Seed the random generator uniquely for each process
        unsigned int seed = (int)strtol(argv[1], NULL, 0); 
        initializeRandomSeed(seed);

        long numElementsPerProc = (int)strtol(argv[2], NULL, 0); 
	struct timeval start_time, end_time;
	
	gettimeofday(&start_time, NULL);
        float *randNums = generateRandomNumbers(numElementsPerProc);
	gettimeofday(&end_time, NULL);
	
	double rand_gen_time_secs = getElapsedTimeInSeconds(start_time, end_time); 
	

	getElapsedTimeInSeconds(start_time, end_time);
        float mean = computeMean(randNums, numElementsPerProc);
        gettimeofday(&end_time, NULL);
            
        double mean_time_secs = getElapsedTimeInSeconds(start_time, end_time); 


	getElapsedTimeInSeconds(start_time, end_time);
        float stdDev = computeStdDev(randNums, numElementsPerProc, mean);
        gettimeofday(&end_time, NULL);
            
        double stddev_time_secs = getElapsedTimeInSeconds(start_time, end_time); 



        if (rank == 0) {
                printf(" Seed: 0x%08x, ", seed);
                printf(" NumbElePerProc: 0x%08x, ", numElementsPerProc);
                printf(" Mean: %02.6f, ", mean);
                printf(" Std Dev: %02.6ff, ", stdDev);

                char sead[20];
                char nele[20];
		char proc[20];
                char mean[20];
                char mets[20];
                char stdd[20];
                char sdts[20];

                sprintf(sead, "0x%x", seed);
                sprintf(proc, "0x%x", argv[3]);
                sprintf(nele, "0x%x", numElementsPerProc);
                sprintf(mean, "%1.8f", mean);
                sprintf(mets, "%1.8f", mean_time_secs);
                sprintf(stdd, "%1.8f", stdDev);
                sprintf(sdts, "%1.8f", stddev_time_secs);


    		    KeyValuePair pairs[] = {
    		    	{"seed", sead},
    		    	{"num_elements_per_proc", nele},
    		    	{"mean", mean},
			{"mean_time_secs", mets},
    		    	{"std_dev", stdd},
    		    	{"stddev_time_secs", sdts}
    		    };
    		    size_t count = sizeof(pairs) / sizeof(pairs[0]);
				// Serialize to JSON
				char *jsonContent = serializeToJson(pairs, count);
				if (!jsonContent) {
				    fprintf(stderr, "Failed to serialize key-value pairs to JSON.\n");
				    return EXIT_FAILURE;
				}   
		
				// Write JSON to a file
				const char *filename = argv[4];
				if (writeToFile(filename, jsonContent) != 0) {
				    fprintf(stderr, "Failed to write JSON to file.\n");
				    free(jsonContent); // Free the allocated JSON string
				    return EXIT_FAILURE;
				}   
		
				printf("JSON saved to %s\n", filename);
				free(jsonContent); // Free the allocated JSON string
    		    }


	    free(randNums);
	    MPI_Finalize();
        return 0;
}
