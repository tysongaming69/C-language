
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, count = left, *l, *r;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Allocate memory for temp arrays
    l = (int*)malloc(n1 * sizeof(int));
    r = (int*)malloc(n2 * sizeof(int));

    // Check if memory allocation was successful
    if (l == NULL || r == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Copy data to temp arrays l[] and r[]
    for (i = 0; i < n1; i++){
        l[i] = arr[left + i];
        }
    for (j = 0; j < n2; j++){
        r[j] = arr[mid + 1 + j];
        }

    // Merge the temp arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            arr[count] = l[i];
            i++;
        } else {
            arr[count] = r[j];
            j++;
        }
        count++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[count] = l[i];
        i++;
        count++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[count] = r[j];
        j++;
        count++;
    }

    // Free the allocated memory
    free(l);
    free(r);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Driver code
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
