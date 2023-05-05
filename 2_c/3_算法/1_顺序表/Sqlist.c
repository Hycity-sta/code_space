#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;

void InitList(SqList *L) {
    L->length = 0;
}

void DestroyList(SqList *L) {
    L->length = 0;
}

void ClearList(SqList *L) {
    L->length = 0;
}

bool ListEmpty(SqList L) {
    return L.length == 0;
}

int ListLength(SqList L) {
    return L.length;
}

bool GetElem(SqList L, int i, int *e) {
    if (i < 1 || i > L.length)
        return false;
    *e = L.data[i-1];
    return true;
}

int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i+1;
    }
    return 0;
}

bool PriorElem(SqList L, int cur_e, int *pre_e) {
    int i;
    for (i = 1; i < L.length; i++) {
        if (L.data[i] == cur_e) {
            *pre_e = L.data[i-1];
            return true;
        }
    }
    return false;
}

bool NextElem(SqList L, int cur_e, int *next_e) {
    int i;
    for (i = 0; i < L.length-1; i++) {
        if (L.data[i] == cur_e) {
            *next_e = L.data[i+1];
            return true;
        }
    }
    return false;
}

bool ListInsert(SqList *L, int i, int e) {
    if (i < 1 || i > L->length+1)
        return false;
    if (L->length >= MAXSIZE)
        return false;
    for (int j = L->length; j >= i; j--)
        L->data[j] = L->data[j-1];
    L->data[i-1] = e;
    L->length++;
    return true;
}

bool ListDelete(SqList *L, int i, int *e) {
    if (i < 1 || i > L->length)
        return false;
    *e = L->data[i-1];
    for (int j = i; j < L->length; j++)
        L->data[j-1] = L->data[j];
    L->length--;
    return true;
}

void ListTraverse(SqList L, void (*visit)(int)) {
    for (int i = 0; i < L.length; i++)
        visit(L.data[i]);
}

void Visit(int e) {
    printf("%d ", e);
}

int main() {
    SqList L;
    int e = 0, pre_e = 0, next_e = 0;

    InitList(&L);

    printf("ListEmpty: %d\n", ListEmpty(L)); // 输出1，表示L为空表
    printf("ListLength: %d\n", ListLength(L)); // 输出0，表示L的长度为0

    ListInsert(&L, 1, 5);
    ListInsert(&L, 2, 7);
    ListInsert(&L, 3, 3);

    ListTraverse(L, Visit); // 输出5 7 3
    printf("\n");

    GetElem(L, 2, &e);
    printf("GetElem: %d\n", e); // 输出7

    LocateElem(L, 7);
    printf("LocateElem: %d\n", LocateElem(L, 7)); // 输出2

    PriorElem(L, 7, &pre_e);
    printf("PriorElem: %d\n", pre_e); // 输出5

    NextElem(L, 7, &next_e);
    printf("NextElem: %d\n", next_e); // 输出3

    ListDelete(&L, 2, &e);
    ListTraverse(L, Visit); // 输出5 3
    printf("\n");

    ClearList(&L);
    printf("ListEmpty: %d\n", ListEmpty(L)); // 输出1，表示L为空表

    return 0;
}
