#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int size, i, j, key = 0;
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
	for (i = 1; i < size; i++)
	{
		key = bls[i];
		for (j=i-1; j >=0 && bls[j]>key; j--)
		{
			bls[j+1]=bls[j];
		}
		bls [j+1] = key;
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