#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NoInfo 0         /* 用0表示没有结点 */
typedef int ElementType;

typedef struct TNode * Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode { /* 树结点定义 */
	ElementType Data; /* 结点数据 */
	BinTree Left;     /* 指向左子树 */
	BinTree Right;    /* 指向右子树 */
};

//队列
typedef struct QNode * Queue;
struct QNode {
	BinTree * Data;
	int Front, Rear;  /* 队列的头、尾指针 */
	int MaxSize;      /* 队列最大容量 */
};

//堆栈
typedef  struct  SNode * PtrToSNode;
struct  SNode {
	BinTree Data;
	PtrToSNode Next;
};
typedef  PtrToSNode  Stack;

//二叉树的操作
void InorderTraversal(BinTree BT); // 中序遍历
void PreorderTraversal(BinTree BT); // 先序遍历
void PostorderTraversal(BinTree BT); // 后序遍历
void InorderTraversal_C(BinTree BT); // 非递归中序遍历
void LevelorderTraversal (BinTree BT); // 层序遍历
void PreorderPrintLeaves(BinTree BT); // 先序遍历输出二叉树中的叶子结点
int GetHeight(BinTree BT); // 求二叉树的高度
BinTree CreatBinTree(); // 二叉树的创建

//队列的操作
Queue CreatQueue(); //生成空队列
bool AddQ(Queue Q, BinTree X); //将元素X入队
bool IsEmptyQ(Queue Q); //判断队列Q是否为空，若是返回true；否则返回false。
bool IsFullQ(Queue Q); //判断队列Q是否满
BinTree DeleteQ(Queue Q); //删除并返回队头元素

//堆栈的操作
Stack CreateStack(); //生成空堆栈
bool Push(Stack S, BinTree X); //将元素X压入堆栈。若堆栈已满，返回false；否则将数据元素X插入到堆栈S栈顶处并返回true。
bool IsEmpty (Stack S); //判断堆栈S是否为空，若是返回true；否则返回false。
BinTree Pop(Stack S); //删除并返回栈顶元素。若堆栈为空，返回错误信息；否则将栈顶数据元素从堆栈中删除并返回。


void InorderTraversal( BinTree BT ) {
	if ( BT ) {
		InorderTraversal( BT->Left );
		/* 此处假设对BT结点的访问就是打印数据 */
		printf("%d ", BT->Data); /* 假设数据为整型 */
		InorderTraversal( BT->Right );
	}
}

void PreorderTraversal( BinTree BT ) {
	if ( BT ) {
		printf("%d ", BT->Data );
		PreorderTraversal( BT->Left );
		PreorderTraversal( BT->Right );
	}
}

void PostorderTraversal( BinTree BT ) {
	if ( BT ) {
		PostorderTraversal( BT->Left );
		PostorderTraversal( BT->Right );
		printf("%d ", BT->Data);
	}
}

void InorderTraversal_C( BinTree BT ) {
	BinTree T;
	Stack S = CreateStack(); /* 创建空堆栈S，元素类型为BinTree */

	T = BT; /* 从根结点出发 */
	while ( T || !IsEmpty(S) ) {
		while ( T ) { /* 一直向左并将沿途结点压入堆栈 */
			Push(S, T);
			T = T->Left;
		}
		T = Pop(S); /* 结点弹出堆栈 */
		printf("%d ", T->Data); /*（访问）打印结点 */
		T = T->Right; /* 转向右子树 */
	}
}

void LevelorderTraversal ( BinTree BT ) {
	Queue Q;
	BinTree T;

	if ( !BT ) return; /* 若是空树则直接返回 */

	Q = CreatQueue(); /* 创建空队列Q */
	AddQ( Q, BT );
	while ( !IsEmptyQ(Q) ) {
		T = DeleteQ( Q );
		printf("%d ", T->Data); /* 访问取出队列的结点 */
		if ( T->Left )   AddQ( Q, T->Left );
		if ( T->Right )  AddQ( Q, T->Right );
	}
}

void PreorderPrintLeaves( BinTree BT ) {
	if ( BT ) {
		if ( !BT->Left && !BT->Right ) /* 如果BT结点是叶子 */
			printf("%d ", BT->Data );
		PreorderPrintLeaves ( BT->Left );
		PreorderPrintLeaves ( BT->Right );
	}
}

int GetHeight( BinTree BT ) {
	int HL, HR, MaxH;

	if ( BT ) {
		HL = GetHeight(BT->Left);   /* 求左子树的高度 */
		HR = GetHeight(BT->Right);  /* 求右子树的高度 */
		MaxH = HL > HR ? HL : HR;   /* 取左右子树较大的高度 */
		return ( MaxH + 1 );        /* 返回树的高度 */
	} else  return 0; /* 空树高度为0 */
}


