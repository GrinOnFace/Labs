#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

void insert(double* E, double* a, double* b);
int examination(double a, double b, double E);

void Sum(double E, double a, double b);
double LeftRectangle(double N, double x, double h);
double RowElem(double i, double x, double h);
double rE(double E);

double abs(double x1, double x2);

int main() {
    double E, a, b;
    while (1) {
        insert(&E, &a, &b);
        if (examination(a, b, E)) {
            Sum(E, a, b);
            _getch();
        }
        else {
            continue;
        }
    }
    return 0;
}

void insert(double* E, double* a, double* b) {
    printf("enter E\n");
    scanf("%lf", E);
    printf("enter a and b\n");
    scanf("%lf %lf", a, b);
}

int examination(double a, double b, double E) {
    if (E <= 0 || a <= 0 || b <= 0) {
        printf("Numbers should be greater than zero\n");
        return 0;
    }
    return 1;
}

double abs(double x1, double x2) {
    if (x1 - x2 < 0) {
        return (x1 - x2) * -1;
    }
    else {
        return (x1 - x2);
    }
}

double LeftRectangle(double N, double x, double h) {
    double S = 0;
    for (int i = 1; i <= N; i++) {
        S += RowElem(i, x, h);
        x += h;
    }
    return S;
}

double RowElem(double i, double x, double h) {
    double sn = h * log(x - h);
    return sn;
}

double rE(double E) {
    double i = 1;
    while (E > i) {
        i *= 10;
    }
    return E / i;
}

void Sum(double E, double a, double b) {
    double flag = 0;
    if (a > b) {
        double a1 = a;
        flag = 1;
        a = b;
        b = a1;
        E = rE(E);
    }
    double sa = LeftRectangle(1, b, (b - a));
    double sb = LeftRectangle(2, a + (b - a) / 2, (b - a) / 2);
    double S;
    double N = 4;
    double h = 4;
    double x = a + h;
    while (abs(sa, sb) >= E) {
        sa = sb;
        sb = LeftRectangle(N, x, h);
        N *= 2;
        h = (b - a) / N;
        x = a + h;
    }
    if (flag == 1) {
        printf(" %.10lf\n", (sb * -1));
    }
    else {
        printf(" %.10lf\n", sb);
    }
}