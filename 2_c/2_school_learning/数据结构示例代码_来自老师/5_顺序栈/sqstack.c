#include <stdio.h> //@include
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType; //@type.definition @type.builtin @type
typedef int Position;
typedef struct SNode * PtrToSNode;
struct SNode {
	ElementType * Data; /* 存储元素的数组 */
	Position Top;      /* 栈顶指针 */
	int MaxSize;       /* 堆栈最大容量 */
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
		printf("堆栈满");
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
		printf("堆栈空"); //@function.call
		return EOF; /* ERROR是ElementType的特殊值，标志错误 */
	} else
		return ( S->Data[(S->Top)--] );
}


// 下面这个部分是共享栈的用法,在这个代码里面还没有完全适配
//bool Push_x( Stack S, ElementType X, int Tag ) {
//	/* Tag作为区分两个堆栈的标志，取值为1和2 */
//	if ( S->Top2 - S->Top1 == 1) { /* 堆栈满 */
//		printf("堆栈满\n");
//		return false;
//	} else {
//		if ( Tag == 1 ) /* 对第一个堆栈操作 */
//			S->Data[++(S->Top1)] = X;
//		else              /* 对第二个堆栈操作 */
//			S->Data[--(S->Top2)] = X;
//		return true;
//	}
//}
//
//ElementType Pop_x( Stack S, int Tag ) {
//	/* Tag作为区分两个堆栈的标志，取值为1和2 */
//	if ( Tag == 1 ) { /* 对第一个堆栈操作 */
//		if ( S->Top1 == -1 ) { /* 堆栈1空 */
//			printf("堆栈1空\n");
//			return ERROR;
//		} else return S->Data[(S->Top1)--];
//	} else { /* 对第二个堆栈操作 */
//		if ( S->Top2 == S->MaxSize ) { /* 堆栈2空 */
//			printf("堆栈2空\n");
//			return ERROR;
//		} else  return S->Data[(S->Top2)++];
//	}
//}
//
