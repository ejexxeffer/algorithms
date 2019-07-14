#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



//print array
void exportArray (int *array, int size) {	
	printf("This is your array: ");
	for (int i=0; i < size; i++) 
		printf("%d%s", array[i], i==size-1 ? "\n\n" : " ");
}
//input values in array
void inputArray (int *array, int size) {
	for (int i=0; i < size; i++)
	{
		printf("Please, enter value: ");
		scanf("%d", &array[i]);
	}
}

//binary change
void change (int *array, int i, int j) {
	array[i]=array[i]^array[j];
	array[j]=array[i]^array[j];
	array[i]=array[i]^array[j];
}
//sorting child is elements from parent
void maxHeap (int *array, int size, int i) {
	int j = i;
	if (2*i+1<size && array[2*i+1]>array[i]) j=2*i+1;
	if (2*i+2<size && array[2*i+2]>array[i]) j=2*i+2;
	if (j!=i) change(array,j,i);
}

void heapSort (int *array, int size) {
	//make heap
	for (int i=size/2; i>=0; i--) {
		maxHeap(array, size, i);
	}
	int last = size;
	while (last>1) {
		last--;
		change(array, 0, last);

		heapSort(array,last);
	}
}

int main() {
	int size, i, j, key, m = 0;
	int count = 1;
	int countBuffer = 0;
	printf("Please, size of an array.\n");
	scanf("%d", &size);
	//check value size
	if (size <= 0)
	{
		printf("Size must be positive value bigger than 0.\n");
		return 0;
	}
	int bls[size];	
	inputArray(bls, size);
	printf("array size=%d\n", size);
	exportArray(bls,size);
	
	// sort array of heap
	heapSort(bls,size);
	// export sorted array
	exportArray(bls,size);
	return 0;
}