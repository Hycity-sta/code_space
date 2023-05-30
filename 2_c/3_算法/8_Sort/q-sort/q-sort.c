#include <stdio.h>

// 交换两个变量的值
void swap(int * a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void show(int * a, int total) {
	for (int i = 0; i < total; i++) {
		printf("%d ", a[i]);
	}
}

// 获取三个数的中位数
int median_of_three(int arr[], int left, int right) {
	int mid = (left + right) / 2;
	int first = arr[left];
	int last = arr[right];
	int middle = arr[mid];
    
	if ((first <= middle && middle <= last) || (last <= middle && middle <= first)) {
		return middle;
	} else if ((middle <= first && first <= last) || (last <= first && first <= middle)) {
		return first;
	} else {
		return last;
	}
}

// 快速排序实现函数
void quick_sort(int arr[], int L, int H) {
	if (L >= H) {
		return;
	} else {
		// 选取基准点
		int pivot = median_of_three(arr, L, H);
        
		// 将数组分为两部分，左边部分小于基准点，右边部分大于基准点
		int i = L, j = H;
		while (i <= j) {
			while (arr[i] < pivot) {
				i++;
			}
			while (arr[j] > pivot) {
				j--;
			}
			if (i <= j) {
				swap(&arr[i], &arr[j]);
				i++;
				j--;
			}
		}
		// 递归排序左半部分和右半部分
		quick_sort(arr, L, j);
		quick_sort(arr, i, H);
	}
}

// 测试函数
int main() {
	int arr[] = {5, 3, 6, 2, 7, 1, 4, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
    
	printf("before: ");
	show(arr, n);
    
	quick_sort(arr, 0, n - 1);
    
	printf("\nafter: ");
	show(arr, n);
	return 0;
}
