#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{		
	int size, i, j, m = 0;
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
	for (i = 0; i < size-1; i++)
	{
		m = i;
		for (j = i + 1; j < size-1 && j!=i; ++j)
		{
			if (bls[j]<bls[m])
			{
				m = j;
			}
		}
		bls[j]=bls[i]^bls[j];
		bls[i]=bls[i]^bls[j];
		bls[j]=bls[i]^bls[j];
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