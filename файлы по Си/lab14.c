#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define size 3
#define int_input(a) scanf("%d", &a)
#define int_print(a) printf("%d ", a);
#define in_range(n, m, i) = n; i < m; i++

void inputMatrix(int matrix[]) {
    for (int i in_range(0, size, i)) {
        for (int j in_range(0, size, j)) {
            int a;
            int_input(a);
            matrix[i * size + j] = a;
        }
    }
}

void printMatrix(int matrix[]) {
    for (int i in_range(0, size, i)) {
        for (int j in_range(0, size, j)) {
            printf("%2d ", matrix[i * size + j]);
        }
        printf("\n");
    }
}

void printInOrderRequired(int matrix[]) {
    int i = size - 1, j = size - 1, di = 1, dj = -1;

    // диагонали под побочной + побочная
    int_print(matrix[j * size + i]);
    while (1) {
        i += di;
        j += dj;

        if (j >= size) {
            j -= 1;
            di *= -1;
            dj *= -1;
        }

        if (i >= size) {
            i -= 1;
            di *= -1;
            dj *= -1;
        }

        if (i < 0 || j < 0) break;
        int_print(matrix[j * size + i]);
    }

    if (j < 0) {
        i -= 1;
        j += 1;
    } else {
        i += 1;
        j -= 1;
    }

    if (i < 0 || j < 0) return;

    // диагонали над побочной
    int_print(matrix[j * size + i]);

    while (1) {
        i += di;
        j += dj;

        if (j < 0) {
            i -= 2;
            j += 1;
            di *= -1;
            dj *= -1;
        } 

        if (i < 0) {
            i += 1;
            j -= 2;
            di *= -1;
            dj *= -1;
        }

        if (i < 0 || j < 0) break;
        int_print(matrix[j * size + i]);
    }
}

int main() {
    int matrix[size][size];

    printf("Input matrix elements: \n");
    inputMatrix((int *)matrix);

    printf("\nMatrix entered: \n");
    printMatrix((int *)matrix);

    printf("\nOutput: \n");
    printInOrderRequired((int *)matrix);

    return 0;
}