#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

//Если программа вывела -1, то память не аллоцировалась
//Если программа вывела -2, то все ок
//Если программа вывела -3, то введенные значения некорректны

void readValue(int* width, int* height);
int check(int width, int height);

double** alloc(int width, int height);

void inputMatrix(double** mat, int width, int height);
void outputMatrix(double** mat, int width, int height);

double** transponse(double** matrixOne, double** matrixTwo, int width, int height);

void funcFree(double** mat, int width);

int main() 
{
    int width, height;
    while(1)
    {  
        readValue(&width, &height);
        if (check(width, height))
        {
            double** matrixOne,** matrixTwo;
            matrixOne = alloc(width, height);
            matrixTwo = alloc(height, width);
            if (matrixOne == NULL || matrixTwo == NULL)
            {
                printf("Memory not allocated");
                return -1;
            }
            else
            {
                inputMatrix(matrixOne, width, height);
                matrixTwo = transponse(matrixOne, matrixTwo, width, height);
                outputMatrix(matrixTwo, height, width);
                funcFree(matrixOne, width);
                funcFree(matrixTwo, height);
                return -2;
            }
        }
        else
            printf("Enter correct width and height");
            return -3;
    }
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
                mat = NULL;
            }
        }
    }
    return mat;
}

double** transponse(double** matrixOne, double** matrixTwo, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            *(*(matrixTwo + j) + i) = *(*(matrixOne + width - 1 - i) + height - 1 - j);
        }
    }
    return matrixTwo;
}

void funcFree(double** mat, int width) {
    for (int i = 0; i < width; i++) {
        free(*(mat + i));   
    }
    free(mat);
}