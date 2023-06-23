#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NoInfo 0         /* ��0��ʾû�н�� */
typedef int ElementType;

typedef struct TNode * Position;
typedef Position BinTree; /* ���������� */
struct TNode { /* ����㶨�� */
	ElementType Data; /* ������� */
	BinTree Left;     /* ָ�������� */
	BinTree Right;    /* ָ�������� */
};

//����
typedef struct QNode * Queue;
struct QNode {
	BinTree * Data;
	int Front, Rear;  /* ���е�ͷ��βָ�� */
	int MaxSize;      /* ����������� */
};

//��ջ
typedef  struct  SNode * PtrToSNode;
struct  SNode {
	BinTree Data;
	PtrToSNode Next;
};
typedef  PtrToSNode  Stack;

//�������Ĳ���
void InorderTraversal(BinTree BT); // �������
void PreorderTraversal(BinTree BT); // �������
void PostorderTraversal(BinTree BT); // �������
void InorderTraversal_C(BinTree BT); // �ǵݹ��������
void LevelorderTraversal (BinTree BT); // �������
void PreorderPrintLeaves(BinTree BT); // �����������������е�Ҷ�ӽ��
int GetHeight(BinTree BT); // ��������ĸ߶�
BinTree CreatBinTree(); // �������Ĵ���

//���еĲ���
Queue CreatQueue(); //���ɿն���
bool AddQ(Queue Q, BinTree X); //��Ԫ��X���
bool IsEmptyQ(Queue Q); //�ж϶���Q�Ƿ�Ϊ�գ����Ƿ���true�����򷵻�false��
bool IsFullQ(Queue Q); //�ж϶���Q�Ƿ���
BinTree DeleteQ(Queue Q); //ɾ�������ض�ͷԪ��

//��ջ�Ĳ���
Stack CreateStack(); //���ɿն�ջ
bool Push(Stack S, BinTree X); //��Ԫ��Xѹ���ջ������ջ����������false����������Ԫ��X���뵽��ջSջ����������true��
bool IsEmpty (Stack S); //�ж϶�ջS�Ƿ�Ϊ�գ����Ƿ���true�����򷵻�false��
BinTree Pop(Stack S); //ɾ��������ջ��Ԫ�ء�����ջΪ�գ����ش�����Ϣ������ջ������Ԫ�شӶ�ջ��ɾ�������ء�


