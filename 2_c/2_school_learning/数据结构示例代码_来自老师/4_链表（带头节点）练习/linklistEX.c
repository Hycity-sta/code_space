#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct LNode * PtrToLNode;
typedef int ElementType;

struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;


int Length( List L );//返回线性表L的长度n
List MakeEmpty();//初始化一个新的空线性表L；
ElementType FindKth(List L, int i );//根据指定的位序i，返回相应元素 ；
Position Find( List L, ElementType X );//已知X，返回线性表L中与X相同的第一个元素的相应位序i；若不存在则返回空；
bool Insert_H(List L, ElementType X, int i);//带头节点，指定位序i前插入一个新元素X；成功则返回true，否则返回false；
bool Delete(List L, int  i);//删除指定位序i的元素；成功则返回true，否则返回false；
int DelElem(List L, ElementType  X);//删除元素X所在的节点，成功返回0，失败返回-1
void merge(List a, List b, List ab); //合并有序链表a,b到ab中，保持有序


//合并有序链表 EX的意思就是在原来代码的基础上实现 合并 这个功能.
int main( ) {

	int i;
	int alen, blen;
	ElementType tmp;
	List a = MakeEmpty();
	List b = MakeEmpty();
	List ab = MakeEmpty();
	printf("输入链表a的元素个数\n");
	scanf("%d", &alen);
	printf("依次输入非递减有序链表a的元素：\n");
	for (i = 0; i < alen; i++) {
		scanf("%d", &tmp);
		Insert_H(a, tmp, i + 1);
	}

	//打印链表a内容
	Position p = a->Next;//p指向第一个结点
	while (p) {
		printf("%d ", p->Data);
		p = p -> Next;
	}
	printf("链表打印完毕\n");

	printf("输入链表b的元素个数\n");
	scanf("%d", &blen);
	printf("依次输入非递减有序链表b的元素：\n");
	for (i = 0; i < blen; i++) {
		scanf("%d", &tmp);
		Insert_H(b, tmp, i + 1);
	}

	//打印链表a内容
	p = b -> Next;//p指向第一个结点
	while (p) {
		printf("%d ", p->Data);
		p = p -> Next;
	}
	printf("链表打印完毕\n");
	//合并
	merge(a, b, ab);


	return 0;
}



bool Delete( List L, int i ) {
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


//返回线性表L的长度n
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

Position Find( List L, ElementType X ) {
	Position p = L; /* p指向L的第1个结点 */

	while ( p && p->Data != X )
		p = p->Next;

	/* 下列语句可以用 return p; 替换 */
	if ( p )
		return p;
	else
		return NULL;
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
			return NULL;
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


int DelElem(List L, ElementType X) {
	Position p = L; /* p指向L的第1个结点 */

	//查找item所在节点 的前一个节点
	while ( p->Next && p->Next->Data != X )
		p = p->Next;

	/* 删除 */
	if ( p->Next ) {
		Position tmp = p->Next;
		p->Next = tmp->Next;
		free(tmp);
		return 0;

	} else
		return -1;

}

List MakeEmpty() {
	List L;

	L = (List)malloc(sizeof(struct LNode));
	L->Next = NULL;

	return L;
}

//合并有序链表a,b到ab中，保持有序
void merge(List a, List b, List ab) {
	int k = 1;
	Position pa = a->Next;//pa指向a第一个结点
	Position pb = b->Next;//pa指向a第一个结点

	while (pa && pb) {
		if (pa->Data < pb->Data) {
			Insert_H(ab, pa->Data, k++);
			pa = pa -> Next;
		} else {
			Insert_H(ab, pb->Data, k++);
			pb = pb -> Next;
		}
	}


	while (pa) {
		Insert_H(ab, pa->Data, k++);
		pa = pa -> Next;
	}

	while (pb) {
		Insert_H(ab, pb->Data, k++);
		pb = pb -> Next;
	}

	//打印链表内容
	Position p = ab -> Next;//p指向第一个结点
	while (p) {
		printf("%d ", p->Data);
		p = p -> Next;
	}
	printf("链表打印完毕\n");

}












