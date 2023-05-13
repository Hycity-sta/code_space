#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100 // 定义数组最大长度为100

// 定义顺序表结构体
typedef struct {
	int data[MAXSIZE]; // 数据存储数组
	int length; // 当前元素个数
} SqList;

// 初始化顺序表
void InitList(SqList * L) {
	L->length = 0; // 将当前元素个数置为0
}

// 销毁顺序表
void DestroyList(SqList * L) {
	L->length = 0; // 将当前元素个数置为0
}

// 清空顺序表
void ClearList(SqList * L) {
	L->length = 0; // 将当前元素个数置为0
}

// 判断顺序表是否为空
bool ListEmpty(SqList L) {
	return L.length == 0; // 返回当前元素个数是否为0
}

// 获取顺序表中元素个数
int ListLength(SqList L) {
	return L.length; // 返回当前元素个数
}

// 获取顺序表中指定位置的元素
bool GetElem(SqList L, int i, int * e) {
	if (i < 1 || i > L.length)
		return false; // 如果i超出范围，则返回false
	*e = L.data[i - 1]; // 获取指定位置的元素值
	return true; // 操作成功，返回true
}

// 查找顺序表中第一个匹配的元素位置
int LocateElem(SqList L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e)
			return i + 1; // 返回匹配的元素位置
	}
	return 0; // 没有匹配的元素，返回0
}

// 获取指定元素的前驱元素值
bool PriorElem(SqList L, int cur_e, int * pre_e) {
	int i;
	for (i = 1; i < L.length; i++) {
		if (L.data[i] == cur_e) {
			*pre_e = L.data[i - 1]; // 将前驱元素值赋给pre_e参数
			return true; // 操作成功，返回true
		}
	}
	return false; // 在顺序表中没有找到当前元素，返回false
}

// 获取指定元素的后继元素值
bool NextElem(SqList L, int cur_e, int * next_e) {
	int i;
	for (i = 0; i < L.length - 1; i++) {
		if (L.data[i] == cur_e) {
			*next_e = L.data[i + 1]; // 将后继元素值赋给next_e参数
			return true; // 操作成功，返回true
		}
	}
	return false; // 在顺序表中没有找到当前元素，返回false
}

// 在指定位置插入元素
bool ListInsert(SqList * L, int i, int e) {
	if (i < 1 || i > L->length + 1)
		return false; // 如果i超出范围，则返回false
	if (L->length >= MAXSIZE)
		return false; // 如果数组已满，则返回false
	for (int j = L->length; j >= i; j--)
		L->data[j] = L->data[j - 1]; // 将元素后移，腾出插入位置
	L->data[i - 1] = e; // 在指定位置插入元素
	L->length++; // 元素个数加1
	return true; // 操作成功，返回true
}

// 删除指定位置的元素
bool ListDelete(SqList * L, int i, int * e) {
	if (i < 1 || i > L->length)
		return false; // 如果i超出范围，则返回false
	*e = L->data[i - 1]; // 获取被删除的元素值
	for (int j = i; j < L->length; j++)
		L->data[j - 1] = L->data[j]; // 将元素前移，覆盖被删除的元素
	L->length--; // 元素个数减1
	return true; // 操作成功，返回true
}

// 遍历顺序表中的所有元素，并对每个元素执行visit函数
void ListTraverse(SqList L, void (*visit)(int)) {
	for (int i = 0; i < L.length; i++)
		visit(L.data[i]); // 对每个元素执行visit函数
}

// 访问元素时调用的自定义函数
void Visit(int e) {
	printf("%d ", e); // 输出元素值
}


int main() {
	SqList L;
	int e = 0, pre_e = 0, next_e = 0;

	InitList(&L);

	printf("ListEmpty: %d\n", ListEmpty(L)); // 输出1，表示L为空表
	printf("ListLength: %d\n", ListLength(L)); // 输出0，表示L的长度为0

	ListInsert(&L, 1, 5);
	ListInsert(&L, 2, 7);
	ListInsert(&L, 3, 3);

	ListTraverse(L, Visit); // 输出5 7 3
	printf("\n");

	GetElem(L, 2, &e);
	printf("GetElem: %d\n", e); // 输出7

	LocateElem(L, 7);
	printf("LocateElem: %d\n", LocateElem(L, 7)); // 输出2

	PriorElem(L, 7, &pre_e);
	printf("PriorElem: %d\n", pre_e); // 输出5

	NextElem(L, 7, &next_e);
	printf("NextElem: %d\n", next_e); // 输出3

	ListDelete(&L, 2, &e);
	ListTraverse(L, Visit); // 输出5 3
	printf("\n");

	ClearList(&L);
	printf("ListEmpty: %d\n", ListEmpty(L)); // 输出1，表示L为空表

	return 0;
}
