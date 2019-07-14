#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{		
	int size, i, j, min, f = 0;
	// input values
	printf("Please, size of an array.\n");
	scanf("%d", &size);
	if (size <= 0)
	{
		printf("Size must be positive value.\n");
		return 0;
	}

	int bls[size];

	for (i=0; i < size; i++)
	{
		printf("Please, enter value: ");
		scanf("%d", &bls[i]);
	}

	// export array
	printf("This is your array: ");
	for (i=0; i < size; i++) 
	{
		printf("%d ", bls[i]);
	}
	printf("size=%d\n", size);
	printf("\n");

	/*// size of array (for strings)
	for (i = 1; bls[i]!='\0'; i++)
	{
		size = i;
	}*/

	// sorting
	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j<size; j++)
		{
			if (bls[j] < bls[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			bls[i]=bls[i]^bls[min];
			bls[min]=bls[i]^bls[min];
			bls[i]=bls[i]^bls[min];
		}
	}
	
	// export array
	printf("This is your array: ");
	for (i=0; i < size; i++) 
	{
		printf("%d ", bls[i]);
	}
	printf("size=%d\n", size);
	printf("\n");

	return 0;
}