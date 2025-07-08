#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printHistogram(int *hist, int n);

int main(int argc, char *argv[])
{ /* histogram_seq.c   */
   long int i, j;
   long int inputValue;

   inputValue = atoi(argv[1]);
   //    printf("Input the amount of values: \n");
   //    scanf("%d", &inputValue);
   // int hist[inputValue];
   int *hist = malloc(inputValue * sizeof(int));
   FILE *inputFile;
   inputFile = fopen(argv[2], "r");

   //    printf("Input the values between 0 and 255 (separated by space): \n");
   for (i = 0; i < inputValue; i++)
   {
      fscanf(inputFile, "%d", &hist[i]);
      //    scanf("%d", &hist[i]);
      // printf("%d ", hist[i]);
   }


   for(int k = 0; k < 10; k++){
      int results[255] = {0};
   
      clock_t start_time = clock();
      // Processing data to compute histogram, see 5.17
      for (int i = 0; i < inputValue; ++i)
      {
         results[hist[i]]++;
      }
      clock_t end_time = clock();
      double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
      printf("Execution time: %g seconds\n", cpu_time_used);
   }

   // printHistogram(results, 255);
   fclose(inputFile);
   free(hist);
   return 0;
}

void printHistogram(int *hist, int n)
{
   int i, j;
   for (i = 0; i < n; i++)
   {
      printf("[%d] - [%d]\n", i, hist[i]);
   }
}
