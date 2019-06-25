#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #include <stdlib.h>

int main()
{		
	int size = 0,
		i = 0, 
		j = 0, 
		left = 1,
		count = 0,
		last = 0;
	// input values
	printf("Please, size of an array.\n");
	scanf("%d", &size);

	if (size <= 0)
	{
		printf("Size must be positive value.\n");
		return 0;
	}

	int bls[size];
	int right = size-1;

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

	// sorting
	 do
	{
		for(i = right; i >= left; i--)
		{
			if(bls[i-1] > bls[i])
			{
				bls[i]=bls[i]^bls[i-1];
				bls[i-1]=bls[i]^bls[i-1];
				bls[i]=bls[i]^bls[i-1];
				last = i;
			}
		}

		left = last + 1;

		for(i = left; i <= right; i++)
		{
			if(bls[i-1] > bls[i])
			{
				bls[i]=bls[i]^bls[i-1];
				bls[i-1]=bls[i]^bls[i-1];
				bls[i]=bls[i]^bls[i-1];
				last = i;
			}
		}

		right = last-1;

	} while(left < right);
	
	// export array
	printf("This is your array: ");
	for (i=0; i < size; i++) 
	{
		printf("%d ", bls[i]);
	}
	printf("size=%d\n", size);;
	printf("\n");

	return 0;
}