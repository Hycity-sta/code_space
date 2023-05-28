// 这里是最小堆 以及最小堆的排序
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEAP_SIZE 100

// 最小堆结构体定义
typedef struct {
	int data[HEAP_SIZE];  // 用数组存储堆中元素
	int size;             // 堆中元素个数
} MinHeap;

// 初始化最小堆
void init_heap(MinHeap * heap) {
	heap->size = 0;
}

// 获取堆中最小的元素
int get_min(MinHeap * heap) {
	if (heap->size == 0) {
		printf("Error: Heap is empty.\n");
		return -1;
	}
	return heap->data[0];
}

// 插入新元素到堆中
void insert(MinHeap * heap, int value) {
	if (heap->size == HEAP_SIZE) {
		printf("Error: Heap is full.\n");
		return;
	}

	// 将新元素插入到堆底
	heap->data[heap->size] = value;
	heap->size++;

	// 自底向上调整堆，保持最小堆性质
	int i = heap->size - 1;
	while (i > 0 && heap->data[i] < heap->data[(i - 1) / 2]) {
		int temp = heap->data[i];
		heap->data[i] = heap->data[(i - 1) / 2];
		heap->data[(i - 1) / 2] = temp;
		i = (i - 1) / 2;
	}
}

// 删除堆中最小的元素
int extract_min(MinHeap * heap) {
	if (heap->size == 0) {
		printf("Error: Heap is empty.\n");
		return -1;
	}

	// 取出堆顶元素（最小值）
	int min_val = heap->data[0];

	// 将堆底元素移到堆顶，并将堆底元素删除
	heap->size--;
	heap->data[0] = heap->data[heap->size];

	// 自顶向下调整堆，保持最小堆性质
	int i = 0;
	while (i * 2 + 1 < heap->size) {
		int left = i * 2 + 1;   // 左子节点索引
		int right = i * 2 + 2;  // 右子节点索引
		int min_child = left;   // 子节点中键值较小的那个
		if (right < heap->size && heap->data[right] < heap->data[left]) {
			min_child = right;
		}
		if (heap->data[i] > heap->data[min_child]) {
			int temp = heap->data[i];
			heap->data[i] = heap->data[min_child];
			heap->data[min_child] = temp;
			i = min_child;
		} else {
			break;
		}
	}

	return min_val;
}

// 打印堆中的元素
void print_heap(MinHeap * heap) {
	printf("Heap (%d elements): ", heap->size);
	for (int i = 0; i < heap->size; i++) {
		printf("%d ", heap->data[i]);
	}
	printf("\n");
}

// 测试代码
int main() {
	MinHeap heap;
	init_heap(&heap);

	// 插入元素
	insert(&heap, 5);
	insert(&heap, 3);
	insert(&heap, 7);
	insert(&heap, 1);
	insert(&heap, 2);

	// 输出堆中元素
	print_heap(&heap);

	// 获取堆中最小的元素
	int min_val = get_min(&heap);
	printf("Min value: %d\n", min_val);

	// 删除堆中最小的元素
	int extracted_val = extract_min(&heap);
	printf("Extracted min value: %d\n", extracted_val);

	// 输出堆中元素
	print_heap(&heap);

	return 0;
}
