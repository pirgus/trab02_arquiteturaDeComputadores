#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

void printHistogram(int *hist, int n);

int main(int argc, char *argv[])
{ /* histogram_seq.c   */
    long int i;
    long int inputValue;

    inputValue = atoi(argv[1]);
    int *hist = malloc(inputValue * sizeof(int));
    // int hist[inputValue];
    FILE *inputFile;

    inputFile = fopen(argv[2], "r");

    for (i = 0; i < inputValue; ++i)
    {
        fscanf(inputFile, "%d", &hist[i]);

        // printf("%d ", hist[i]);
    }

    
    // for(int k = 0; k < 10; k++){

        int results[255] = {0};
        double start_time_omp = omp_get_wtime();
        #pragma omp parallel for num_threads(8) reduction(+:results)
        for (i = 0; i < inputValue; i++){
            results[hist[i]]++;
        }
        double end_time_omp = omp_get_wtime();
        double cpu_time_used = ((double) (end_time_omp - start_time_omp));
        printf("Execution time: %g seconds\n", cpu_time_used);
    // }
    
    // printHistogram(results, 255);

    fclose(inputFile);
    free(hist);
    return 0;
}

void printHistogram(int *hist, int n)
{
    int i;
    for (i = 0; i < n; i++){
        printf("[%d] - [%d]\n", i, hist[i]);
    }
}
