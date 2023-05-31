#include <stdio.h>

void quicksort(int[], int, int);
int partition(int[], int, int);

void show(int*);

int main()
{
    int arr[] = {35,25,15,45,80,75,20,40,36,70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Initial array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high) {
        int pivot_index = partition(arr, low, high);

        printf("After partition %d: ", pivot_index);
        for (int i = low; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int temp;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

