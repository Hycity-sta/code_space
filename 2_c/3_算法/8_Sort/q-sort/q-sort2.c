#include <stdio.h>

void show(int * arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

void detail(int *arr, int n,int a,int b, int c, int d) {
    show(arr,n);
    printf("\n");
    printf("\n");
}

// 交换两个元素的位置
void swap(int * a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


int findPiv(int arr[], int low, int high,int total) {
	int pivot = arr[high];     // 将数组最后一个元素作为基准数
	int i = low - 1;           // 定义 i 指针，并将其指向第一个元素的前一个位置

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
            printf("\nhave swap!: ");
            show(arr,total);
            printf("\n");
		}
	}

	swap(&arr[i + 1], &arr[high]); // 将基准数放到正确的位置上
    
    printf("\n\ndon't swap!: ");
    show(arr,total);
    
	return i + 1;                 // 返回分区点的位置
}

void quickSort(int arr[], int low, int high,int total) {

	if (low < high) {                      // 只有在 low < high 的情况下才需要排序
		int p = findPiv(arr, low, high,total); // 对数组进行分区，并获取分区点的位置
		quickSort(arr, low, p - 1,total);        // 对左边子数组进行递归排序
		quickSort(arr, p + 1, high,total);       // 对右边子数组进行递归排序
	}
    
    printf("\n");
    printf("\nafter deal:");
    show(arr,total);
}





int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

	printf("before array: ");
	show(arr, n);
	quickSort(arr, 0, n - 1,n);
	printf("\nSorted array: ");
	show(arr, n);


	return 0;
}
