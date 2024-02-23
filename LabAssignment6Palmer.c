#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value)

{
    // base case: the array is empty or the value is not in the range
    if (low > high)
    {
        return -1;
    }

    // find the middle index
    int mid = (low + high) / 2;

    // compare the value with the middle element
    if (value == numbers[mid])
    {
        return mid; // locate the value
    }
    else if (value < numbers[mid])
    {
        return search(numbers, low, mid - 1, value); // search in the left side
    }
    else
    {
        return search(numbers, mid + 1, high, value); // search in the right side
    }
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}