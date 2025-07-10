#include <stdio.h>
#include <stdlib.h>


#define RANGE 400000

int main(int argc, char* argv[])
{
    unsigned long int i, N;
    N = atoi(argv[1]);
    FILE *outputFile;
    outputFile = fopen(argv[2], "w+");

    for(i=0;i<N;i++){
        fprintf(outputFile, "%d\n", rand()%RANGE);
    }

    fclose(outputFile);

    return 0;
}