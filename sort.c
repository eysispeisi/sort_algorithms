#include "sort.h"

/*
Bubble sort, sometimes referred to as sinking sort
Although the algorithm is simple, it is too slow and impractical for most problems.
It can be practical if the input is usually in sorted order but may occasionally
have some out-of-order elements nearly in position.
*/
void bubbleSort(int items[], int lo, int hi) {
    bool stop = false;
    int tmp;
    while (!stop) {
        stop = true;
        for (int i=lo; i<hi; i++) {
            if (items[i] > items[i+1]) {
                SWAP(tmp, &items[i], &items[i+1]);
                if (stop)
                    stop = false;
            }
        }
    }
}


/*
Mergesort is a divide and conquer algorithm that was invented by John von Neumann
in 1945.
Produces a stable sort, which means that the implementation preserves the input
order of equal elements in the sorted output.
*/
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        // Merges two subarrays of arr[].
        // First subarray is arr[l..m]
        // Second subarray is arr[m+1..r]
        {
            int i, j, k;
            int n1 = m - l + 1;
            int n2 =  r - m;

            /* create temp arrays */
            int L[n1], R[n2];

            /* Copy data to temp arrays L[] and R[] */
            for (i = 0; i < n1; i++)
                L[i] = arr[l + i];
            for (j = 0; j < n2; j++)
                R[j] = arr[m + 1+ j];

            /* Merge the temp arrays back into arr[l..r]*/
            i = 0; // Initial index of first subarray
            j = 0; // Initial index of second subarray
            k = l; // Initial index of merged subarray
            while (i < n1 && j < n2)
            {
                if (L[i] <= R[j])
                    arr[k] = L[i++];
                else
                    arr[k] = R[j++];
                k++;
            }

            /* Copy the remaining elements of L[], if there
               are any */
            while (i < n1)
                arr[k++] = L[i++];

            /* Copy the remaining elements of R[], if there
               are any */
            while (j < n2)
                arr[k++] = R[j++];
        }
    }
}

/*
Quicksort (sometimes called partition-exchange sort)
Developed by Tony Hoare in 1959
It can be about two or three times faster than its main competitors,
merge sort and heapsort.
*/
void quickSort(int arr[], int lo, int hi) {
    if (lo < hi)
    {
        int tmp;
        int pivot = arr[hi];
        int i_lo = lo;
        int i_hi = hi-1;
        while (1) {
            while (i_lo < i_hi && arr[i_lo] <= pivot)
                i_lo++;
            while (i_lo < i_hi && pivot <= arr[i_hi])
                i_hi--;
            if (i_lo >= i_hi)
                break;
            SWAP(tmp, &arr[i_lo], &arr[i_hi]);
        }
        if (i_lo < hi && arr[i_lo] > arr[hi] )
            SWAP(tmp, &arr[hi], &arr[i_lo]);

        quickSort(arr, lo, i_lo);
        quickSort(arr, i_lo+1, hi);
    }
}


/*
Heapsort is a comparison-based sorting algorithm.
Heapsort can be thought of as an improved selection sort: like that algorithm, it divides
its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted
region by extracting the largest element and moving that to the sorted region. The
improvement consists of the use of a heap data structure rather than a linear-time search
to find the maximum.
Heapsort was invented by J. W. J. Williams in 1964.
*/
void heapSort(int arr[], int lo, int hi) {
    int parent, n1, n2, swap;
    int node = hi;
    // prime heap
    for (int i=lo; i<hi; i++){
        node = i;
        parent = (node-1)/2;
        while (node > 0) {
            if (arr[node] >= arr[parent]) {
                SWAP(swap, &arr[node], &arr[parent]);
                node = parent;
                parent = (node-1)/2;
            } else
                break;
        }
    }
    // sort heap
    int last = hi;
    while (last > lo) {
        SWAP(swap, &arr[lo], &arr[last]);
        last--;
        node = lo;
        n1 = node*2+1;
        n2 = n1+1;
        while (n1 < last && n1 > 0) {
            if (arr[n2] >= arr[n1] && arr[n2] > arr[node]) {
                SWAP(swap, &arr[n2], &arr[node]);
                node = n2;
            } else if (arr[n1] > arr[n2] && arr[n1] > arr[node]) {
                SWAP(swap, &arr[n1], &arr[node]);
                node = n1;
            } else
                break;
            n1 = node*2+1;
            n2 = n1+1;
        }
    }
    if (arr[lo] > arr[lo+1])
        SWAP(swap, &arr[lo], &arr[lo+1]);
    if (arr[hi-1] > arr[hi])
        SWAP(swap, &arr[hi-1], &arr[hi]);
}

