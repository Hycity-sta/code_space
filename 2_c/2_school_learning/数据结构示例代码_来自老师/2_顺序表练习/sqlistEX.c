#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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


int DelElem(List L, ElementType item);
ElementType GetElem(List L, Position pos); //�����±�Ϊpos��Ԫ��
void merge(List a, List b, List ab);


//�ϲ�����˳���
int main() {
	int i;
	int alen, blen;
	ElementType tmp;
	
	List a = MakeEmpty();
	List b = MakeEmpty();
	List ab = MakeEmpty();
	
	printf("����˳���a��Ԫ�ظ���\n");
	scanf("%d", &alen);
	printf("��������ǵݼ�����˳���a��Ԫ�أ�\n");
	for (i = 0; i < alen; i++) {
		scanf("%d", &tmp);
		Insert(a, tmp, i + 1);
	}
	printf("����˳���b��Ԫ�ظ���\n");
	
	scanf("%d", &blen);
	printf("��������ǵݼ�����˳���b��Ԫ�أ�\n");
	for (i = 0; i < blen; i++) {
		scanf("%d", &tmp);
		Insert(b, tmp, i + 1);
	}
	//�ϲ�
	merge(a, b, ab);
}


List MakeEmpty() {
	List L;

	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;

	return L;
}

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


Position Find( List L, ElementType X ) {
	Position i = 0;

	while ( i <= L->Last && L->Data[i] != X )
		i++;
	if ( i > L->Last )  return ERROR; /* ���û�ҵ������ش�����Ϣ */
	else  return i;  /* �ҵ��󷵻ص��Ǵ洢λ�� */
}


int DelElem(List L, ElementType item) {
	Position p = Find(L, item);
	if (p != -1) {
		Delete(L, p + 1);
		return 1;
	} else
		return ERROR;
}


ElementType GetElem(List L, Position pos) {
	if (pos < 0 || pos > L->Last) {
		printf("λ����Ч");
		return ERROR;
	}
	return L->Data[pos];
}


//�ϲ�����˳���a,b��ab�У��������� ;����ӡab
void merge(List a, List b, List ab) {
	int i, j, k;
	for (i = 0, j = 0, k = 0; i <= a->Last && j <= b->Last; k++) {
		if (a->Data[i] < b->Data[j]) {
			Insert(ab, a->Data[i], k + 1);
			i++;
		} else {
			Insert(ab, b->Data[j], k + 1);
			j++;
		}
	}
	while (j <= b->Last) {
		Insert(ab, b->Data[j], k + 1);
		j++;
		k++;
	}
	while (i <= a->Last) {
		Insert(ab, a->Data[i], k + 1);
		i++;
		k++;
	}
	for (i = 0; i <= ab->Last; i++)
		printf("%d ", ab->Data[i]);
}


//int main( ) {
//	printf("�½�˳����õ�\n");
//	List l = MakeEmpty();
//	ElementType x = 1;
//	Position p = 1;
//	for (int i = 0; i < 3; i++) Insert(l, x + i, p + i); //���ϵ���������Ԫ��
//	//��ӡ˳�������
//	for (int i = 0; i <= l->Last; i++) {
//		printf("%d ", l->Data[i]);
//	}
//	printf("˳����ӡ���\n");
//	//����ָ��λ�á�
//	printf("��˳����1��λ�ã��±�Ϊ0������0��Ȼ���ӡ˳���\n");
//	Insert(l, 0, 1);
//	//��ӡ˳�������
//	for (int i = 0; i <= l->Last; i++) {
//		printf("%d ", l->Data[i]);
//	}
//	printf("˳����ӡ���\n");
//	//����
//	x = 3;
//	p = Find(l, x);
//	if (p != ERROR) printf("˳������±� %d,��Ԫ�� %d \n", p, x);
//	else printf("˳�����û��Ԫ�� %d \n", x);
//	//ɾ��
//	p = 2;
//	printf("��˳�����ɾ��λ��%d ��Ԫ��,��Ԫ�������±�Ϊ%d-1\n", p, p);
//	Delete(l, p);
//	//��ӡ˳�������
//	for (int i = 0; i <= l->Last; i++) {
//		printf("%d ", l->Data[i]);
//	}
//	printf("˳����ӡ���\n");
//	//ɾ��2
//	x = 2;
//	printf("��˳�����ɾ����һ��ֵΪ%d��Ԫ��:\n", x);
//	DelElem(l, x);
//	//��ӡ˳�������
//	for (int i = 0; i <= l->Last; i++) {
//		printf("%d ", l->Data[i]);
//	}
//	printf("˳����ӡ���\n");
//	//����λ��1��Ԫ��
//	ElementType ep;
//	p = 1;
//	ep = GetElem(l, p);
//	printf("���ҵ�λ����%d��Ԫ����:%d", p, ep);
//	return 0;
//}
