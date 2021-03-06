#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int size, i, j, key, m = 0;
	int count = 1;
	int countBuffer = 0;
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
	
	// sorting with find steps
	for (i = size/2; i>=1; i/=2)
	{	
		countBuffer = i;
		for (m = countBuffer; m < size; m++)
		{
			key = bls[m];
			for (j=m-countBuffer; j >= 0 && bls[j]>key; j-=countBuffer)
			{	

				bls[j+countBuffer]=bls[j];
			}
			bls[j+countBuffer]=key;
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