void InorderTraversal( BinTree BT ) {
	if ( BT ) {
		InorderTraversal( BT->Left );
		/* �˴������BT���ķ��ʾ��Ǵ�ӡ���� */
		printf("%d ", BT->Data); /* ��������Ϊ���� */
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
	Stack S = CreateStack(); /* �����ն�ջS��Ԫ������ΪBinTree */

	T = BT; /* �Ӹ������� */
	while ( T || !IsEmpty(S) ) {
		while ( T ) { /* һֱ���󲢽���;���ѹ���ջ */
			Push(S, T);
			T = T->Left;
		}
		T = Pop(S); /* ��㵯����ջ */
		printf("%d ", T->Data); /*�����ʣ���ӡ��� */
		T = T->Right; /* ת�������� */
	}
}

void LevelorderTraversal ( BinTree BT ) {
	Queue Q;
	BinTree T;

	if ( !BT ) return; /* ���ǿ�����ֱ�ӷ��� */

	Q = CreatQueue(); /* �����ն���Q */
	AddQ( Q, BT );
	while ( !IsEmptyQ(Q) ) {
		T = DeleteQ( Q );
		printf("%d ", T->Data); /* ����ȡ�����еĽ�� */
		if ( T->Left )   AddQ( Q, T->Left );
		if ( T->Right )  AddQ( Q, T->Right );
	}
}

void PreorderPrintLeaves( BinTree BT ) {
	if ( BT ) {
		if ( !BT->Left && !BT->Right ) /* ���BT�����Ҷ�� */
			printf("%d ", BT->Data );
		PreorderPrintLeaves ( BT->Left );
		PreorderPrintLeaves ( BT->Right );
	}
}

int GetHeight( BinTree BT ) {
	int HL, HR, MaxH;

	if ( BT ) {
		HL = GetHeight(BT->Left);   /* ���������ĸ߶� */
		HR = GetHeight(BT->Right);  /* ���������ĸ߶� */
		MaxH = HL > HR ? HL : HR;   /* ȡ���������ϴ�ĸ߶� */
		return ( MaxH + 1 );        /* �������ĸ߶� */
	} else  return 0; /* �����߶�Ϊ0 */
}


BinTree CreatBinTree() {
	ElementType Data;
	BinTree BT, T;
	Queue Q = CreatQueue(); /* �����ն��� */

	/* ������1����㣬������� */
	scanf("%d", &Data);
	if ( Data != NoInfo ) {
		/* �������㵥Ԫ����������ַ��� */
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = Data;
		BT->Left = BT->Right = NULL;
		AddQ( Q, BT );
	} else return NULL; /* ����1�����ݾ���0�����ؿ��� */

	while ( !IsEmptyQ(Q) ) {
		T = DeleteQ(Q); /* �Ӷ�����ȡ��һ����ַ*/
		scanf("%d", &Data); /* ����T������ */
		if ( Data == NoInfo ) T->Left = NULL;
		else {  /* �����½�㣬��Ϊ���ӽ�����ӣ��½����� */
			T->Left = (BinTree)malloc(sizeof(struct TNode));
			T->Left->Data = Data;
			T->Left->Left = T->Left->Right = NULL;
			AddQ( Q, T->Left );
		}
		scanf("%d", &Data); /* ����T���Һ��� */
		if ( Data == NoInfo ) T->Right = NULL;
		else {  /* �����½�㣬��Ϊ���ӽ���Һ��ӣ��½����� */
			T->Right = (BinTree)malloc(sizeof(struct TNode));
			T->Right->Data = Data;
			T->Right->Left = T->Right->Right = NULL;
			AddQ( Q, T->Right );
		}
	} /* ����while */
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
		printf("������");
		return false;
	} else {
		Q->Rear = (Q->Rear + 1) % Q->MaxSize;
		Q->Data[Q->Rear] = X;
		return true;
	}
}

BinTree DeleteQ( Queue Q ) {
	if ( IsEmptyQ(Q) ) {
		printf("���п�");
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
	/* ����һ����ջ��ͷ��㣬���ظý��ָ�� */
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

bool IsEmpty ( Stack S ) {
	/* �ж϶�ջS�Ƿ�Ϊ�գ����Ƿ���true�����򷵻�false */
	return ( S->Next == NULL );
}

bool Push( Stack S, BinTree X ) {
	/* ��Ԫ��Xѹ���ջS */
	PtrToSNode TmpCell;
	TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
	TmpCell->Data = X;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	return true;
}

BinTree Pop( Stack S ) {
	/* ɾ�������ض�ջS��ջ��Ԫ�� */
	PtrToSNode FirstCell;
	BinTree TopElem;
	if ( IsEmpty(S) ) {
		printf("��ջ��");
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
	//���򴴽���������1������1 2 3 0 0 0 0; 2������ 1 2 3 4 5 6 7 0 0 10 0 0 13 0 0 0 0 0 0
	printf("�½�������\n");
	BinTree BT = CreatBinTree();

	//�������
	printf("��ʼ�������������\n");
	InorderTraversal( BT );
	printf("����������������\n");

	//�������
	printf("��ʼ�������������\n");
	PreorderTraversal( BT );
	printf("����������������\n");

	//�������
	printf("��ʼ�������������\n");
	PostorderTraversal( BT );
	printf("����������������\n");

	//�ǵݹ��������
	printf("��ʼ�ǵݹ��������������\n");
	InorderTraversal_C( BT );
	printf("�ǵݹ�����������������\n");

	//�������
	printf("��ʼ�������������\n");
	LevelorderTraversal( BT );
	printf("����������������\n");

	//�����������������е�Ҷ�ӽ��
	printf("��ʼ�����������������е�Ҷ�ӽ��\n");
	PreorderPrintLeaves( BT );
	printf("�����������������е�Ҷ�ӽ�����\n");

	//��������ĸ߶�
	int h = GetHeight( BT );
	printf("�������߶�Ϊ��%d\n", h);

	return 0;
}




