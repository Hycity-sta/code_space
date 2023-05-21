#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int a, b;
    for (a = 0; a<n-1; a++) {     
        for (b = 0; b <n-a-1; b++) {
            if (arr[b] > arr[b+1]) {
                int temp = arr[b];
                arr[b] = arr[b+1];
                arr[b+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Before Sorted array: \n");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n);

    printf("\n\nAfter Sorted array: \n");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
