#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double FirstLine(double x, double y);
double SecondLine(double x, double y);
double ThirdLine(double x, double y);

void insert(double* x, double* y);

void PositionOnLine(int ResFirstLine, int ResSecondLine, int ResThirdLine);
void PositionOnZone(int ResFirstLine, int ResSecondLine, int ResThirdLine);

int main() {
	int ResFirstLine, ResSecondLine, ResThirdLine;
	double x, y;
	insert(&x, &y);
	ResFirstLine = FirstLine(x, y);
	ResSecondLine = SecondLine(x, y);
	ResThirdLine = ThirdLine(x, y);
	if (ResFirstLine == 0 || ResSecondLine == 0 || ResThirdLine == 0) {
		PositionOnLine(ResFirstLine, ResSecondLine, ResThirdLine);
	}
	else {
		PositionOnZone(ResFirstLine, ResSecondLine, ResThirdLine);
	}
}

void insert(double* x, double* y) {
	printf("Please insert coordinates of the point\n");
	scanf("%lf %lf", x, y);
}

void PositionOnLine(int ResFirstLine, int ResSecondLine, int ResThirdLine) {
	if (ResFirstLine == 0 && ResSecondLine != 0 && ResThirdLine != 0) {
		printf("The point lies on a straight line y = 2x + 2\n");
	}
	else if (ResFirstLine != 0 && ResSecondLine == 0 && ResThirdLine != 0) {
		printf("The point lies on a straight line y = 0.5x - 1\n");
	}
	else if (ResFirstLine != 0 && ResSecondLine != 0 && ResThirdLine == 0) {
		printf("The point lies on a straight line y = -x + 2\n");
	}
	else if (ResFirstLine == 0 && ResSecondLine == 0) {
		printf("The point lies at the intersection of the lines y = 2x + 2 and y = 0.5x - 1\n");
	}
	else if (ResFirstLine == 0 && ResThirdLine == 0) {
		printf("The point lies at the intersection of the lines y = 2x + 2 and y = -x + 2\n");
	}
	else {
		printf("The point lies at the intersection of the lines y = 0.5x - 1 and y = -x + 2\n");
	}
}

void PositionOnZone(int ResFirstLine, int ResSecondLine, int ResThirdLine) {
	if (ResFirstLine == 2 && ResSecondLine == 1 && ResThirdLine == 1) {
		printf("The point lies in #1 zone\n");
	}
	else if (ResSecondLine == 2 && ResThirdLine == 1) {
		printf("The point lies in #2 zone\n");
	}
	else if (ResFirstLine == 2 && ResSecondLine == 2 && ResThirdLine == 2) {
		printf("The point lies in #3 zone\n");
	}
	else if (ResFirstLine == 1 && ResSecondLine == 2) {
		printf("The point lies in #4 zone\n");
	}
	else if (ResFirstLine == 1 && ResSecondLine == 1 && ResThirdLine == 2) {
		printf("The point lies in #5 zone\n");
	}
	else if (ResFirstLine == 1 && ResThirdLine == 1) {
		printf("The point lies in #6 zone\n");
	}
	else {
		printf("The point lies in #7 zone\n");
	}
}

double FirstLine(double x, double y) {
	int res;
	if (y == (2 * x + 2)) {// На линии
		res = 0;
	}
	else if (y > (2 * x + 2)) {// Выше линии
		res = 1;
	}
	else {// Ниже линии
		res = 2;
	}
	return res;
}

double SecondLine(double x, double y) {
	int res;
	if (y == (0.5 * x - 1)) {// На линии
		res = 0;
	}
	else if (y > (0.5 * x - 1)) {// Выше линии
		res = 1;
	}
	else {// Ниже линии
		res = 2;
	}
	return res;
}

double ThirdLine(double x, double y) {
	int res;
	if (y == (-x + 2)) { // На линии
		res = 0;
	}
	else if (y > (-x + 2)) {// Выше линии
		res = 1;
	}
	else {// Ниже линии
		res = 2;
	}
	return res;
}
