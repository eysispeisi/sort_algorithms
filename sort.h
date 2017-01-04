#ifndef _SORT_H_
#define _SORT_H_

#include <stdbool.h>

/*
swapping macro, swaps values of <a> and <b>
usage: SWAP(<temp storage variable>, <address of a>, <address of b>);
example: SWAP(tmp, &array[0], &array[1]); // swaps value of array[0] with array[1]
*/
#define SWAP(tmp, a, b) { tmp = *a; *a = *b; *b = tmp; }

void bubbleSort(int items[], int lo, int hi);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int lo, int hi);
void heapSort(int arr[], int lo, int hi);


#endif