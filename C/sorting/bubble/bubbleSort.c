#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #include <stdlib.h>

int main()
{		
	int size;
	int bls[size];
	int i;
	int j;
	// input values
	printf("Please, size of an array.\n");
	scanf("%d", &size);
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
	/*// size of array
	for (i = 1; bls[i]!='\0'; i++)
	{
		size = i;
	}*/
	// sorting
	for (i = 0; i < size; i++)
	{
		for (j = size-1; j>i; j--)
		{
			if (bls[j-1]>bls[j])
			{
				bls[j-1]=bls[j-1]^bls[j];
				bls[j]=bls[j-1]^bls[j];
				bls[j-1]=bls[j-1]^bls[j];
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