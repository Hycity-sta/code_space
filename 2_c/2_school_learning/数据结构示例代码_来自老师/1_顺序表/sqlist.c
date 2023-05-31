#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -1
#define MAXSIZE 100

typedef int Position;
typedef struct LNode * PtrToLNode;
typedef int ElementType;



struct LNode {
	ElementType Data[MAXSIZE];
	Position Last;
};
typedef PtrToLNode List;


List MakeEmpty();
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, int i );
bool Delete( List L, int i );

int main( ) {
	printf("新建顺序表\n");
	List l = MakeEmpty();
	
	ElementType x = 1;
	Position p = 1;
	
	for (int i = 0; i < 3; i++) Insert(l, x + i, p + i); //不断地在最后插入元素
	
	//打印顺序表内容
	for (int i = 0; i <= l->Last; i++) {
		printf("%d ", l->Data[i]);
	}
	printf("顺序表打印完毕\n");
	
	//插入指定位置、
	printf("在顺序表第1个位置（下标为0）插入0，然后打印顺序表\n");
	Insert(l, 0, 1);
	
	//打印顺序表内容
	for (int i = 0; i <= l->Last; i++) {
		printf("%d ", l->Data[i]);
	}
	printf("顺序表打印完毕\n");
	
	//查找
	x = 3;
	p = Find(l, x);
	if (p != ERROR) printf("顺序表中下标 %d,有元素 %d \n", p, x);
	else printf("顺序表中没有元素 %d \n", x);
	
	//删除
	printf("从顺序表中删除位序%d 的元素,该元素数组下标为%d-1\n", x, x);
	Delete(l, x);
	
	//打印顺序表内容
	for (int i = 0; i <= l->Last; i++) {
		printf("%d ", l->Data[i]);
	}
	printf("顺序表打印完毕\n");
	
	return 0;
}

//创建一个空的顺序表
List MakeEmpty() {
	List L;

	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;

	return L;
}

//找一个元素x
Position Find( List L, ElementType X ) {
	Position i = 0;

	while ( i <= L->Last && L->Data[i] != X )
		i++;
	if ( i > L->Last )  return ERROR; /* 如果没找到，返回错误信息 */
	else  return i;  /* 找到后返回的是存储位置 */
}

//在一个确定的位置插入一个确定的元素
bool Insert( List L, ElementType X, int i ) {
	/* 在L的指定位序i前插入一个新元素X;位序i元素的数组位置下标是i-1 */
	Position j;

	if ( L->Last == MAXSIZE - 1) {
		/* 表空间已满，不能插入 */
		printf("表满");
		return false;
	}
	if ( i < 1 || i > L->Last + 2 ) {
		/* 检查插入位序的合法性：是否在1~n+1。n为当前元素个数，即Last+1 */
		printf("位序不合法");
		return false;
	}
	for ( j = L->Last; j >= i - 1; j-- ) /*Last指向序列最后元素 */
		L->Data[j + 1] = L->Data[j]; /* 将位序i及以后的元素顺序向后移动 */
	L->Data[i - 1] = X; /* 新元素插入第i位序，其数组下标为i-1 */
	L->Last++;       /* Last仍指向最后元素 */
	return true;
}

//在一个确定的位置删除该位置的元素
bool Delete( List L, int i ) {
	/* 从L中删除指定位序i的元素,该元素数组下标为i-1 */
	Position j;

	if ( i < 1 || i > L->Last + 1 ) { /* 检查空表及删除位序的合法性 */
		printf("位序%d不存在元素", i );
		return false;
	}
	for ( j = i; j <= L->Last; j++ )
		L->Data[j - 1] = L->Data[j]; /*将位序i+1及以后的元素顺序向前移动*/
	L->Last--; /* Last仍指向最后元素 */
	return true;
}
