#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR NULL

typedef struct LNode * PtrToLNode;
typedef int ElementType;

struct LNode {
	ElementType Data;//存放数据
	PtrToLNode Next;//指向下一个结点
};
typedef PtrToLNode Position;//链表的位置是结点的地址
typedef PtrToLNode List;//用List定义表头指针


//L没有头结点,返回线性表L的长度n 3.5
int Length( List L );
//L有头结点,返回线性表L的长度(实际元素个数)n 3.5
int Length_H( List L );
//初始化一个新的不带头结点的空线性表L；
List MakeEmpty();
//初始化一个新的带头结点的空线性表L；
List MakeEmpty_H();
//L没有头结点,根据指定的位序i(位序从1开始)，返回相应元素 ；3.6
ElementType FindKth(List L, int i );
//L有头结点,根据指定的位序i(位序从1开始)，返回相应元素 ；
ElementType FindKth_H(List L, int i );
//已知X，返回线性表L中与X相同的第一个元素的相应地址；若不存在则返回空；
Position Find( List L, ElementType X );
//L带头节点，指定位序i前插入一个新元素X；成功则返回true，否则返回false；3.9
bool Insert_H(List L, ElementType X, int i);
//L带头节点，删除指定位序i的元素；成功则返回true，否则返回false；3.10
bool Delete_H(List L, int  i);


int main( ) {
	printf("新建带头节点的链表\n");
	List l = MakeEmpty_H();
	ElementType x = 0;
	int n = 0; //链表长度
	
	for (int i = 1; i < 4; i++) {
		Insert_H(l, x + i, i); //不断地在最后插入元素
		n = Length_H( l );
		printf("当前链表长度为 %d\n", n);
	}
	
	//打印链表内容
	Position p = l->Next; //p指向第一个结点
	while (p) {
		printf("%d ", p->Data);
		p = p -> Next;
	}
	printf("链表打印完毕\n");

	//插入指定位置、
	printf("在链表第1个位置插入0，然后打印链表\n");
	Insert_H(l, 0, 1);

	//打印链表内容
	p = l->Next; //p指向第一个结点
	while (p) {
		printf("%d ", p->Data);
		p = p -> Next;
	}
	printf("链表打印完毕\n");

	//查找
	//根据指定的位序i，返回相应元素
	int k = 3;
	x = FindKth_H(l, k);
	if (x != -1)
		printf("链表中第 %d 个节点的元素为 %d \n", k, x);
	else
		printf("链表中没有第 %d 个节点\n", k);

	//返回链表l中与x相同的第一个元素的相应位序
	x = 2;
	Position pt = Find(l->Next, x); //l为头节点，l->Next是第一个节点
	if (pt) {
		p = l->Next; //p指向第一个结点
		int cnt = 1;
		while (p != pt) {
			cnt++;
			p = p -> Next;

		}
		printf("链表中第一次出现元素为 %d 的节点位序是 %d\n", x, cnt);
	} else
		printf("链表中没有元素为 %d 的节点\n", x);

	//删除
	printf("从链表中删除节点位序为 %d 的元素,该元素为%d\n", k, FindKth(l->Next, k));
	Delete_H(l, k);
	//打印链表内容
	p = l->Next; //p指向第一个结点
	while (p) {
		printf("%d ", p->Data);
		p = p -> Next;
	}
	printf("链表打印完毕\n");

	return 0;
}

//初始化一个新的带头结点的空线性表L；
List MakeEmpty_H() {
	List L;

	L = (List)malloc(sizeof(struct LNode));
	L->Next = NULL;

	return L;
}

//初始化一个新的不带头结点的空线性表L；
List MakeEmpty() {
	List L = NULL;
	return L;
}

bool Delete_H( List L, int i ) {
	/* 这里默认L有头结点 */
	Position tmp, pre;
	int cnt = 0;

	/* 查找位序为i-1的结点 */
	pre = L;      /* pre指向表头 */
	while ( pre && cnt < i - 1 ) {
		pre = pre->Next;
		cnt++;
	}
	if ( pre == NULL || cnt != i - 1 || pre->Next == NULL) {
		/* 所找结点或位序为i的结点不在L中 */
		printf("插入位置参数错误\n");
		return false;
	} else { /* 找到了待删结点的前一个结点pre */
		/* 将结点删除 */
		tmp = pre->Next;
		pre->Next = tmp->Next;
		free(tmp);
		return true;
	}
}

//L没有头结点，返回线性表L的长度n
int Length( List L ) {
	Position p;
	int cnt = 0; /* 初始化计数器 */

	p = L;  /* p指向表的第一个结点 */
	while ( p ) {
		p = p->Next;
		cnt++; /* 当前p指向的是第cnt个结点*/
	}

	return cnt;
}

//L有头结点，返回线性表L的长度(实际元素个数)n
int Length_H( List L ) {
	Length(L->Next); //l为头节点，l->Next是第一个节点
}

//L没有头结点,根据指定的位序i(位序从1开始)，返回相应元素 ；3.6
ElementType FindKth( List L, int K ) {
	/* 根据指定的位序K，返回L中相应元素 */
	Position p;
	int cnt = 1; /* 位序从1开始 */

	p = L; /* p指向L的第1个结点 */
	while ( p && cnt < K ) {
		p = p->Next;
		cnt++;
	}
	if ( (cnt == K) && p )
		return p->Data; /* 找到第K个 */
	else
		return EOF;   /* 否则返回错误信息 */
}

//L有头结点,根据指定的位序i(位序从1开始)，返回相应元素 ；
ElementType FindKth_H(List L, int i ) {
	return FindKth( L->Next, i); //l为头节点，l->Next是第一个节点
}


Position Find( List L, ElementType X ) {
	Position p = L; /* p指向L的第1个结点 */

	while ( p && p->Data != X )
		p = p->Next;

	/* 下列语句可以用 return p; 替换 */
	if ( p )
		return p;
	else
		return ERROR;
}

List Insert( List L, ElementType X, int i ) {
	Position tmp, pre;

	tmp = (Position)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
	tmp->Data = X;
	if ( i == 1 ) { /* 新结点插入在表头 */
		tmp->Next = L;
		return tmp; /* 返回新表头指针 */
	} else {
		/* 查找位序为i-1的结点 */
		int cnt = 1;  /* 位序从1开始 */
		pre = L;      /* pre指向L的第1个结点 */
		while ( pre && cnt < i - 1 ) {
			pre = pre->Next;
			cnt++;
		}
		if ( pre == NULL || cnt != i - 1) { /* 所找结点不在L中 */
			printf("插入位置参数错误\n");
			free(tmp);
			return ERROR;
		} else { /* 找到了待插结点的前一个结点pre */
			/* 插入新结点，并且返回表头L */
			tmp->Next = pre->Next;
			pre->Next = tmp;
			return L;
		}
	}
}


bool Insert_H( List L, ElementType X, int i ) {
	/* 这里默认L有头结点 */
	Position tmp, pre;
	int cnt = 0;

	/* 查找位序为i-1的结点 */
	pre = L;      /* pre指向表头 */
	while ( pre && cnt < i - 1 ) {
		pre = pre->Next;
		cnt++;
	}
	if ( pre == NULL || cnt != i - 1) { /* 所找结点不在L中 */
		printf("插入位置参数错误\n");
		return false;
	} else { /* 找到了待插结点的前一个结点pre；若i为1，pre就指向表头 */
		/* 插入新结点 */
		tmp = (Position)malloc(sizeof(struct LNode)); /*申请、填装结点*/
		tmp->Data = X;
		tmp->Next = pre->Next;
		pre->Next = tmp;
		return true;
	}
}



