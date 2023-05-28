#include <stdio.h>
//选择排序
void selectionSort(int arr[], int n);

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

/* int arr[]: 数组
 * int n: 数组的大小
 * a是负责控制遍历的论数,之所以是n-1,是因为后面有个比较的过程
 * 在比较的过程里面,因为需要前后比较,所以a要比b小,所以b可以是最后一个,a就是b的前一个,也就是倒数第二个元素了
 * 这意味着,当a在倒数第二个元素开始,排序完成后,整个数组就已经排序完成了,不用再继续进行比较了
 */
void selectionSort(int arr[], int n) {
    int a, b, min_idx;

    for (a = 0; a < n-1; a++) {
        // 在未排序部分中找到最小元素
        min_idx = a;
        for (b = a+1; b<n; b++)
            if (arr[b]<arr[min_idx])
                min_idx = b;

        // 将找到的最小元素放到已排序部分的末尾
        int temp = arr[min_idx];
        arr[min_idx] = arr[a];
        arr[a] = temp;
    }
}

