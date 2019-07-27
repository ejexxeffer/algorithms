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


int minVal (int *array, int a, int b) {
	return array[a] < array[b] ? a : b;
}

//Merge two sorted halves of array
void merge(int *array, int *buffer, int left, int right, int middle) {
	int middleP = middle + 1;
	int leftInc = left;
	for (int i = left; i<=right; i++) {		
		if (leftInc <= middle && middleP <= right){
			buffer[i] = array[minVal(array, leftInc, middleP)];
			leftInc == minVal(array, leftInc, middleP) ? leftInc++ : middleP++;
		} else {
			if (leftInc>middle) {
				buffer[i]=array[middleP];
				middleP++;
			}
			else {
			if (middleP>right)
				buffer[i]=array[leftInc];
				leftInc++;
			}
		}
	}

	for (int i = left; i <= right; i++)
	{
		array[i] = buffer[i];
	}
}

/*
First of all, the left half of the array is sorted, then the right half of the array sorted.
After the sorting is completed, start merge.
Attention! This is a recursion!!
*/
void mergeSort (int *array, int *buffer, int left, int right) {
	if(left < right) {
		int middle = (left+right)/2;
		mergeSort(array, buffer, left, middle);
		mergeSort(array, buffer, middle+1, right);
		merge(array, buffer, left, right, middle);
	}
}

int main() {
	int size = 0;
	printf("Please, size of an array.\n");
	scanf("%d", &size);
	//check value size
	if (size <= 0)
	{
		printf("Size must be positive value bigger than 0.\n");
		return 0;
	}
	int array[size];
	int buffer[size];	
	inputArray(array, size);
	printf("array size=%d\n", size);
	exportArray(array,size);
	
	// sort array of heap
	mergeSort(array, buffer, 0, size-1);
	// export sorted array
	printf("*********END SORTING*********\n");
	exportArray(array,size);
	return 0;
}