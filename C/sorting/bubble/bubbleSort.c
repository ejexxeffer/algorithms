#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{		
	int size, i, j = 0;
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
	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size; ++i)
		{
			if (bls[i]>bls[i+1])
			{
			bls[i]=bls[i]^bls[i+1];
			bls[i+1]=bls[i]^bls[i+1];
			bls[i]=bls[i]^bls[i+1];
			}
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