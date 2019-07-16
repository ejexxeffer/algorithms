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

int maxVal (int *array, int a, int b) {
	return array[a] > array[b] ? a : b;
}

int maxHeap (int *array, int size, int i) {
	int j = 0;
	int m = 2*i+1;
	if((m)<size && (m+1)<size) {
		j=maxVal(array,m, m+1);
	} else if (m<size) {
		j=m;
	} else if (m+1<size) {
		j=m+1;
	} else j=i;
	j = maxVal(array, i, j);
	if (j!=i){
		change(array, i, j);
		return j;
	} else {
		return -1;
	}
}


//sorting child is elements from parent
void heap(int *array, int size, int i) {
	int j = i;
	exportArray(array,size);
	do {
		printf("j=%d\n", j);
		printf("i=%d\n", i);
		j = maxHeap(array,size,j);
	} while (j<=size/2-1 && j!=-1);
}

void heapSort (int *array, int size) {
	//make heap
	for (int i=size/2-1; i>=0; i--) {
		printf("i=%d\n", i);
		heap(array, size, i);
	}
	exportArray(array,size);
	printf("*********END HEAP*********\n");
	int last = size - 1;
	printf("*********BEGIN SORTING*********\n");
	while (last>0) {
		change(array, 0, last);
		heap(array,last, 0);
		exportArray(array,size);
		printf("*********END STEP*********\n");		
		last --;	
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
	int bls[size];	
	inputArray(bls, size);
	printf("array size=%d\n", size);
	exportArray(bls,size);
	
	// sort array of heap
	heapSort(bls,size);
	// export sorted array
	printf("*********END SORTING*********\n");
	exportArray(bls,size);
	return 0;
}