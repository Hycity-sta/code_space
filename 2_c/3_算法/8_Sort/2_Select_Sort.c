#include <stdio.h>

void selectionSort(int arr[], int n) {
    int a, b, min_idx;

    for (a = 0; a < n-1; a++) {
        // 在未排序部分中找到最小元素
        min_idx = a;
        for (b = a+1; b < n; b++)
            if (arr[b] < arr[min_idx])
                min_idx = b;

        // 将找到的最小元素放到已排序部分的末尾
        int temp = arr[min_idx];
        arr[min_idx] = arr[a];
        arr[a] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Befort Sorted array: \n");
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    
    selectionSort(arr, n);
    
    printf("\n\nAfter Sorted array: \n");
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}
