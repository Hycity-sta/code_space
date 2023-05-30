#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int Median3(int *, int, int);
void quicksort(int *, int, int);
void swap(int *, int *);
void show(int *, int);

int main(int argc, char * argv[]) {
	int arr[] = {23, 45, 12, 89, 23, 45, 73, 92, 10, 34, 23, 12, 34,23,12,9,5,34,54,756,223,2,2,2,2,2,2,2,2,2,2};
	int total = sizeof(arr) / sizeof(arr[0]);
	printf("before: ");
	show(arr, total);
	quicksort(arr, 0, total - 1);
	printf("\nlater: ");
	show(arr, total);
	return 0;
}

int Median3(int *arr, int left, int right) {
	int center = (left + right) / 2;

	if (arr[left] > arr[center]) {
        int m = arr[left];
        arr[left] = arr[center];
        arr[center] = m;
    }
    
	if (arr[left] > arr[right]) {
        int m = arr[left];
        arr[left] = arr[right];
        arr[right] = m;
    }
    
	if (arr[center] > arr[right]) {
        int m = arr[center];
        arr[center] = arr[right];
        arr[right] = m;
    }

    int m = arr[center];
    arr[center] = arr[right-1];
    arr[right-1] = m;

	return arr[right - 1];
}

void quicksort(int *arr, int Lindex, int Rindex) {
	int Pivot, Cutoff, Low, High;

	if (Cutoff <= Rindex - Lindex) {
		Pivot = Median3(arr, Lindex, Rindex);
		Low = Lindex;
		High = Rindex - 1;

		while (1) {
			while (arr[++Low] < Pivot);
			while (arr[--High] > Pivot);
			if (Low < High) swap(&arr[Low], &arr[High]);
			else break;
		}

        int m = arr[Low];
        arr[Low]=arr[Rindex-1];
        arr[Rindex-1] = m;

		quicksort(arr, Lindex, Low - 1);
		quicksort(arr, Low + 1, Rindex);
	} else printf("too few");
}

void swap(int * a, int * b) {
	int m = *a;
	*a = *b;
	*b = m;
}

void show(int * arr, int total) {
	for (int i = 0; i < total; i++) printf("%d ", arr[i]);
}
