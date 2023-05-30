/*
 * 这里的数组是从0开始的, 所以在某些运算上会做一些处理
 * 这里的最大堆的序列都是按照中序遍历的顺序进行排列的
 * 这里还没有实现排序
 * 这里是用结构体的方式实现的,与纯数组的实现方式有一些区别
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_HEAP_SIZE 100

// 定义最大堆结构体
typedef struct {
	int * data;  // 存储堆中的元素
	int size;    // 堆内元素的个数
	int capacity;// 堆的容量
} MaxHeap;


MaxHeap * createMaxHeap(int max_size);
int parent(int i);
int leftChild(int i);
int rightChild(int i);
void shiftUp(MaxHeap * heap, int i);
void shiftDown(MaxHeap * heap, int i);
void insert(MaxHeap * heap, int value);
int delete (MaxHeap * heap);
void printMaxHeap(MaxHeap * heap);


int main() {
	MaxHeap * heap = createMaxHeap(MAX_HEAP_SIZE);
	// 向堆中插入元素

	int arr[] = {10,5,20,8,15,30,2};
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i=0; i<n; i++) {
		insert(heap, arr[i]);
	}
	printMaxHeap(heap); // 打印当前堆中的元素
	int max = delete (heap); // 删除堆顶元素
	printf("Deleted element: %d\n", max);
	printMaxHeap(heap); // 再次打印当前堆中的元素
	insert(heap, 25); // 向堆中插入一个新元素
	printMaxHeap(heap); // 再次打印当前堆中的元素

	return 0;
}


// 创建空的最大堆
// 传入最大堆的最大容量
// 返回一个MaxHeap类型的指针
MaxHeap * createMaxHeap(int max_size) {
	MaxHeap * heap = (MaxHeap *)malloc(sizeof(MaxHeap));
	heap->data = (int *)malloc(sizeof(int) * max_size);
	heap->size = 0;
	heap->capacity = max_size;
	return heap;
}


// 获取父节点索引
// 传入当前节点的下标
// 返回父节点的下标
int parent(int i) {
	return (i - 1) / 2; //可以用i/2-1, 两者在这里是等价的, 因为int会向下取整, 抹除了两者之间的差异
}


// 获取左子节点索引
// 传入当前节点的下标
// 返回左子节点的下标
int leftChild(int i) {
	return 2 * i + 1;
}


// 获取右子节点索引
// 传入当前节点的下标
// 返回右子节点的下标
int rightChild(int i) {
	return 2 * i + 2;
}


// 上浮操作，将新插入的元素上浮到正确的位置
// 传入一个最大堆的地址, 以及当前需要操作的节点的下标
void shiftUp(MaxHeap * heap, int i) {
    bool a = heap->data[parent(i)] < heap->data[i];
	while (i > 0 && a) {
		// 如果当前节点的父节点小于当前节点，则交换这两个位置的值
		int temp = heap->data[parent(i)];
		heap->data[parent(i)] = heap->data[i];
		heap->data[i] = temp;
		i = parent(i);  // 更新索引
	}
}


// 下沉操作，将根节点下沉到正确的位置
void shiftDown(MaxHeap * heap, int i) {
	int maxIndex = i;
	int l_index = leftChild(i);
	int r_index = rightChild(i);

	// 找到当前节点、左子节点和右子节点中最大的一个
	if (l_index < heap->size && heap->data[l_index] > heap->data[maxIndex]) {
		maxIndex = l_index;
	}
	if (r_index < heap->size && heap->data[r_index] > heap->data[maxIndex]) {
		maxIndex = r_index;
	}

	if (i != maxIndex) {
		// 如果当前节点不是最大的，则交换这两个位置的值
		int temp = heap->data[i];
		heap->data[i] = heap->data[maxIndex];
		heap->data[maxIndex] = temp;
		shiftDown(heap, maxIndex); // 继续向下递归进行下沉操作
	}
}


// 将元素插入到堆中
void insert(MaxHeap * heap, int value) {
	if (heap->size == heap->capacity) {
		printf("Error: Heap is full\n");
		return;
	}

	heap->data[heap->size] = value;  // 将元素插入数组尾部
	heap->size++;  // 堆大小加一
	shiftUp(heap, heap->size - 1);  // 将新插入的元素上浮到正确的位置
}


// 从堆中删除元素
int delete (MaxHeap * heap) {
	if (heap->size == 0) {
		printf("Error: Heap is empty\n");
		return -1;
	}

	int max = heap->data[0];  // 取出堆顶元素
	heap->data[0] = heap->data[heap->size - 1];  // 将最后一个元素移动到堆顶
	heap->size--;  // 堆大小减一
	shiftDown(heap, 0);  // 将新的堆顶元素下沉到正确的位置
	return max;
}


// 打印堆中的所有元素
void printMaxHeap(MaxHeap * heap) {
	printf("Max Heap:\n");
	for (int i = 0; i < heap->size; i++) {
		printf("%d ", heap->data[i]);
	}
	printf("\n");
}
