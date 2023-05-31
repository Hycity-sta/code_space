#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int ElementType;

void Swap( ElementType * a, ElementType * b ) {
	ElementType t = *a;
	*a = *b;
	*b = t;
}

void InsertionSort( ElementType A[], int N ) {
	/* �������� */
	int P, i;
	ElementType Tmp;

	for ( P = 1; P < N; P++ ) {
		Tmp = A[P]; /* ȡ��δ���������еĵ�һ��Ԫ��*/
		for ( i = P; i > 0 && A[i - 1] > Tmp; i-- )
			A[i] = A[i - 1]; /*������������������Ԫ�رȽϲ�����*/
		A[i] = Tmp; /* �Ž����ʵ�λ�� */
	}
}

ElementType Median3( ElementType A[], int Left, int Right ) {
	int Center = (Left + Right) / 2;
	if ( A[Left] > A[Center] )
		Swap( &A[Left], &A[Center] );
	if ( A[Left] > A[Right] )
		Swap( &A[Left], &A[Right] );
	if ( A[Center] > A[Right] )
		Swap( &A[Center], &A[Right] );
	/* ��ʱA[Left] <= A[Center] <= A[Right] */
	Swap( &A[Center], &A[Right - 1] ); /* ����׼Pivot�ص��ұ�*/
	/* ֻ��Ҫ����A[Left+1] �� A[Right-2] */
	return  A[Right - 1]; /* ���ػ�׼Pivot */
}

void Qsort( ElementType A[], int Left, int Right ) {
	/* ���ĵݹ麯�� */
	int Pivot, Cutoff, Low, High;

	if ( Cutoff <= Right - Left ) { /* �������Ԫ�س�ֶ࣬������� */
		Pivot = Median3( A, Left, Right ); /* ѡ��׼ */
		Low = Left;
		High = Right - 1;
		while (1) { /*�������бȻ�׼С���Ƶ���׼��ߣ�����Ƶ��ұ�*/
			while ( A[++Low] < Pivot ) ;
			while ( A[--High] > Pivot ) ;
			if ( Low < High ) Swap( &A[Low], &A[High] );
			else break;
		}
		Swap( &A[Low], &A[Right - 1] ); /* ����׼������ȷ��λ�� */
		Qsort( A, Left, Low - 1 );  /* �ݹ������ */
		Qsort( A, Low + 1, Right ); /* �ݹ����ұ� */
	} else InsertionSort( A + Left, Right - Left + 1 ); /* Ԫ��̫�٣��ü����� */
}

void QuickSort( ElementType A[], int N ) {
	/* ͳһ�ӿ� */
	Qsort( A, 0, N - 1 );
}
