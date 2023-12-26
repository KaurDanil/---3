#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double reference = 1.8832;
const double a = 1.0;
const double b = 3.0;
const double eps = 0.0001;

double f(double x) {
    double lnX = log(x);
    return 3.0 * lnX * lnX + 6.0 * lnX - 5.0;
}

double dfdx(double x) {
    return (6.0 * log(x) + 6.0) / x;
}

double newton(double a, double b, double eps, double (*f)(double x), double(*dfdx)(double x)) {
    double lastX = (a + b) / 2.0;
    double x = lastX - f(lastX) / dfdx(lastX);

    while (fabs(x - lastX) >= eps) {
        lastX = x;
        x = x - f(x) / dfdx(x);
    }

    return x;
}

int main() {
    double newtonSolution = newton(a, b, eps, f, dfdx);
    double fVal = f(newtonSolution);

    printf("Reference root: %f\nNewton's method: %f\nF(x) = %e", reference, newtonSolution, fVal);

    return 0;
}