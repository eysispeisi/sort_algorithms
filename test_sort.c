#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "sort.c"

void printarr(int arr[], size_t s);
void populate(int arr[], int lo, int hi);
void shuffle(int arr[], int lo, int hi);
int isSorted(int arr[], int lo, int hi);
void testSort(const char *name, void (*sortFunc)(int*, int, int), int arr[], size_t size);
void runTests();


void printarr(int arr[], size_t s) {
	printf("{");
	for (int i=0; i<s; i++)
		printf("%d, ", arr[i]);
	printf("\b\b}\n");
}

void populate(int arr[], int lo, int hi) {
	time_t r;
	srand((unsigned) time(&r));
	for (int i=lo; i<hi; i++)
		arr[i] = rand()%hi;
}

void shuffle(int arr[], int lo, int hi) {
	int a, b, tmp;
	time_t r;
	srand((unsigned) time(&r));
	for (int i=lo; i < ((hi-lo)*2); i++) {
		a = (rand()%(1+hi-lo))+lo;
		b = (rand()%(1+hi-lo))+lo;
		if (a!=b) {
			SWAP(tmp, &arr[a], &arr[b]);
		}
	}
}

int isSorted(int arr[], int lo, int hi) {
	for (int i=lo; i < hi; i++)
		if (arr[i] > arr[i+1])
			return 0;
	return 1;
}


void testSort(const char *name, void (*sortFunc)(int*, int, int), int arr[], size_t size) {
	printf("test: %s: ", name);
	clock_t start_t, end_t, total_t;
	int arr2[size];
	memcpy(arr2, arr, size*sizeof(int));
	start_t = clock();
	sortFunc(arr2, 0, size-1);
	end_t = clock();
	total_t = end_t - start_t;
	printf("time: %d", total_t);
	if (isSorted(arr2, 0, size-1))
		printf(", PASS");
	else
		printf(", FAIL");
	printf("\n");
	//printarr(arr2, size);
}

typedef struct {
	const char * name;
	void (*func)(int*, int, int);
	int *arr;
	int arr_size;
} test_case;

int *reverseArray(int *arr, size_t size) {
}

void runTests() {
	//create original array of size arrSize
	int arrSize = 1000;
	int arr[arrSize];
	for (int i=0; i<arrSize; i++)
		arr[i] = i;
	//populate(arr, 0, arrSize-1);
	shuffle(arr, 0, arrSize-1);
	int arr2[arrSize];
	printf("Unsorted:\n");
	printf("Array size: %d\n", arrSize);
	//printarr(arr, arrSize);
	printf("\n");


	testSort("mergeSort", &mergeSort, arr, arrSize);
	testSort("bubbleSort", &bubbleSort, arr, arrSize);
	testSort("quickSort", &quickSort, arr, arrSize);
	testSort("heapSort", &heapSort, arr, arrSize);

}


int main() {
	runTests();
	return 0;
}