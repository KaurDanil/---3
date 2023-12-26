#include <stdio.h>


int main(){
    int n; 
    scanf("%d", &n);
    int par = 2 + 2 * (n - 3);
    int positive = par / 2;
    int negative = par / 2;
    int cnt_pos = 0;
    int cnt_iter = 1;
    int cnt_neg = 0;
    int matrix[n][n];
    for (int i = 0; i != n; ++i){
        for (int j = 0; j != n; ++j){
            scanf("%d", &matrix[i][j]);
        }
    }
    putchar('\n');
    
    for (int i = 0; i < n; ++i){
        for (int j = n; j != -1; --j){
            if ((i + j) == (n - 1)){
                printf("%d ", matrix[i][j]);
            }
        }
    }

    while ((cnt_neg != negative) && (cnt_pos != positive)){
        if ((cnt_pos != positive) && (cnt_pos != positive - 1)){
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    if (((i + j) == (n - 1 - cnt_iter) && ((n - 1 - cnt_iter) != 0)) && (cnt_pos % 2 == 0)){
                        printf("%d ", matrix[j][i]);
                    }
                    else if (((i + j) == (n - 1 - cnt_iter) && ((n - 1 - cnt_iter) != 0)) && (cnt_pos % 2 != 0)){
                        printf("%d ", matrix[i][j]);
                    }
                }
                }
            ++cnt_pos;
        }
        if ((cnt_neg != negative) && (cnt_neg != negative - 1)){
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    if (((i + j) == (n - 1 + cnt_iter) && ((n - 1 + cnt_iter) != 0)) &&(cnt_neg % 2 == 0)){
                        printf("%d ", matrix[j][i]);
                    }
                    else if (((i + j) == (n - 1 + cnt_iter) && ((n - 1 + cnt_iter) != 0)) && (cnt_neg % 2 != 0)){
                        printf("%d ", matrix[i][j]);
                    }
                }
                }
            ++cnt_neg;
        }
        if ((cnt_pos == positive - 1) && (cnt_neg == negative - 1)){
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    if (((i + j) == (n + cnt_iter) && ((n  + cnt_iter) != 0)) && (cnt_pos % 2 == 0)){
                        printf("%d ", matrix[j][i]);
                    }
                    else if (((i + j) == (n + cnt_iter) && ((n + cnt_iter) != 0)) && (cnt_pos % 2 != 0)){
                        printf("%d ", matrix[i][j]);
                    }
                }
                }
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    if (((i + j) == (n - 1 - cnt_iter) && ((n - 2 - cnt_iter) != 0)) && (cnt_pos % 2 == 0)){
                        printf("%d ", matrix[j][i]);
                    }
                    else if (((i + j) == (n - 2 - cnt_iter) && ((n - 2 - cnt_iter) != 0)) && (cnt_pos % 2 != 0)){
                        printf("%d ", matrix[i][j]);
                    }
                }
                }
            ++cnt_neg;
            ++cnt_pos;
        }
        ++cnt_iter;
    }
    printf("%d ", matrix[0][0]);
    printf("%d", matrix[n - 1][n - 1]);
}