#include <stdio.h>

//冒牌排序
void bubbleSort(int arr[], int n);

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);//这个是数组中元素的个数
    
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

// int arr[] 为数组
// int n 为数组的大小
 
/* 第一次循环是在为第二次循环的计算做准备
 * 因为冒泡排序执行一轮之后,在单轮参加排序的数字中,最大值已经排在了最后了
 * 所以下一轮就不需要对最大值与最大值前面的那个数字进行比较了
 * a是用来控制每一轮需要遍历的元素的变量,影响
 * b具体控制操作的次数
 */
void bubbleSort(int arr[], int n) {
    int a, b;
    for (a = 0; a<n-1; a++) {     
        for (b = 0; b <n-a-1; b++) { //在这一轮循环中需要遍历的元素个数为n-a-1
            //交换位置
            if (arr[b] > arr[b+1]) {
                int temp = arr[b];
                arr[b] = arr[b+1];
                arr[b+1] = temp;
            }
        }
        //执行完一轮了,a要++,然后下一轮遍历中,将减少遍历数组中的一个元素
    }
}