BinTree CreatBinTree() {
	ElementType Data;
	BinTree BT, T;
	Queue Q = CreatQueue(); /* 创建空队列 */

	/* 建立第1个结点，即根结点 */
	scanf("%d", &Data);
	if ( Data != NoInfo ) {
		/* 分配根结点单元，并将结点地址入队 */
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = Data;
		BT->Left = BT->Right = NULL;
		AddQ( Q, BT );
	} else return NULL; /* 若第1个数据就是0，返回空树 */

	while ( !IsEmptyQ(Q) ) {
		T = DeleteQ(Q); /* 从队列中取出一结点地址*/
		scanf("%d", &Data); /* 读入T的左孩子 */
		if ( Data == NoInfo ) T->Left = NULL;
		else {  /* 分配新结点，作为出队结点左孩子；新结点入队 */
			T->Left = (BinTree)malloc(sizeof(struct TNode));
			T->Left->Data = Data;
			T->Left->Left = T->Left->Right = NULL;
			AddQ( Q, T->Left );
		}
		scanf("%d", &Data); /* 读入T的右孩子 */
		if ( Data == NoInfo ) T->Right = NULL;
		else {  /* 分配新结点，作为出队结点右孩子；新结点入队 */
			T->Right = (BinTree)malloc(sizeof(struct TNode));
			T->Right->Data = Data;
			T->Right->Left = T->Right->Right = NULL;
			AddQ( Q, T->Right );
		}
	} /* 结束while */
	return BT;
}

Queue CreatQueue() {
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QNode));
	Q -> Data = (BinTree *)malloc(100 * sizeof(struct TNode));
	Q->MaxSize = 100;
	Q->Front = 0;
	Q->Rear = 0;
	return Q;
}

bool AddQ( Queue Q, BinTree X ) {
	if ( IsFullQ(Q) ) {
		printf("队列满");
		return false;
	} else {
		Q->Rear = (Q->Rear + 1) % Q->MaxSize;
		Q->Data[Q->Rear] = X;
		return true;
	}
}

BinTree DeleteQ( Queue Q ) {
	if ( IsEmptyQ(Q) ) {
		printf("队列空");
		return NULL;
	} else  {
		Q->Front = (Q->Front + 1) % Q->MaxSize;
		return  Q->Data[Q->Front];
	}
}


bool IsEmptyQ( Queue Q ) {
	return ( Q->Front == Q->Rear);
}

bool IsFullQ( Queue Q ) {
	return ( (Q->Rear + 1 ) % Q -> MaxSize == Q->Front);
}


Stack CreateStack( ) {
	/* 构建一个堆栈的头结点，返回该结点指针 */
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

bool IsEmpty ( Stack S ) {
	/* 判断堆栈S是否为空，若是返回true；否则返回false */
	return ( S->Next == NULL );
}

bool Push( Stack S, BinTree X ) {
	/* 将元素X压入堆栈S */
	PtrToSNode TmpCell;
	TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
	TmpCell->Data = X;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	return true;
}

BinTree Pop( Stack S ) {
	/* 删除并返回堆栈S的栈顶元素 */
	PtrToSNode FirstCell;
	BinTree TopElem;
	if ( IsEmpty(S) ) {
		printf("堆栈空");
		return NULL;
	} else {
		FirstCell = S->Next;
		TopElem = FirstCell->Data;
		S->Next = FirstCell->Next;
		free(FirstCell);
		return TopElem;
	}
}


int main() {
	//层序创建二叉树，1、输入1 2 3 0 0 0 0; 2、输入 1 2 3 4 5 6 7 0 0 10 0 0 13 0 0 0 0 0 0
	printf("新建二叉树\n");
	BinTree BT = CreatBinTree();

	//中序遍历
	printf("开始中序遍历二叉树\n");
	InorderTraversal( BT );
	printf("中序遍历二叉树完毕\n");

	//先序遍历
	printf("开始先序遍历二叉树\n");
	PreorderTraversal( BT );
	printf("先序遍历二叉树完毕\n");

	//后序遍历
	printf("开始后序遍历二叉树\n");
	PostorderTraversal( BT );
	printf("后序遍历二叉树完毕\n");

	//非递归中序遍历
	printf("开始非递归中序遍历二叉树\n");
	InorderTraversal_C( BT );
	printf("非递归中序遍历二叉树完毕\n");

	//层序遍历
	printf("开始层序遍历二叉树\n");
	LevelorderTraversal( BT );
	printf("层序遍历二叉树完毕\n");

	//先序遍历输出二叉树中的叶子结点
	printf("开始先序遍历输出二叉树中的叶子结点\n");
	PreorderPrintLeaves( BT );
	printf("先序遍历输出二叉树中的叶子结点完毕\n");

	//求二叉树的高度
	int h = GetHeight( BT );
	printf("二叉树高度为：%d\n", h);

	return 0;
}




