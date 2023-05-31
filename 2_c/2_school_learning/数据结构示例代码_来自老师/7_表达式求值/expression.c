// ����Ǳ��ʽ��ֵ�Ĵ���,�����������˳��ջ��

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR -1 /* ����ջΪ��ʱ���ش�������Ĭ����ȷ����ֵȫ������ */
#define MAXOP 100    /* ���������п��ܵ���󳤶� */
#define INFINITY 1e9 /* ���������� */

typedef double ElementType; /* ����ջ��Ԫ�����;��廯 */
/* �������ζ�Ӧ����������������ַ�����β */
typedef enum {num, opr, end} Type;
typedef enum {true, false} bool;
typedef int Position;

struct SNode {
	ElementType * Data; /* �洢Ԫ�ص����� */
	Position Top;      /* ջ��ָ�� */
	int MaxSize;       /* ��ջ������� */
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
		printf("��ջ��");
		return EOF; /* ERROR��ElementType������ֵ����־���� */
	} else
		return ( S->Data[(S->Top)--] );
}

Type GetOp( char * Expr, int * start, char * str ) {
	/* ��*start��ʼ������һ�����󣨲�������������������������ַ���str�� */
	int i = 0;

	/* �������ʽǰ�ո� */
	while ( (str[0] = Expr[(*start)++]) == ' ' ) ;

	while ( str[i] != ' ' && str[i] != '\0' )
		str[++i] = Expr[(*start)++];
	if ( str[i] == '\0' ) /* �����������Ľ�β */
		(*start)--;     /* *startָ������� */
	str[i] = '\0';      /* ����һ������Ļ�ȡ */

	if ( i == 0 ) return end; /* �����˽��� */
	else if ( isdigit(str[0]) || isdigit(str[1]) ) /* ���str[0]�����֡����Ƿ��Ÿ������� */
		return num;        /* ��ʾ��ʱstr�д����һ������ */
	else                   /* ���str���ǿմ����ֲ������� */
		return opr;        /* ��ʾ��ʱstr�д����һ������� */
}

ElementType PostfixExp( char * Expr ) {
	/* ����GetOp���������׺���ʽ����ֵ */
	Stack S;
	Type T;
	ElementType Op1, Op2;
	char str[MAXOP];
	int start = 0;

	/* ����һ���¶�ջ */
	S = CreateStack( MAXOP );

	Op1 = Op2 = 0;
	while ( (T = GetOp(Expr, &start, str)) != end ) { /* ��δ�����������ʱ */
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
					if ( Op2 != 0.0 ) /* �������ķ�ĸ�Ƿ�Ϊ0 */
						Push(S, Op1 / Op2);
					else {
						printf("���󣺳�����ĸΪ��\n");
						Op2 = INFINITY;
					}
					break;
				default:
					printf("����δ֪�����%s\n", str);
					Op2 = INFINITY;
					break;
			}
			if ( Op2 >= INFINITY ) break;
		}
	}
	if ( Op2 < INFINITY )    /* ����������˱��ʽ */
		if ( !IsEmpty(S) )   /* ����ʱ��ջ���� */
			Op2 = Pop(S);    /* ��¼������ */
		else Op2 = INFINITY; /* �����Ǵ��� */
	free(S);    /* �ͷŶ�ջ */
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
		printf("���ʽ����\n");

	return 0;
}
