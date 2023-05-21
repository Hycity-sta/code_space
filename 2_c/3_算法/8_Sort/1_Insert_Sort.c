#include <stdio.h>

void insertion_sort(int arr[], int n);

int main() {
    int arr[] = {10,20,70,50,40,30,20,70,34,90,21,58};

    /* 下面这一行代码是在计算数组中元素的个数 用于确定数组的长度
     * 其中 sizeof(arr) 计算整个数组占用的内存空间大小（以字节为单位)
     * sizeof(arr[0]) 是计算数组中单个元素的内存空间大小。将它们相除即可得到数组中元素的个数
     * 这种方法通常用于在不知道数组具体元素个数的情况下统计数组长度
     */
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Before Sorted array: ");
    for (int i = 0; i<n; i++)
        printf("%d ", arr[i]);
    
    insertion_sort(arr, n);
    
    printf("\nAfter Sorted array: ");
    for (int i = 0; i<n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}

// int arr[]为数组
// int n为数组的长度
void insertion_sort(int arr[], int n) {
    int a, key, b;
    
    for (a= 1; a<n; a++) {
        key = arr[a];
        b = a - 1;
        
        while (b>=0 && arr[b]>key) {
            arr[b+1] = arr[b];
            b = b-1;
        }
        
        arr[b+1] = key;
    }
}
