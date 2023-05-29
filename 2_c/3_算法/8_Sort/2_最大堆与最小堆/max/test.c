#include <stdlib.h>

#include <stdio.h>

void PercDown(int *, int, int );
void Swap(int *, int *);
void HeapSort(int *, int);

int main(int argc, char * argv[]) {
	system("chcp 65001");
	int a[] = {2, 4, 1, 20, 534, 23, 22};
	int n = sizeof(a) / sizeof(a[0]);

	printf("无序数组为:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	HeapSort(a, n);

	printf("\n排序之后:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}


//下沉操作
void PercDown(int arr[], int root_in, int total) {
	int Par_in, Ch_in;
	int t;

	t = arr[root_in];

	for (Par_in = root_in; (Par_in * 2 + 1) < total; Par_in = Ch_in) {
		Ch_in = Par_in * 2 + 1;
		if ( (Ch_in != total - 1) && (arr[Ch_in] < arr[Ch_in + 1])) {
			Ch_in++;
		}
		if (t >= arr[Ch_in]) break;
		else arr[Par_in] = arr[Ch_in];
	}

	arr[Par_in] = t;
}


//交换两个元素的位置
void Swap(int * a, int * b) {
	int t = *a;
	*a = *b;
	*b = t;
}


//堆排序,该函数完成后数组为一个从小到大的有序序列
void HeapSort(int arr[], int total) {
    //将无序数组调整为最大堆
	for (int i = total / 2 - 1; i >= 0; i--) {
		PercDown(arr, i, total);
        
		printf("\n将无序调为最大堆的测试数据:\n");
		for (int i = 0; i < total; i++) {
			printf("%d ", arr[i]);
		}
	}
    
    printf("\n");

    //将最大堆中的最大元素不断输出,从最后一个开始
	for (int i = total - 1; i > 0; i--) {
		Swap(&arr[0], &arr[i]);
		printf("\n交换后的状态测试数据:\n");
		for (int i = 0; i < total; i++) {
			printf("%d ", arr[i]);
		}
		PercDown(arr, 0, i);
		printf("\n交换后调整为最大堆测试数据:\n");
		for (int i = 0; i < total; i++) {
			printf("%d ", arr[i]);
		}
        printf("\n");
	}
}
