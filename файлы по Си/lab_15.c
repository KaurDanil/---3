#include <stdio.h>



int max(int a, int b){
    return a > b ? a : b;
}



int main(){
    FILE *file_in;
    int matrix[8][8];
    int row, col;
    int max_el = 0;
    file_in = fopen("matrix.txt", "r");
    fscanf(file_in, "%d %d", &row, &col);
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            fscanf(file_in, "%d", &matrix[i][j]);
        }
    }
    fclose(file_in);
    int cnt = 0;
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            if ((i != j) && (cnt > j)){
                max_el = max(max_el, matrix[i][j]);
            }
        }
        ++cnt;
    }
    cnt = 0;
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            if ((i != j) && (cnt < j)){
                matrix[i][j] *= max_el;
            }
        }
        ++cnt;
    }

    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
                printf("%d ", matrix[i][j]);
            }
        printf("\n");
    }
}