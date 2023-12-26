#include <stdio.h>
#include <math.h>

const double a = 0.0;
const double b = 0.5;
const double k = 1.0;
const int n = 100;
const int fieldSize = 18;
const int columnsCount = 4;

double getEps() {
    double eps = 1.0;
    while (1.0 + eps > 1.0) eps /= 2.0;
    return eps * 2.0;
}

double myPow(double base, int exponent) {
    double res = 1.0;
    for (int i = 0; i < exponent; i++) res *= base;
    return res;
}

double calcF(double x) {
    return x * (3.0 - x) / myPow(1.0 - x, 3);
}

double calcFTaylor(double x, double eps, int *iterationsCount) {
    double res = 0.0;
    double lastVal = 0.0;
    int n = 1;
    
    do {
        lastVal = res;
        res += (float)(n * (n + 2)) * myPow(x, n);
        n++;
    } while (fabs(res - lastVal) >= k * eps);

    *iterationsCount = n;

    return res;
}

double typeSplitter() {
    int columnWidth = fieldSize + 3;

    for (int i = 0; i < columnWidth * columnsCount; i++) {
        if (i % columnWidth == 0) {
            printf("+");
            continue;
        } 

        printf("-");
    }

    printf("+\n");
}

int typeHeader() {
    printf("| %18s | %18s | %18s | %18s |\n", "x value", "f(x) - right way", "f(x) - Taylor", "Iterations");
}

int main() {
    double step = (b - a) / n;
    double x = a;
    double eps = getEps();
    int iterationsMax = 0;

    typeSplitter();
    typeHeader();
    typeSplitter();

    for (int i = 0; i < n + 1; i++) {
        double fVal = calcF(x);
        
        int iterationsCount;
        double fTaylorVal = calcFTaylor(x, eps, &iterationsCount);
        if (iterationsCount > iterationsMax) iterationsMax = iterationsCount;

        printf("| %18.15f | %18.15f | %18.15f | %18d |\n", x, fVal, fTaylorVal, iterationsCount);
        x += step;
    }

    typeSplitter();
    printf("Max iterations count was: %d", iterationsMax);

    return 0;
}