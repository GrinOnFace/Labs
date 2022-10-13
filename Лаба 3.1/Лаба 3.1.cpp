#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>

void insert(double* E);
int check(double E);

double absolute(double x1, double x2);
double factorial(double num, double number);

void sum(double E);
double elements(double n, double number);

int main(void) {
    double E;
    while (1) {
        insert(&E);
        if (check(E)) {
            sum(E);
            printf("Press any button to restart the program\n");
            _getch();
        }
        else {
            continue;
        }
    }
    return 0;
}

void insert(double * E) {
    printf("Enter number E\n");
    scanf("%lf", E);
}

int check(double E) {
    int result;
    if (E <= 0) {
        printf("Number E should be greater than zero. Pls, input coorect number\n");
        result = 0;
    }
    result = 1;
    return result;
}

double absolute(double x1, double x2) {
    double abs;
    if (x1 - x2 < 0) {
        abs = (x1 - x2) * -1;
    }
    else {
        abs = (x1 - x2);
    }
    return abs;
}

void sum(double E) {
    double n = 2;
    double S;
    double sum = 1;
    double prev = 1;
    double step;
    do {
        S = sum;
        step = elements(n, prev);
        prev = factorial(n, prev);
        sum += step;
        n = n + 1;
    } while (absolute(sum, S) > E);
    printf("%.15lf\n", sum);
}

double factorial(double n, double number) {
    return (number * n);
}

double elements(double n, double number) {
    return (1.0 / factorial(n, number));
}