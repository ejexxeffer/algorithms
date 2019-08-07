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

int minVal (int *array, int a, int b) {
	return array[a] < array[b] ? a : b;
}

//Make partition and sort array values to left and right site 
// //from supporting element
int partition(int *array, int left, int right) {
	int p = array[(left+right)/2];
	int l = left;
	int r = right;
	while (l<=r)
	{
		while (array[l]< p) l++;
		while (array[r]> p) r--;
		if (l>=r) return r;
		change(array,l,r);
	} 
}




/*
Find supporting element, then make sorting left and right sides.
Make quicksort to left and right sides. 
Attention! This is a recursion!!
*/

/*void quickSort (int *array, int first, int last) {
	if (first < last) {
	int p = array[(first+last)/2];
	int l = first;
	int r = last;
	do
	{
		while (array[l]< array[p]) l++;
		while (array[r]> array[p]) r--;
		if (l<=r)
		{
			change(array,l,r);
			l++; r--;
		}
	} while (l<=r);
	if (r>first)quickSort(array, first, r);
	if (last>l)quickSort(array, l, last);
	}
	
}*/
void quickSort (int *array, int left, int right) {
	if(left < right) {
		int pivot = partition(array,left,right);
		if ((pivot-1)>left)quickSort(array, left, pivot - 1);
		if (right>pivot+1)quickSort(array, pivot + 1, right);
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
	quickSort(array, 0, size-1);
	// export sorted array
	printf("*********END SORTING*********\n");
	exportArray(array,size);
	return 0;
}
