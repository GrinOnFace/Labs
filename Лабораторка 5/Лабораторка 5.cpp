#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void userInputArraySize(int* arrSize);
int mallocF(double** arr, int arrSize);

void swap(double* pa, double* pb);
int check(int arrSize);

void sort(double* arr, int arrSize);
int groupElem(double* arr, int arrSize);
void sortBelowZero(double* arr, int arrSize);
void resArray(double* arr, int arrSize);

void main()
{
    int arrSize = 0;
    userInputArraySize(&arrSize);
    if(check(arrSize) == 1)
    {
        double* arr = NULL;
        if (mallocF(&arr, arrSize) == 0)
        {
            printf("Memory not allocated");
        }
        else
        {
            sort(arr, arrSize);
            groupElem(arr, arrSize);
            sortBelowZero(arr, arrSize);
            printf("Result of the sorted is: \n");
            resArray(arr, arrSize);
            free(arr);
        }
    }
    else
    {
        printf("Size should be greater than zero");
    }
}

int mallocF(double** arr, int arrSize)
{
    double* temp = (double*)malloc(arrSize * sizeof(double));
    *arr = temp;
    unsigned int ans;
    printf("Input elements of array:\n");
    if (temp != NULL) {
        for (int i = 0; i < arrSize; ++i) {
            scanf("%lf", temp + i);
        }
        ans = 1;
    }
    else {
        ans = 0;
    }
    return ans;
}

int check(int arrSize) 
{
    unsigned int ans;
    if (arrSize < 0)
        ans = 0;
    else
        ans = 1;
    return ans;
}

void swap(double* pa, double* pb)
{
    double temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void userInputArraySize(int* arrSize)
{
    printf("Input Array Size\n");
    scanf("%d", arrSize);
}

void sort(double* arr, int arrSize)
{
    for (int i = 0; i < arrSize - 1; i++)
        for (int j = i + 1; j < arrSize; j++)
            if (*(arr + i) > *(arr + j))
                swap(arr + i, arr + j);
}

int groupElem(double* arr, int arrSize)
{
    int j = 0;
    for (int i = 0; i < arrSize; i++)
        if (*(arr + i) >= 0) {
            swap(arr + i, arr + j);
            j++;
        }
    return j;
}

void sortBelowZero(double* arr, int arrSize) {
    for (int i = 0; i < arrSize - 1; i++)
        for (int j = i + 1; j < arrSize; j++)
            if (*(arr + i) < 0 && *(arr + i) > *(arr + j))
                swap(arr + i, arr + j);
}

void resArray(double* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        printf("%lf\n", *(arr + i));
    }
}