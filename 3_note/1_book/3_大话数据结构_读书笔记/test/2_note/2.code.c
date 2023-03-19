
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20 //这个是存储空间最大值
typedef int ElemType; //这个是指定数据的类型

typedef struct {
    ElemType data[MAXSIZE];//顺序表中的数据
    int length;//顺序表的当前长度
}SqList; //这个是线性表中的顺序存储结构, 下面都叫顺序表


// 下面定义一些通用的常量
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; //这里是指定函数返回值的类型 这个单词是状态,类型的意思

//获取顺序表中具体位置的值
Status GetElem(SqList L, int i, ElemType *e) {
    if (L.length==0 || i<1 || i>L.length) {
        return ERROR;
    }
    *e = L.data[i-1];
    return OK;
}

//在顺序表特定位置插入一个值
Status ListInsert(SqList *L, int i, ElemType e) {
    int k;
    if (L->length==MAXSIZE) {
        return ERROR;
    }
    if (i<1 || i>L->length+1) {
        return ERROR;
    }
    if (i<=L->length) {
        for (k=L->length-1; k>=i-1; k--) {
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}

//删除顺序表中特定位置的值
Status ListDelete(SqList *L, int i, ElemType *e) {
    int k;
    if (L->length == 0) {
        return ERROR;
    }
    if (i<1 || i>L->length) {
        return ERROR;
    }
    *e = L->data[i-1];
    if (i<L->length) {
        for (k=i; k<L->length; k++) {
            L->data[k-1] = L->data[k];
        }
    }
    L->length--;
    return OK;
}


