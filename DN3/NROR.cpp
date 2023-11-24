#include <iostream>
#include <cmath>

double e3x(double x) {
    return exp(3 * x);
}

double arctan(double x, int terms) {
    double result = 0.0;
    for (int n = 0; n < terms; ++n) {
        result += pow(-1, n) * pow(x, 2 * n + 1) / (2 * n + 1);
    }
    return result;
}

double trapezoidalRule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        result += f(x);
    }

    result *= h;

    return result;
}

int main() {
    double a = 0.0;
    double b = M_PI / 4.0;
    int n = 1000;

    double integralValue = trapezoidalRule([](double x) {
        return e3x(x) * arctan(x / 2.0, 100);
    }, a, b, n);

    std::cout << "Priblizna vrednost integrala: " << integralValue << std::endl;

    return 0;
}