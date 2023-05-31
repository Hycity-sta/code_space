// 这个是表达式求值的代码,这个是依托于顺序栈的

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR -1 /* 当堆栈为空时返回错误，这里默认正确返回值全是正的 */
#define MAXOP 100    /* 操作数序列可能的最大长度 */
#define INFINITY 1e9 /* 代表正无穷 */

typedef double ElementType; /* 将堆栈的元素类型具体化 */
/* 类型依次对应运算数、运算符、字符串结尾 */
typedef enum {num, opr, end} Type;
typedef enum {true, false} bool;
typedef int Position;

struct SNode {
	ElementType * Data; /* 存储元素的数组 */
	Position Top;      /* 栈顶指针 */
	int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode * Stack;

Stack CreateStack(int Maxsize);
bool IsFull(Stack S);
bool Push(Stack S, ElementType X);
bool IsEmpty(Stack S);
ElementType Pop(Stack S);
bool Push_x(Stack S, ElementType X, int Tag);
ElementType Pop_x(Stack S, int Tag);

Stack CreateStack( int MaxSize ) {
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool IsFull( Stack S ) {
	return (S->Top == S->MaxSize - 1);
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
		printf("堆栈空");
		return EOF; /* ERROR是ElementType的特殊值，标志错误 */
	} else
		return ( S->Data[(S->Top)--] );
}

Type GetOp( char * Expr, int * start, char * str ) {
	/* 从*start开始读入下一个对象（操作数或运算符），并保存在字符串str中 */
	int i = 0;

	/* 跳过表达式前空格 */
	while ( (str[0] = Expr[(*start)++]) == ' ' ) ;

	while ( str[i] != ' ' && str[i] != '\0' )
		str[++i] = Expr[(*start)++];
	if ( str[i] == '\0' ) /* 如果读到输入的结尾 */
		(*start)--;     /* *start指向结束符 */
	str[i] = '\0';      /* 结束一个对象的获取 */

	if ( i == 0 ) return end; /* 读到了结束 */
	else if ( isdigit(str[0]) || isdigit(str[1]) ) /* 如果str[0]是数字、或是符号跟个数字 */
		return num;        /* 表示此时str中存的是一个数字 */
	else                   /* 如果str不是空串，又不是数字 */
		return opr;        /* 表示此时str中存的是一个运算符 */
}

ElementType PostfixExp( char * Expr ) {
	/* 调用GetOp函数读入后缀表达式并求值 */
	Stack S;
	Type T;
	ElementType Op1, Op2;
	char str[MAXOP];
	int start = 0;

	/* 申请一个新堆栈 */
	S = CreateStack( MAXOP );

	Op1 = Op2 = 0;
	while ( (T = GetOp(Expr, &start, str)) != end ) { /* 当未读到输入结束时 */
		if ( T == num )
			Push( S, atof(str) );
		else {
			if ( !IsEmpty(S) ) Op2 = Pop(S);
			else Op2 = INFINITY;
			if ( !IsEmpty(S) ) Op1 = Pop(S);
			else Op2 = INFINITY;
			switch ( str[0] ) {
				case '+':
					Push(S, Op1 + Op2);
					break;
				case '*':
					Push(S, Op1 * Op2);
					break;
				case '-':
					Push(S, Op1 - Op2);
					break;
				case '/':
					if ( Op2 != 0.0 ) /* 检查除法的分母是否为0 */
						Push(S, Op1 / Op2);
					else {
						printf("错误：除法分母为零\n");
						Op2 = INFINITY;
					}
					break;
				default:
					printf("错误：未知运算符%s\n", str);
					Op2 = INFINITY;
					break;
			}
			if ( Op2 >= INFINITY ) break;
		}
	}
	if ( Op2 < INFINITY )    /* 如果处理完了表达式 */
		if ( !IsEmpty(S) )   /* 而此时堆栈正常 */
			Op2 = Pop(S);    /* 记录计算结果 */
		else Op2 = INFINITY; /* 否则标记错误 */
	free(S);    /* 释放堆栈 */
	return Op2;
}

int main() {
	char Expr[MAXOP];
	ElementType f;

	gets(Expr);
	f = PostfixExp(Expr);
	if ( f < INFINITY )
		printf("%.4f\n", f);
	else
		printf("表达式错误\n");

	return 0;
}
