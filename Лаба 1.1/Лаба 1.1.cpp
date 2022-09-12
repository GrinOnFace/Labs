#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void intern(double* x, double* y);
void FindPosition(double x, double y);

int main() {
	double x, y;
	intern(&x, &y);
	FindPosition(x, y);
	return 0;
}

void intern(double* x, double* y) {
	printf("Line equation: y = 0.5x + 1\n");
	printf("Please insert coordinates of the point: \n");
	scanf("%lf %lf", x, y);
}

void FindPosition(double x, double y) {
	if (y == (0.5 * x + 1)) {
		printf("Point is on the line");
	}
	else if (y < (0.5 * x + 1)) {
		printf("Point is above the line");
	}
	else {
		printf("Point is below the line");
	}
}