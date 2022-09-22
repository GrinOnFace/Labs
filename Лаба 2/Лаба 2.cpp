#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void insert(double* leftboarder, double* rightboarder, int* iterations);
void start(double leftboarder, double rightboarder, int iterations);
int check(double leftboarder, double rightboarder, int iterations);

void funcFor(double leftboarder, double Step, int iterations);
void funcWhile(double leftboarder, double rightboarder, double Step);
void funcDoWhile(double leftboarder, double rightboarder, double Step);

double calc(double i);

double stepiterations(double leftboarder, double rightboarder, int iterations);

int main(void) {
    double leftboarder, rightboarder;
    int iterations;
    while (true) {
        insert(&leftboarder, &rightboarder, &iterations);
        if (check(leftboarder, rightboarder, iterations)) {
            start(leftboarder, rightboarder, iterations);
            break;
        }
        else {
            printf("enter other values\n");
        }
    }
    return 0;
}

double calc(double i) {
    return ((sin(i) * sin(i)) / i);
}

void insert(double* leftboarder, double* rightboarder, int* iterations) {
    printf("Please insert leftboarder and rightboarder\n");
    scanf("%lf %lf", leftboarder, rightboarder);
    printf("Please insert number of iterations\n");
    scanf("%d", iterations);
}

double stepiterations(double leftboarder, double rightboarder, int iterations) {
    return (rightboarder - leftboarder) / (iterations - 1);
}

void funcFor(double leftboarder, double Step, int iterations) {
    double x = leftboarder;
    printf("for:\nx    |");
    for (int i = 0; i < iterations; i++) {
        printf(" %7.3lf |", leftboarder);
        leftboarder += Step;
    }
    leftboarder = x;
    printf("\nf(x) |");
    for (int i = 0; i < iterations; i++) {
        double meaning = calc(leftboarder);
        if (isnan(meaning)) {
            printf("  Error  |");
        }
        else {
            printf(" %7.3lf |", calc(leftboarder));
        }
        leftboarder += Step;
    }
}

void funcWhile(double leftboarder, double rightboarder, double Step) {
    printf("\nWhile:\nx    |");
    double meaning = leftboarder;
    double search = calc(leftboarder);
    if (leftboarder == rightboarder) {
        printf(" %7.3lf |", leftboarder);
        printf("\nf(x) |");
        if (isnan(search)) {
            printf("  Error  |");
        }
        else {
            printf(" %7.3lf |", calc(leftboarder));
        }
    }
    else {
        while (leftboarder < rightboarder + Step) {
            printf(" %7.3lf |", leftboarder);
            leftboarder += Step;
        }
        leftboarder = meaning;
        printf("\nf(x) |");
        while (leftboarder < rightboarder + Step) {
            search = calc(leftboarder);
            if (isnan((search))) {
                printf("  Error  |");
            }
            else {
                printf(" %7.3lf |", calc(leftboarder));
            }
            leftboarder += Step;
        }
    }
}

void funcDoWhile(double leftboarder, double rightboarder, double Step) {
    printf("\nDo While:\nx    |");
    double meaning = leftboarder;
    do {
        printf(" %7.3lf |", leftboarder);
        leftboarder += Step;
    } while (leftboarder < rightboarder + Step);
    leftboarder = meaning;
    printf("\nf(x) |");
    do {
        double search = calc(leftboarder);
        if (isnan((search))) {
            printf("  Error  |");
        }
        else {
            printf(" %7.3lf |", calc(leftboarder));
        }
        leftboarder += Step;
    } while (leftboarder < rightboarder + Step);
}

void start(double leftboarder, double rightboarder, int iterations) {
    double Step;
    if (leftboarder > rightboarder) {
        Step = stepiterations(rightboarder, leftboarder, iterations);
        funcFor(rightboarder, Step, iterations);
        funcWhile(rightboarder, leftboarder, Step);
        funcDoWhile(rightboarder, leftboarder, Step);
    }
    else {
        Step = stepiterations(leftboarder, rightboarder, iterations);
        funcFor(leftboarder, Step, iterations);
        funcWhile(leftboarder, rightboarder, Step);
        funcDoWhile(leftboarder, rightboarder, Step);
    }
}

int check(double leftboarder, double rightboarder, int iterations) {
    int result;
    if (iterations <= 0) {
        printf("iterations below 0\n");
        result = 0;
    }
    else if (leftboarder == rightboarder && iterations != 1) {
        printf("leftborder = rightborder and iterations more than 1\n");
        result = 0;
    }
    else if (leftboarder != rightboarder && iterations == 1) {
        printf("iterations = 1 and leftboaber != rightborder, it is impossible\n");
        result = 0;
    }
    else {
        result = 1;
    }
    return result;
}