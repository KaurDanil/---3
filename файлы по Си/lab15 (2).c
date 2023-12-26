#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define matrixMaxSize 8

int processMatrix(int matrix[], int size) {
    for (int i = 0; i < size; i++) {
        int sum = 0;

        int col = i * 2;
        int row = 0;

        if (col >= size) {
            row = col - size + 1;
            col = size - 1;
        }

        while (1) {
            sum += matrix[row * matrixMaxSize + col];
            col--;
            row++;

            if (col < 0 || row >= size) break;
        }

        matrix[i * matrixMaxSize + i] = sum;
    }
}

void printMatrix(int matrix[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", matrix[j * matrixMaxSize + i]);
        }
        printf("\n");
    }
}

void inputMatrix(int matrix[], int *size) {
    printf("Input file name: \n");

    char filename[64];
    scanf("%s", filename); 

    FILE *inputFile;
    inputFile = fopen(filename, "r");

    int elems[matrixMaxSize * matrixMaxSize];
    int enteredCount = 0;

    while (1) {
        int entered;
        int scanRes = fscanf(inputFile, "%d ", &entered);
        elems[enteredCount++] = entered;
        if (scanRes == EOF) break;
    }

    *size = sqrt(enteredCount);

    for (int i = 0; i < *size; i++) {
        for (int j = 0; j < *size; j++) {
            matrix[j * matrixMaxSize + i] = elems[j * (*size) + i];
        }
    }
}

int main() {
    int matrix[matrixMaxSize][matrixMaxSize];
    int size;

    inputMatrix((int *)matrix, &size);

    printf("\nMatrix entered: \n");
    printMatrix((int *)matrix, size);

    processMatrix((int *)matrix, size);

    printf("\nProcessed matrix: \n");
    printMatrix((int *)matrix, size);

    return 0;
}