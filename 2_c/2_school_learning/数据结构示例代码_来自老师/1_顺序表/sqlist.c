#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -1
#define MAXSIZE 100

typedef int Position;
typedef struct LNode * PtrToLNode;
typedef int ElementType;



struct LNode {
	ElementType Data[MAXSIZE];
	Position Last;
};
typedef PtrToLNode List;


List MakeEmpty();
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, int i );
bool Delete( List L, int i );

int main( ) {
	printf("�½�˳���\n");
	List l = MakeEmpty();
	
	ElementType x = 1;
	Position p = 1;
	
	for (int i = 0; i < 3; i++) Insert(l, x + i, p + i); //���ϵ���������Ԫ��
	
	//��ӡ˳�������
	for (int i = 0; i <= l->Last; i++) {
		printf("%d ", l->Data[i]);
	}
	printf("˳����ӡ���\n");
	
	//����ָ��λ�á�
	printf("��˳����1��λ�ã��±�Ϊ0������0��Ȼ���ӡ˳���\n");
	Insert(l, 0, 1);
	
	//��ӡ˳�������
	for (int i = 0; i <= l->Last; i++) {
		printf("%d ", l->Data[i]);
	}
	printf("˳����ӡ���\n");
	
	//����
	x = 3;
	p = Find(l, x);
	if (p != ERROR) printf("˳������±� %d,��Ԫ�� %d \n", p, x);
	else printf("˳�����û��Ԫ�� %d \n", x);
	
	//ɾ��
	printf("��˳�����ɾ��λ��%d ��Ԫ��,��Ԫ�������±�Ϊ%d-1\n", x, x);
	Delete(l, x);
	
	//��ӡ˳�������
	for (int i = 0; i <= l->Last; i++) {
		printf("%d ", l->Data[i]);
	}
	printf("˳����ӡ���\n");
	
	return 0;
}

//����һ���յ�˳���
List MakeEmpty() {
	List L;

	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;

	return L;
}

//��һ��Ԫ��x
Position Find( List L, ElementType X ) {
	Position i = 0;

	while ( i <= L->Last && L->Data[i] != X )
		i++;
	if ( i > L->Last )  return ERROR; /* ���û�ҵ������ش�����Ϣ */
	else  return i;  /* �ҵ��󷵻ص��Ǵ洢λ�� */
}

//��һ��ȷ����λ�ò���һ��ȷ����Ԫ��
bool Insert( List L, ElementType X, int i ) {
	/* ��L��ָ��λ��iǰ����һ����Ԫ��X;λ��iԪ�ص�����λ���±���i-1 */
	Position j;

	if ( L->Last == MAXSIZE - 1) {
		/* ��ռ����������ܲ��� */
		printf("����");
		return false;
	}
	if ( i < 1 || i > L->Last + 2 ) {
		/* ������λ��ĺϷ��ԣ��Ƿ���1~n+1��nΪ��ǰԪ�ظ�������Last+1 */
		printf("λ�򲻺Ϸ�");
		return false;
	}
	for ( j = L->Last; j >= i - 1; j-- ) /*Lastָ���������Ԫ�� */
		L->Data[j + 1] = L->Data[j]; /* ��λ��i���Ժ��Ԫ��˳������ƶ� */
	L->Data[i - 1] = X; /* ��Ԫ�ز����iλ���������±�Ϊi-1 */
	L->Last++;       /* Last��ָ�����Ԫ�� */
	return true;
}

//��һ��ȷ����λ��ɾ����λ�õ�Ԫ��
bool Delete( List L, int i ) {
	/* ��L��ɾ��ָ��λ��i��Ԫ��,��Ԫ�������±�Ϊi-1 */
	Position j;

	if ( i < 1 || i > L->Last + 1 ) { /* ���ձ�ɾ��λ��ĺϷ��� */
		printf("λ��%d������Ԫ��", i );
		return false;
	}
	for ( j = i; j <= L->Last; j++ )
		L->Data[j - 1] = L->Data[j]; /*��λ��i+1���Ժ��Ԫ��˳����ǰ�ƶ�*/
	L->Last--; /* Last��ָ�����Ԫ�� */
	return true;
}
