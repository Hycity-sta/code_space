#include <stdio.h>
#define MaxSize 100
typedef struct {
	int data[MaxSize];
	int length;		
}SeqList;

/**
 * 在第location个位置插入元素elem
 * @param L        顺序表
 * @param location 插入的位置
 * @param elem     插入的元素
 */	
int Insert_SeqList(SeqList &L, int location, int elem) {
	if (location<1 || location>L.length+1 || L.length>=MaxSize)
	{
		return 0;
	}
	for (int i = L.length; i >= location; --i)
	{
		L.data[i] = L.data[i-1];
	}
	L.data[location - 1] = elem;
	L.length++;
	return 1;
}

/**
 * 合并两个顺序表，组成新的顺序表
 * @param La       待合并顺序表
 * @param Lb       待合并顺序表
 * @param Lc       合并后的顺序表
 */
void MergeList(SeqList La, SeqList Lb, SeqList &Lc) {
	Init_SeqList(Lc);
	int i,j,k;
	i = j = 0;
	k = 1;
	while((i<La.length) && (j<Lb.length)) {
		if (La.data[i] < Lb.data[j])
		{
			Insert_SeqList(Lc, k++, La.data[i++]);
		}
		else {
			Insert_SeqList(Lc, k++, Lb.data[j++]);
		}
	}
	while(i<La.length) {
		Insert_SeqList(Lc, k++, La.data[i++]);
	}
	while(j<Lb.length) {
		Insert_SeqList(Lc, k++, Lb.data[j++]);
	}
}
