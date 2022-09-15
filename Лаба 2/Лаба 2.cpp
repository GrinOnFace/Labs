#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <stdio.h>

int main() {
	return 0;
}

void insert(double* x, double* y, double* iterrations) {
	printf("input range:\n");
	scanf("%lf %lf", x, y);
	printf("How much iterrations?\n");
	scanf("%lf", iterrations);
}

double change(double x, double y, double itterations) {
	double change;
	change = ((x - y) / itterations - 1);
	return change;
}
bool error(double x, double y, double itterations) {
	if (x < y) {
		printf("Error. Try again\n");
		return false;
	}
	else if (x == y && itterations != 1) {
		printf("Error. Try again\n");
		return false;
	}
}
