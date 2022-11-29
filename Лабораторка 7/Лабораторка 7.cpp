#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int counter = 0;

typedef enum Direction_t {
    RIGHT,
    LEFT,
    UP,
    DOWN
} Direction;

typedef struct It_t {
    int i;
    int j;
    Direction direction;
    int min_i;
    int min_j;
    int max_i;
    int max_j;
} It;

int getNext(It& it, int width, int height);

void readValue(int* width, int* height);
int check(int width, int height);
void swap(double* pa, double* pb);

double** alloc(int width, int height);

void inputMatrix(double** mat, int width, int height);
void outputMatrix(double** mat, int width, int height);

void funcFree(double** mat, int width);

double at(double** mat, It it);

int main() {
    //int width, height;
    //readValue(&width, &height);
    int width = 5, height = 5;

    if (check(width, height)) {
        double** matrix = alloc(width, height);
        if (matrix != NULL) {
            //inputMatrix(matrix, width, height);

            for (int i = 0; i < width; i++) {
                for (int j = 0; j < height; j++) {
                    matrix[i][j] = (double)(rand() % 1000) / (rand() % 10 + 1);
                }
            }

            outputMatrix(matrix, width, height);

            It it = { 0, 0, RIGHT, 1, 0, height, width };
            do {
                printf("%7.3lf, ", at(matrix, it));
            } while (getNext(it, width, height));

            funcFree(matrix, width);
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
    if ((height < 1 && width < 1) ||
        (height == 1 && width == 1) ||
        (height == 1 && width < 2) ||
        (height < 2 && width == 1))
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

void swap(double* pa, double* pb) {
    double temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void funcFree(double** mat, int width) {
    for (int i = 0; i < width; i++) {
        free(*(mat + i));
    }
    free(mat);
}

double at(double** mat, It it) {
    return *(*(mat + it.i) + it.j);
}

int getNext(It& it, int width, int height) {
    if (it.direction == RIGHT) {
        if (++it.j + 1 >= it.max_j) {
            it.max_j--;
            it.direction = DOWN;
            if (it.i >= it.max_i)
                return 0;
        }
    }
    else if (it.direction == LEFT) {
        if (--it.j <= it.min_j) {
            it.min_j++;
            it.direction = UP;
            if (it.i <= it.min_i)
                return 0;
        }
    }
    else if (it.direction == DOWN) {
        if (++it.i + 1 >= it.max_i) {
            it.max_i--;
            it.direction = LEFT;
            if (it.j <= it.min_j)
                return 0;
        }
    }
    else if (it.direction == UP) {
        if (--it.i <= it.min_i) {
            it.min_i++;
            it.direction = RIGHT;
            if (it.j >= it.max_j)
                return 0;
        }
    }

    return 1;
}
