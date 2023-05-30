#include <stdlib.h>

#include <stdio.h>

void PercDown(int *, int, int );
void Swap(int *, int *);
void HeapSort(int *, int);
void arrtoString(int *, int);

int main(int argc, char * argv[]) {
	system("chcp 65001");
	int a[] = {34, 48, 13, 20, 23, 22};
	int a_total = sizeof(a) / sizeof(a[0]);

	printf("无序数组为:\n");
    arrtoString(a,a_total);
    
	HeapSort(a, a_total);

	printf("\n排序之后:\n");
    arrtoString(a,a_total);

	return 0;
}


//下沉操作
//传入一个数组
//插入一个根的下标
//传这个数组里面一共有多少个元素
//操作将会对数组执行一次下沉操作,将root_in为下标的元素下沉到数组中正确的位置
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
        arrtoString(arr,total);
	}
    
    printf("\n");

    //将最大堆中的最大元素不断输出,从最后一个开始
	for (int i = total - 1; i > 0; i--) {
		Swap(&arr[0], &arr[i]);
        
		printf("\n交换后的状态测试数据:\n");
        arrtoString(arr,total);
        
		PercDown(arr, 0, i);
        
		printf("\n交换后调整为最大堆测试数据:\n");
        arrtoString(arr,total);
        
        printf("\n");
	}
}

//将一个数组打印出来
void arrtoString(int * arr,int total) {
    for (int i=0;i<total;i++) {
        printf("%d ", arr[i]);
    }
}

//将无序数组调整为最大堆
void beHeap(int arr[], int total) {
	for (int i = total / 2 - 1; i >= 0; i--) {
		PercDown(arr, i, total);
	}
}
