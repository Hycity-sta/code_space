//������˾N��Ա���Ĺ��䣬Ҫ�󰴹����������ÿ��������ж���Ա����
//
//�����ʽ:
//�������ȸ���������N
//��Ա����������������N����������ÿ��Ա���Ĺ��䣬��Χ��[0, 50]��
//
//�����ʽ:
//������ĵ���˳�����ÿ�������Ա����������ʽΪ��������:��������ÿ��ռһ�С��������Ϊ0��������
//
//��������:
//8
//10 2 0 5 7 2 5 2
//�������:
//0:1
//2:3
//5:2
//7:1
//10:1

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 51

int main() {
	int n;
	scanf("%d", &n);

	int * ages = (int *)malloc(n * sizeof(int));
	int cntAges[MAX_SIZE] = {0};
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", &ages[i]);
		++cntAges[ages[i]];
	}

	for (int i = 0; i < MAX_SIZE; ++i) {
		if (cntAges[i] > 0) {
			printf("%d:%d\n", i, cntAges[i]);
		}
	}

	free(ages);
	return 0;
}
