#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int STEPS_LIMIT = 50;
const int RECT_CENTER_X = 10;
const int RECT_CENTER_Y = -10;
const int RECT_SIZE = 10; 
const int RECT_HALF_SIZE = RECT_SIZE / 2;

int myMax(int a, int b) {
    return a > b ? a : b;
}

int myMin(int a, int b) {
    return a < b ? a : b;
}

int mySign(int a) {
    if (a == 0) return 0;
    return a > 0 ? 1 : -1;
}

int myAbs(int a) {
    return a > 0 ? a : -a;
}

int myMod(int x, int divider) {
    return x - ((int)(x / divider) * divider);
}

bool isCollide(int x, int y) {
    return (x >= RECT_CENTER_X - RECT_HALF_SIZE) &&
    (x <= RECT_CENTER_X + RECT_HALF_SIZE) &&
    (y >= RECT_CENTER_Y - RECT_HALF_SIZE) &&
    (y <= RECT_CENTER_Y + RECT_HALF_SIZE);
} 

int updateI(int i, int j, int l, int step) {
    return myAbs(step - 15) - myMin(i / 3, myMod(j + l, 10)) - 20;
}

int updateJ(int i, int j, int l, int step) {
    return (-(j + step)) / 5 + myAbs(myMod((i * l), 8));
}

int updateL(int i, int j, int l, int step) {
    return myMax(myMod(i + j, 15), myMod((i + step), 14));
}

int main() {
    int i = 11, j = 13, l = 10, step = 0;
    
    for (; step < STEPS_LIMIT; step++) {
        if (isCollide(i, j)) {
            printf("%d", step);
            return 0;
        } 
        
        int iNew = updateI(i, j, l, step);
        int jNew = updateJ(i, j, l, step);
        int lNew = updateL(i, j, l, step);
        
        i = iNew;
        j = jNew;
        l = lNew;
    }
    
    printf("You've missed\nThat's why %d, %d, %d, %d", step, i, j, l);
    
    return 0;
}
