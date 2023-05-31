#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct LNode * PtrToLNode;
typedef int ElementType;

struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;


int Length( List L );//�������Ա�L�ĳ���n
List MakeEmpty();//��ʼ��һ���µĿ����Ա�L��
ElementType FindKth(List L, int i );//����ָ����λ��i��������ӦԪ�� ��
Position Find( List L, ElementType X );//��֪X���������Ա�L����X��ͬ�ĵ�һ��Ԫ�ص���Ӧλ��i�����������򷵻ؿգ�
bool Insert_H(List L, ElementType X, int i);//��ͷ�ڵ㣬ָ��λ��iǰ����һ����Ԫ��X���ɹ��򷵻�true�����򷵻�false��
bool Delete(List L, int  i);//ɾ��ָ��λ��i��Ԫ�أ��ɹ��򷵻�true�����򷵻�false��
int DelElem(List L, ElementType  X);//ɾ��Ԫ��X���ڵĽڵ㣬�ɹ�����0��ʧ�ܷ���-1
void merge(List a, List b, List ab); //�ϲ���������a,b��ab�У���������


//�ϲ��������� EX����˼������ԭ������Ļ�����ʵ�� �ϲ� �������.
int main( ) {

	int i;
	int alen, blen;
	ElementType tmp;
	List a = MakeEmpty();
	List b = MakeEmpty();
	List ab = MakeEmpty();
	printf("��������a��Ԫ�ظ���\n");
	scanf("%d", &alen);
	printf("��������ǵݼ���������a��Ԫ�أ�\n");
	for (i = 0; i < alen; i++) {
		scanf("%d", &tmp);
		Insert_H(a, tmp, i + 1);
	}

	//��ӡ����a����
	Position p = a->Next;//pָ���һ�����
	while (p) {
		printf("%d ", p->Data);
		p = p -> Next;
	}
	printf("�����ӡ���\n");

	printf("��������b��Ԫ�ظ���\n");
	scanf("%d", &blen);
	printf("��������ǵݼ���������b��Ԫ�أ�\n");
	for (i = 0; i < blen; i++) {
		scanf("%d", &tmp);
		Insert_H(b, tmp, i + 1);
	}

	//��ӡ����a����
	p = b -> Next;//pָ���һ�����
	while (p) {
		printf("%d ", p->Data);
		p = p -> Next;
	}
	printf("�����ӡ���\n");
	//�ϲ�
	merge(a, b, ab);


	return 0;
}



bool Delete( List L, int i ) {
	/* ����Ĭ��L��ͷ��� */
	Position tmp, pre;
	int cnt = 0;

	/* ����λ��Ϊi-1�Ľ�� */
	pre = L;      /* preָ���ͷ */
	while ( pre && cnt < i - 1 ) {
		pre = pre->Next;
		cnt++;
	}
	if ( pre == NULL || cnt != i - 1 || pre->Next == NULL) {
		/* ���ҽ���λ��Ϊi�Ľ�㲻��L�� */
		printf("����λ�ò�������\n");
		return false;
	} else { /* �ҵ��˴�ɾ����ǰһ�����pre */
		/* �����ɾ�� */
		tmp = pre->Next;
		pre->Next = tmp->Next;
		free(tmp);
		return true;
	}
}


//�������Ա�L�ĳ���n
int Length( List L ) {
	Position p;
	int cnt = 0; /* ��ʼ�������� */

	p = L;  /* pָ���ĵ�һ����� */
	while ( p ) {
		p = p->Next;
		cnt++; /* ��ǰpָ����ǵ�cnt�����*/
	}

	return cnt;
}

ElementType FindKth( List L, int K ) {
	/* ����ָ����λ��K������L����ӦԪ�� */
	Position p;
	int cnt = 1; /* λ���1��ʼ */

	p = L; /* pָ��L�ĵ�1����� */
	while ( p && cnt < K ) {
		p = p->Next;
		cnt++;
	}
	if ( (cnt == K) && p )
		return p->Data; /* �ҵ���K�� */
	else
		return EOF;   /* ���򷵻ش�����Ϣ */
}

