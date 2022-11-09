#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

void readValue(int* width, int* height);
int check(int width, int height);

double** alloc(int width, int height);

void inputMatrix(double** mat, int width, int height);
void outputMatrix(double** mat, int width, int height);
void findMax(double** mat, int width, int height, double sum);
double findSum(double** mat, int width, int height);

void funcFree(double** mat, int width);

int main() {
    int width, height;
    readValue(&width, &height);
    if (check(width, height)) {
        double** matrix = alloc(width, height);
        if (matrix != NULL) {
            inputMatrix(matrix, width, height);
            findMax(matrix, width, height, findSum(matrix, width, height));
            outputMatrix(matrix, width, height);
            funcFree(matrix, width);
        }
        else
            printf("Memory not allocated");
    }
    else
        printf("Enter correct width and height");
}

void inputMatrix(double** mat, int width, int height) {
    printf("Please, insert values for matrix\n");
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            scanf_s("%lf", &(*(*(mat + i) + j)));
}

void outputMatrix(double** mat, int width, int height) {
    printf("Your Matrix:\n");
    for (unsigned int i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; j++) {
            printf("|   %7.3lf \t", *(*(mat + i) + j));
        }
        printf("|\n");
    }
}

int check(int width, int height) {
    unsigned int ans = 1; 
    if ((height < 1 || width < 1) || (height == 1 && width == 1) || (height == 1 && width < 2) || (height < 2 && width == 1)) {
        printf("These values dont form a matrix\n");
        ans = 0;
    }
    else if (width == 1 && height > 1) {
        printf("No elements above the secondary diagonal\n");
        ans = 0;
    }
    return ans;
}

void readValue(int* width, int* height) {
    printf("Insert count of widths and heights:\n");
    scanf_s("%d %d", width, height);
}

double** alloc(int width, int height) {
    double** mat = (double**)malloc(width * sizeof(double*));
    if (mat != NULL) {
        for (unsigned int i = 0; i < width; i++) {
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

void funcFree(double** mat, int width) {
    for (unsigned int i = 0; i < width; i++) {
        free(*(mat + i));
    }
    free(mat);
}

void findMax(double** mat, int width, int height, double sum) {
    unsigned int positionX = 0;
    unsigned int positionY = 0;
    double max = *(*(mat));
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
            if (*(*(mat + i) + j) > max) {
                max = *(*(mat + i) + j);
                positionX = i;
                positionY = j;
            }
    *(*(mat + positionX) + positionY) = sum;
}

double findSum(double** mat, int width, int height) {
    double sum = 0;
    for (unsigned int i = 0; i < width - i; i++)
        for (unsigned int j = 0; j < width - i - 1; j++)
            sum += mat[i][j];
    return sum; 
}



