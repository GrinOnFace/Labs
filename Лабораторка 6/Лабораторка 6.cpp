#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

void readValue(int* width, int* height);
int check(int width, int height);
void swap(double* pa, double* pb);

double** alloc(int width, int height);

void inputMatrix(double** mat, int width, int height);
void outputMatrix(double** mat, int width, int height);

double** transponseForRectangle(double** matrixOne, double** matrixTwo, int width, int height);
double** transponseForSquare(double** matrixOne, int width, int height);

void funcFree(double** mat, int width);

int main(){
    int width, height;
    readValue(&width, &height);
    if (check(width, height)) {
        double** matrixOne = alloc(width, height);
        if (matrixOne != NULL) {
            if (height == width) {
                inputMatrix(matrixOne, width, height);
                transponseForSquare(matrixOne, width, height);
                outputMatrix(matrixOne, width, height);
                funcFree(matrixOne, width);
            }
            else {
                double** matrixTwo = alloc(height, width);
                if (matrixTwo != NULL) {
                    inputMatrix(matrixOne, width, height);
                    matrixTwo = transponseForRectangle(matrixOne, matrixTwo, width, height);
                    outputMatrix(matrixTwo, height, width);
                    funcFree(matrixOne, width);
                    funcFree(matrixTwo, height);
                }
                else
                    printf("Memory dont allocated");
            }
        }
        else 
            printf("Memory dont allocated");
    }
    else
        printf("Enter correct width and height");
}

void inputMatrix(double** mat, int width, int height) {
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            scanf_s("%lf", &(*(*(mat + i) + j)));
}

void outputMatrix(double** mat, int width, int height) {
    printf("Your Matrix:\n");
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; j++) {
            printf("|   %7.3lf \t", *(*(mat + i) + j));
        }
        printf("|\n");
    }
}

int check(int width, int height) {
    int ans = 1;
    if ((height < 1 || width < 1) || (height == 1 && width == 1) || (height == 1 && width < 2) || (height < 2 && width == 1))
        ans = 0;
    return ans;
}

void readValue(int* width, int* height) {
    printf("Insert count of widths and heights:\n");
    scanf_s("%d %d", width, height);
}

double** alloc(int width, int height) {
    double** mat = (double**)malloc(width * sizeof(double*));
    if (mat != NULL) {
        for (int i = 0; i < width; i++) {
            *(mat + i) = (double*)malloc(height * sizeof(double));
            if (*(mat + i) == NULL) {
                while (--i >= 0) {
                    free(*(mat + i));
                }
                free(mat);
            }
        }
    }
    return mat;
}

double** transponseForRectangle(double** matrixOne, double** matrixTwo, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            *(*(matrixTwo + j) + i) = *(*(matrixOne + width - 1 - i) + height - 1 - j);
        }
    }
    return matrixTwo;
}

void swap(double* pa, double* pb) {
    double temp = *pa;
    *pa = *pb;
    *pb = temp;
}

double** transponseForSquare(double** matrixOne, int width, int height) {
    for (int i = 0; i < width - 1; i++) {
        for (int j = 0; j < height - 1; j++) {
            swap(*(matrixOne + i) + j, *(matrixOne + width - 1 - j) + height - 1 - i);
        }
    }
    return matrixOne;
}

void funcFree(double** mat, int width) {
    for (int i = 0; i < width; i++) {
        free(*(mat + i));   
    }
    free(mat);
}