Position Find( List L, ElementType X ) {
	Position p = L; /* pָ��L�ĵ�1����� */

	while ( p && p->Data != X )
		p = p->Next;

	/* ������������ return p; �滻 */
	if ( p )
		return p;
	else
		return NULL;
}

List Insert( List L, ElementType X, int i ) {
	Position tmp, pre;

	tmp = (Position)malloc(sizeof(struct LNode)); /* ���롢��װ��� */
	tmp->Data = X;
	if ( i == 1 ) { /* �½������ڱ�ͷ */
		tmp->Next = L;
		return tmp; /* �����±�ͷָ�� */
	} else {
		/* ����λ��Ϊi-1�Ľ�� */
		int cnt = 1;  /* λ���1��ʼ */
		pre = L;      /* preָ��L�ĵ�1����� */
		while ( pre && cnt < i - 1 ) {
			pre = pre->Next;
			cnt++;
		}
		if ( pre == NULL || cnt != i - 1) { /* ���ҽ�㲻��L�� */
			printf("����λ�ò�������\n");
			free(tmp);
			return NULL;
		} else { /* �ҵ��˴������ǰһ�����pre */
			/* �����½�㣬���ҷ��ر�ͷL */
			tmp->Next = pre->Next;
			pre->Next = tmp;
			return L;
		}
	}
}


bool Insert_H( List L, ElementType X, int i ) {
	/* ����Ĭ��L��ͷ��� */
	Position tmp, pre;
	int cnt = 0;

	/* ����λ��Ϊi-1�Ľ�� */
	pre = L;      /* preָ���ͷ */
	while ( pre && cnt < i - 1 ) {
		pre = pre->Next;
		cnt++;
	}
	if ( pre == NULL || cnt != i - 1) { /* ���ҽ�㲻��L�� */
		printf("����λ�ò�������\n");
		return false;
	} else { /* �ҵ��˴������ǰһ�����pre����iΪ1��pre��ָ���ͷ */
		/* �����½�� */
		tmp = (Position)malloc(sizeof(struct LNode)); /*���롢��װ���*/
		tmp->Data = X;
		tmp->Next = pre->Next;
		pre->Next = tmp;
		return true;
	}
}


int DelElem(List L, ElementType X) {
	Position p = L; /* pָ��L�ĵ�1����� */

	//����item���ڽڵ� ��ǰһ���ڵ�
	while ( p->Next && p->Next->Data != X )
		p = p->Next;

	/* ɾ�� */
	if ( p->Next ) {
		Position tmp = p->Next;
		p->Next = tmp->Next;
		free(tmp);
		return 0;

	} else
		return -1;

}

List MakeEmpty() {
	List L;

	L = (List)malloc(sizeof(struct LNode));
	L->Next = NULL;

	return L;
}

//�ϲ���������a,b��ab�У���������
void merge(List a, List b, List ab) {
	int k = 1;
	Position pa = a->Next;//paָ��a��һ�����
	Position pb = b->Next;//paָ��a��һ�����

	while (pa && pb) {
		if (pa->Data < pb->Data) {
			Insert_H(ab, pa->Data, k++);
			pa = pa -> Next;
		} else {
			Insert_H(ab, pb->Data, k++);
			pb = pb -> Next;
		}
	}


	while (pa) {
		Insert_H(ab, pa->Data, k++);
		pa = pa -> Next;
	}

	while (pb) {
		Insert_H(ab, pb->Data, k++);
		pb = pb -> Next;
	}

	//��ӡ��������
	Position p = ab -> Next;//pָ���һ�����
	while (p) {
		printf("%d ", p->Data);
		p = p -> Next;
	}
	printf("�����ӡ���\n");

}












