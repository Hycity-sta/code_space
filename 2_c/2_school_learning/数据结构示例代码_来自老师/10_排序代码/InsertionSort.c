#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int ElementType;

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
