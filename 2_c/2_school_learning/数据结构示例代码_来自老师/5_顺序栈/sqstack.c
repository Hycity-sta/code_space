#include <stdio.h> //@include
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType; //@type.definition @type.builtin @type
typedef int Position;
typedef struct SNode * PtrToSNode;
struct SNode {
	ElementType * Data; /* �洢Ԫ�ص����� */
	Position Top;      /* ջ��ָ�� */
	int MaxSize;       /* ��ջ������� */
};
typedef PtrToSNode Stack;

Stack CreateStack(int Maxsize); //@parameter @variable @function
bool IsFull(Stack S);
bool Push(Stack S, ElementType X);
bool IsEmpty(Stack S);
ElementType Pop(Stack S);
bool Push_x(Stack S, ElementType X, int Tag);
ElementType Pop_x(Stack S, int Tag);


Stack CreateStack( int MaxSize ) {
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType)); //@keyword.operator
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S; //keyword.return
}

bool IsFull( Stack S ) {
	return (S->Top == S->MaxSize - 1); //@number
}

bool Push( Stack S, ElementType X ) {
	if ( IsFull(S) ) {
		printf("��ջ��");
		return false;
	} else {
		S->Data[++(S->Top)] = X;
		return true;
	}
}

bool IsEmpty( Stack S ) {
	return (S->Top == -1);
}

ElementType Pop( Stack S ) {
	if ( IsEmpty(S) ) {
		printf("��ջ��"); //@function.call
		return EOF; /* ERROR��ElementType������ֵ����־���� */
	} else
		return ( S->Data[(S->Top)--] );
}


// ������������ǹ���ջ���÷�,������������滹û����ȫ����
//bool Push_x( Stack S, ElementType X, int Tag ) {
//	/* Tag��Ϊ����������ջ�ı�־��ȡֵΪ1��2 */
//	if ( S->Top2 - S->Top1 == 1) { /* ��ջ�� */
//		printf("��ջ��\n");
//		return false;
//	} else {
//		if ( Tag == 1 ) /* �Ե�һ����ջ���� */
//			S->Data[++(S->Top1)] = X;
//		else              /* �Եڶ�����ջ���� */
//			S->Data[--(S->Top2)] = X;
//		return true;
//	}
//}
//
//ElementType Pop_x( Stack S, int Tag ) {
//	/* Tag��Ϊ����������ջ�ı�־��ȡֵΪ1��2 */
//	if ( Tag == 1 ) { /* �Ե�һ����ջ���� */
//		if ( S->Top1 == -1 ) { /* ��ջ1�� */
//			printf("��ջ1��\n");
//			return ERROR;
//		} else return S->Data[(S->Top1)--];
//	} else { /* �Եڶ�����ջ���� */
//		if ( S->Top2 == S->MaxSize ) { /* ��ջ2�� */
//			printf("��ջ2��\n");
//			return ERROR;
//		} else  return S->Data[(S->Top2)++];
//	}
//}
//
