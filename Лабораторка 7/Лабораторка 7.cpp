#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

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
    int step;
    int counter;
} It;

int getNext(It& it, int width, int height);

void readValue(int* width, int* height);
int check(int width, int height);
void swap(double* pa, double* pb);
void swapInto(double** matrix, It pa, It pb);

double** alloc(int width, int height);

void inputMatrix(double** mat, int width, int height);
void outputMatrix(double** mat, int width, int height);

void funcFree(double** mat, int width);
void sort(double** mat, int width, int height);

double at(double** mat, It it);

int main() {
    int width, height;
    readValue(&width, &height);
    if (check(width, height)) {
        double** matrix = alloc(width, height);
        if (matrix != NULL) {
            inputMatrix(matrix, width, height);
            printf("Preveous matrix\n");
            outputMatrix(matrix, width, height);
            sort(matrix, width, height);
            printf("Sort matrix\n");
            outputMatrix(matrix, width, height);
            funcFree(matrix, width);
        }
        else
            printf("Memory dont allocated");
    }
    else
        printf("Enter correct width and height");
}

void inputMatrix(double** mat, int width, int height) {
    printf("Input matrix\n");
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            scanf_s("%lf", &(*(*(mat + i) + j)));
}

void outputMatrix(double** mat, int width, int height) {
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

void swapInto(double** matrix, It pa, It pb) {
    return swap((*(matrix + pa.j) + pa.i), (*(matrix + pb.j) + pb.i));
}

void funcFree(double** mat, int width) {
    for (int i = 0; i < width; i++) {
        free(*(mat + i));
    }
    free(mat);
}

double at(double** mat, It it) {
    return *(*(mat + it.j) + it.i);
}

bool isValid(It& it, int width, int height) {
    return (it.i < height) && (it.j < width) && (it.i >= 0) && (it.j >= 0);
}

int getNext(It& it, int width, int height) {
    if (it.direction == UP) {
        it.j--;
        it.counter++;
        if (it.counter == it.step) {
            it.direction = LEFT;
            it.counter = 0;
        }
    }
    else if (it.direction == LEFT) {
        it.i--;
        it.counter++;
        if (it.counter == it.step) {
            it.direction = DOWN;
            it.counter = 0;
            it.step++;
        }
    }
    else if (it.direction == DOWN) {
        it.j++;
        it.counter++;
        if (it.counter == it.step) {
            it.direction = RIGHT;
            it.counter = 0;
        }
    }
    else if (it.direction == RIGHT) {
        it.i++;
        it.counter++;
        if (it.counter == it.step) {
            it.direction = UP;
            it.counter = 0;
            it.step++;
        }
    }
    if (isValid(it, width, height)) {
        return 1;
    }
    if (it.step > width && it.step > height) {
        return 0;
    }
    return getNext(it, width, height);
}

void sort(double** matrix, int width, int height)
{
    It begin = { height / 2, width / 2, UP, 1, 0 };
    do {
        It cur = begin, min = begin;
        do {
            if (at(matrix, cur) < at(matrix, min)) {
                min = cur;
            }
        } while (getNext(cur, width, height));
        swapInto(matrix, begin, min);
    } while (getNext(begin, width, height));
}