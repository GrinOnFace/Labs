#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

unsigned int userInputArraySize();
void CleanUp(double* arr);
int userInputArray(double* arr, int arrSize);
int calculation(double* arr, int arrSize, double* sum);
void MallocF(double** arr, int arrSize);
void mediana(double max, double min, unsigned int maxPosition, int arrSize, double* sum, double* arr);
int check(unsigned int maxPosition, int arrSize);

int main()
{
	int arrSize = 0;
	double* arr = NULL, sum = 0;
	if (2 >= (arrSize = userInputArraySize()))
	{
		printf("Error. Incorrect array size\n");
		CleanUp(arr);
	}
	else
	{
		MallocF(&arr, arrSize);
		if (arr)
		{
			CleanUp(arr);
		}
		if (0 != userInputArray(arr, arrSize))
		{
			printf("Input failed\n");
			CleanUp(arr);
		}
		if (0 != calculation(arr, arrSize, &sum))
		{
			printf("Input failed\n");
			CleanUp(arr);
		}
		printf("result is %lf\n", sum);
	}
}

void MallocF(double** arr, int arrSize)
{
	double* temp = (double*)malloc(arrSize * sizeof(double));
	*arr = temp;
}

void CleanUp(double* arr)
{
	if (arr)
	{
		free(arr);
	}
}

unsigned int userInputArraySize()
{
	printf("Input Array Size\n");
	int size = 0;
	if (1 != scanf("%d", &size))
	{
		return 0;
	}
	return size;
}

int userInputArray(double* arr, int arrSize)
{
	int counter = 0;
	printf("Input %d numbers\n", arrSize);
	while (counter < arrSize)
	{
		if (1 != scanf("%lf", arr + counter++))
		{
			return -1;
		}
	}
	return 0;
}

void mediana(double max, double min, unsigned int maxPosition, int arrSize, double* sum, double* arr)
{
	double mediana = (min + max) / 2;
	for (int i = maxPosition + 1; i < arrSize; i++)
	{
		if (*(arr + i) > mediana)
		{
			*sum += *(arr + i);
		}
	}
}

int check(unsigned int maxPosition, int arrSize)
{
	if ((maxPosition + 1 == arrSize) || (maxPosition + 2 == arrSize))
	{
		printf("No such elements\n");
		return -1;
	}
	return 0;
}

int calculation(double* arr, int arrSize, double* sum)
{
	double max = *arr;
	unsigned int maxPosition = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (*(arr + i) > max)
		{
			max = *(arr + i);
			maxPosition = i;
		}
	}
	if (-1 == check(maxPosition, arrSize))
	{
		return -1;
	}
	else {
		double min = max;
		max = *(arr + maxPosition + 1);
		for (int i = maxPosition + 1; i < arrSize; i++)
		{
			if (*(arr + i) > max)
			{
				max = *(arr + i);
			}
			if (*(arr + i) < min)
			{
				min = *(arr + i);
			}
		}
		mediana(max, min, maxPosition, arrSize, sum, arr);
		return 0;
	}
}