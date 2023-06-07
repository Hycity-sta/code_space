#include "Sqlist.h"

void initList(SqList * L) {
	L->length = 0;
}

void destroyList(SqList * L) {
	L->length = 0;
}

void clearList(SqList * L) {
	L->length = 0;
}

bool isEmpty(SqList L) {
	return (L.length == 0);
}

int getLength(SqList L) {
	return L.length;
}

// 获取顺序表中指定位置的元素
bool getElem(SqList L, int i, int * e) {
	if (i < 1 || i > L.length) return false; // i超出范围
	*e = L.data[i - 1];
	return true;
}

// 查找顺序表中第一个匹配的元素位置
int getElemLocate(SqList L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e)
			return i + 1; // 返回匹配的元素位置
	}
	return 0; // 没有匹配的元素，返回0
}

// 获取指定元素的前驱元素值
bool getPriorElem(SqList L, int cur_e, int * pre_e) {
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
bool getNextElem(SqList L, int cur_e, int * next_e) {
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
bool insertElem(SqList * L, int i, int e) {
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
bool delElem(SqList * L, int i, int * e) {
	if (i < 1 || i > L->length)
		return false; // 如果i超出范围，则返回false
	*e = L->data[i - 1]; // 获取被删除的元素值
	for (int j = i; j < L->length; j++)
		L->data[j - 1] = L->data[j]; // 将元素前移，覆盖被删除的元素
	L->length--; // 元素个数减1
	return true; // 操作成功，返回true
}

// 遍历顺序表中的所有元素，并对每个元素执行visit函数
void traverse(SqList L, void (*visit_)(int)) {
	for (int i = 0; i < L.length; i++)
		visit_(L.data[i]);
}

// 访问元素时调用的自定义函数
void visit(int e) {
	printf("%d ", e);
}
