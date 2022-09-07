#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    printf("Line equation: y = 0.5x + 1\n");
    printf("Please insert coordinates of the point: \n");
    double x, y;
    scanf("%lf %lf", &x, &y);
    if (y == (0.5 * x + 1)) {
        printf("Point is on the line");
    }
    else if (y < (0.5 * x + 1)) {
        printf("Point is above the line");
    }
    else {
        printf("Point is below the line");
    }
    return 0;
}