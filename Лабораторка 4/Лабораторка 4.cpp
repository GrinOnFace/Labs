#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

// если завершилась успешно 0
// если возникла проблема ввода пользователя вернёт -1
// если память не освободилась, то -2

unsigned int userInputArraySize();
int userInputArray(int* arr, unsigned int arrSize);
int calculation(int* arr, unsigned int addSize, int* sum);

int main()
{
	int ret = 0, sum = 0, * arr = NULL;
	unsigned int arrSize = 0;
	if (0 == (arrSize = userInputArraySize()))
	{
		printf("Error. Incorrect array size");
		ret = -1;
		goto CleanUp;
	}
	arr = (int*)malloc(arrSize * sizeof(int));
	if (arr == NULL)
	{
		printf("Error. Not enough memory");
		ret = -2;
		goto CleanUp;
	}
	if (0 != (ret = userInputArray(arr, arrSize)))
	{
		printf("Input failed");
		goto CleanUp;
	}
	if (0 != (ret = calculation(arr, arrSize, &sum)))
	{
		printf("Input failed");
		goto CleanUp;
	}
	printf("result is %d\n", sum);

CleanUp:
	if (arr)
	{
		free(arr);
	}
	return ret;
}

unsigned int userInputArraySize()
{
	printf("Input Array Size\n");
	unsigned int size = 0;
	if (1 != scanf("%u", &size))
	{
		return 0;
	}
	return size;
}

int userInputArray(int* arr, unsigned int arrSize)
{
	unsigned int counter = 0;
	printf("Input %u numbers\n", arrSize);
	while (counter < arrSize)
	{
		if (1 != scanf("%d", arr + counter++))
		{
			return -1;
		}
	}
	return 0;
}

int calculation(int* arr, unsigned int arrSize, int* sum)
{
	if (arrSize == 0)
	{
		return -1;
	}

	int max = *arr;
	unsigned int maxPosition = 0;
	for (unsigned int i = 0; i < arrSize; i++)
	{
		if (*(arr + i) > max)
		{
			max = *(arr + i);
			maxPosition = i;
		}
	}

	if (maxPosition + 1 == arrSize)
	{
		*sum = 0;
		return 0;
	}

	int min = max;
	max = *(arr + maxPosition + 1);

	for (unsigned int i = maxPosition + 1; i < arrSize; i++)
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

	double mediana = (min + max) / 2;
	for (unsigned int i = maxPosition + 1; i < arrSize; i++)
	{
		if (*(arr + i) > mediana)
		{
			*sum += *(arr + i);
		}
	}

	return 0;
}