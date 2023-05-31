#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR NULL

typedef struct LNode * PtrToLNode;
typedef int ElementType;

struct LNode {
	ElementType Data;//�������
	PtrToLNode Next;//ָ����һ�����
};
typedef PtrToLNode Position;//�����λ���ǽ��ĵ�ַ
typedef PtrToLNode List;//��List�����ͷָ��


//Lû��ͷ���,�������Ա�L�ĳ���n 3.5
int Length( List L );
//L��ͷ���,�������Ա�L�ĳ���(ʵ��Ԫ�ظ���)n 3.5
int Length_H( List L );
//��ʼ��һ���µĲ���ͷ���Ŀ����Ա�L��
List MakeEmpty();
//��ʼ��һ���µĴ�ͷ���Ŀ����Ա�L��
List MakeEmpty_H();
//Lû��ͷ���,����ָ����λ��i(λ���1��ʼ)��������ӦԪ�� ��3.6
ElementType FindKth(List L, int i );
//L��ͷ���,����ָ����λ��i(λ���1��ʼ)��������ӦԪ�� ��
ElementType FindKth_H(List L, int i );
//��֪X���������Ա�L����X��ͬ�ĵ�һ��Ԫ�ص���Ӧ��ַ�����������򷵻ؿգ�
Position Find( List L, ElementType X );
//L��ͷ�ڵ㣬ָ��λ��iǰ����һ����Ԫ��X���ɹ��򷵻�true�����򷵻�false��3.9
bool Insert_H(List L, ElementType X, int i);
//L��ͷ�ڵ㣬ɾ��ָ��λ��i��Ԫ�أ��ɹ��򷵻�true�����򷵻�false��3.10
bool Delete_H(List L, int  i);


int main( ) {
	printf("�½���ͷ�ڵ������\n");
	List l = MakeEmpty_H();
	ElementType x = 0;
	int n = 0; //������
	
	for (int i = 1; i < 4; i++) {
		Insert_H(l, x + i, i); //���ϵ���������Ԫ��
		n = Length_H( l );
		printf("��ǰ������Ϊ %d\n", n);
	}
	
	//��ӡ��������
	Position p = l->Next; //pָ���һ�����
	while (p) {
		printf("%d ", p->Data);
		p = p -> Next;
	}
	printf("�����ӡ���\n");

	//����ָ��λ�á�
	printf("�������1��λ�ò���0��Ȼ���ӡ����\n");
	Insert_H(l, 0, 1);

	//��ӡ��������
	p = l->Next; //pָ���һ�����
	while (p) {
		printf("%d ", p->Data);
		p = p -> Next;
	}
	printf("�����ӡ���\n");

	//����
	//����ָ����λ��i��������ӦԪ��
	int k = 3;
	x = FindKth_H(l, k);
	if (x != -1)
		printf("�����е� %d ���ڵ��Ԫ��Ϊ %d \n", k, x);
	else
		printf("������û�е� %d ���ڵ�\n", k);

	//��������l����x��ͬ�ĵ�һ��Ԫ�ص���Ӧλ��
	x = 2;
	Position pt = Find(l->Next, x); //lΪͷ�ڵ㣬l->Next�ǵ�һ���ڵ�
	if (pt) {
		p = l->Next; //pָ���һ�����
		int cnt = 1;
		while (p != pt) {
			cnt++;
			p = p -> Next;

		}
		printf("�����е�һ�γ���Ԫ��Ϊ %d �Ľڵ�λ���� %d\n", x, cnt);
	} else
		printf("������û��Ԫ��Ϊ %d �Ľڵ�\n", x);

	//ɾ��
	printf("��������ɾ���ڵ�λ��Ϊ %d ��Ԫ��,��Ԫ��Ϊ%d\n", k, FindKth(l->Next, k));
	Delete_H(l, k);
	//��ӡ��������
	p = l->Next; //pָ���һ�����
	while (p) {
		printf("%d ", p->Data);
		p = p -> Next;
	}
	printf("�����ӡ���\n");

	return 0;
}

//��ʼ��һ���µĴ�ͷ���Ŀ����Ա�L��
List MakeEmpty_H() {
	List L;

	L = (List)malloc(sizeof(struct LNode));
	L->Next = NULL;

	return L;
}

//��ʼ��һ���µĲ���ͷ���Ŀ����Ա�L��
List MakeEmpty() {
	List L = NULL;
	return L;
}

bool Delete_H( List L, int i ) {
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

//Lû��ͷ��㣬�������Ա�L�ĳ���n
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

//L��ͷ��㣬�������Ա�L�ĳ���(ʵ��Ԫ�ظ���)n
int Length_H( List L ) {
	Length(L->Next); //lΪͷ�ڵ㣬l->Next�ǵ�һ���ڵ�
}

//Lû��ͷ���,����ָ����λ��i(λ���1��ʼ)��������ӦԪ�� ��3.6
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

//L��ͷ���,����ָ����λ��i(λ���1��ʼ)��������ӦԪ�� ��
ElementType FindKth_H(List L, int i ) {
	return FindKth( L->Next, i); //lΪͷ�ڵ㣬l->Next�ǵ�һ���ڵ�
}


Position Find( List L, ElementType X ) {
	Position p = L; /* pָ��L�ĵ�1����� */

	while ( p && p->Data != X )
		p = p->Next;

	/* ������������ return p; �滻 */
	if ( p )
		return p;
	else
		return ERROR;
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
			return ERROR;
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



