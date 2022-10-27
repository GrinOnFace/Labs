#include <stdio.h>
#include <malloc.h>

void readValue(int* row, int* column);
double** alloc(int row, int column);
int check(int row, int column);
void input_mat(double** mat, int row, int column);
void output_mat(double** mat, int row, int column);
double** calculation(double** mat1, double** mat2, int row, int column);
void func_free(double** mat, int row);

int main() {
    int row, column;
    readValue(&row, &column);
    if (check(row, column)) {
        double** mat1, ** mat2;
        mat1 = alloc(row, column);
        mat2 = alloc(column, row);
        if (mat1 == NULL || mat2 == NULL)
            printf("Memory not allocated");
        else {
            input_mat(mat1, row, column);
            mat2 = calculation(mat1, mat2, row, column);
            output_mat(mat2, column, row);
            func_free(mat1, row);
            func_free(mat2, column);
        }
    }
    else
        printf("Count of rows and columns must be greater than zero");
    return 0;
}

void input_mat(double** mat, int row, int column) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            scanf_s("%lf", &(*(*(mat + i) + j)));
}

void output_mat(double** mat, int row, int column) {
    printf("Your Matrix:\n");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; j++) {
            printf("| %7.2lf \t", *(*(mat + i) + j));
        }
        printf("|\n");
    }
}

int check(int row, int column) {
    int ans = 1;
    if (column <= 0 || row <= 0)
        ans = 0;
    return ans;
}

void readValue(int* row, int* column) {
    printf("Insert count of rows and columns:");
    scanf_s("%d %d", row, column);
}

double** alloc(int row, int column) {
    double** mat = (double**)malloc(row * sizeof(double*));
    if (mat != NULL) {
        for (int i = 0; i < row; i++) {
            *(mat + i) = (double*)malloc(column * sizeof(double));
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

double** calculation(double** mat1, double** mat2, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            *(*(mat2 + j) + i) = *(*(mat1 + row - 1 - i) + column - 1 - j);
        }
    }
    return mat2;
}

void func_free(double** mat, int row) {
    for (int i = 0; i < row; i++) {
        free(*(mat + i));
    }
    free(mat);
}