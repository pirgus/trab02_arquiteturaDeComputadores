#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Número de elementos em cada bucket

// Função para encontrar o valor máximo em um array
float findMax(float array[], int n) {
    float max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Função para inserir um elemento no bucket
void insertionSort(float bucket[], int n) {
    for (int i = 1; i < n; i++) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Função para realizar o bucket sort
void bucketSort(float array[], int n) {
    // Encontrar o valor máximo no array
    float max = findMax(array, n);

    // Inicializar os buckets
    int bucketCount = MAX;
    float buckets[bucketCount][n];
    int bucketSizes[bucketCount];

    // Inicializar os tamanhos dos buckets
    for (int i = 0; i < bucketCount; i++) {
        bucketSizes[i] = 0;
    }

    // Distribuir os elementos nos buckets
    for (int i = 0; i < n; i++) {
        int index = (array[i] * bucketCount) / (max + 1);
        buckets[index][bucketSizes[index]] = array[i];
        bucketSizes[index]++;
    }

    // Ordenar cada bucket individualmente
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // Concatenar os buckets ordenados de volta no array original
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            array[index++] = buckets[i][j];
        }
    }
}

// Função para imprimir o array
void printArray(float array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

// Função para ler os dados de um arquivo
int readFile(const char *filename, float **array) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return -1;
    }

    int n = 0;
    while (fscanf(file, "%f", &(*array)[n]) == 1) {
        n++;
        *array = realloc(*array, sizeof(float) * (n + 1));
    }
    fclose(file);
    return n;
}

int main() {
    float *array = malloc(sizeof(float) * 1);
    const char *filename = "dados.txt";  // Substitua pelo nome do seu arquivo

    int n = readFile(filename, &array);
    if (n == -1) {
        return 1;
    }

    printf("Array original: \n");
    printArray(array, n);

    bucketSort(array, n);

    printf("Array ordenado: \n");
    printArray(array, n);

    free(array);
    return 0;
}

