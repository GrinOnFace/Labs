#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

int userInputArraySize();
int calculation(double* arr, int arrSize, double* sum);
int mallocF(double** arr, int arrSize);
int medianaF(double max, double min, unsigned int maxPosition, int arrSize, double* sum, double* arr);

int main()
{
    int arrSize = 0;
    double sum = 0;
    double* arr = NULL;

    if (2 >= (arrSize = userInputArraySize()))
    {
        printf("Error. Incorrect array size\n");
    }   
    else
    {
        if (mallocF(&arr, arrSize) == 0)
        {
            printf("Memory not allocated");
        }
        if (calculation(arr, arrSize, &sum) == 0)
        {
            printf("result is %lf\n", sum);
        }
        free(arr);
    }
}

int mallocF(double** arr, int arrSize)
{
    double* temp = (double*)malloc(arrSize * sizeof(double));
    *arr = temp;
    unsigned int ans;
    printf("Input elements of array:\n");
    if (temp != NULL) 
    {
        for (int i = 0; i < arrSize; ++i)
        {
            scanf_s("%lf", temp + i);
        }
        ans = 1;
    }
    else {
        ans = 0;
    }
    return ans;
}

int userInputArraySize()
{
    printf("Input Array Size\n");
    int size = 0;
    if (1 != scanf("%d", &size))
    {
        return 0;
    }
    return size;
}

int calculation(double* arr, int arrSize, double* sum)
{
    int ans = 0;
    double max = *arr;
    double min = *arr;
    unsigned int maxPosition = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
            maxPosition = i;
        }
    }
    for (int i = 0; i < arrSize; i++)
    {
        if (*(arr + i) < min)
        {
            min = *(arr + i);
        }
    }
    if (medianaF(max, min, maxPosition, arrSize, sum, arr) == 1)
    {
        printf("No such elements\n");
        ans = 1;
    }
    return ans;
}

int medianaF(double max, double min, unsigned int maxPosition, int arrSize, double* sum, double* arr)
{
    int ans = 0;
    unsigned int counter = 0;
    double middle = ((max + min) / 2);
    for (int i = maxPosition + 1; i < arrSize; i++)

        if (*(arr + i) > middle)
        {
            *sum += *(arr + i);
            counter++;
        }
    if (counter == 0)
    {
        ans = 1;
    }
    return ans;
}