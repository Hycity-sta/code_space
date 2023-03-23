#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20 //这个是存储空间最大值
typedef int ElemType; //这个是指定数据的类型

typedef struct {
    ElemType data[MAXSIZE];//顺序表中的数据
    int length;//顺序表的当前长度
               //有些顺序表还会弄出一个last用来代表数组最后一个元素的下标
               //如果带有last的话, 下面那些算法的处理就会有点区别了
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
        return ERROR;//对于不合法的操作重拳出击
    }
    *e = L.data[i-1];//i是现实中的计数, 计算机中对数组的计数要减一
    return OK;
}

//在顺序表特定位置插入一个值
Status ListInsert(SqList *L, int i, ElemType e) {
    int k;//这个用来计数的
    if (L->length==MAXSIZE) {
        return ERROR;//与最大长度相等了,没位置给你插了,重拳出击!
    }
    if (i<1 || i>L->length+1) {
        return ERROR;//位置不存在,搞啥?重拳出击!
    }
    if (i<=L->length) {
        for (k=L->length-1; k>=i-1; k--) { //-1是将位序变成数组下标
            L->data[k+1] = L->data[k];//给要插入的东西腾出空间
        }
    }
    L->data[i-1] = e;//把要放的数据放在空出来的地方
    L->length++;//长度增加了,加一下
    return OK;//顺利完成任务
}

//删除顺序表中特定位置的值
Status ListDelete(SqList *L, int i, ElemType *e) {
    int k;
    if (L->length == 0) {
        return ERROR;//你这个表是空的,没东西,删了个寂寞
    }
    if (i<1 || i>L->length) {
        return ERROR;//你要求删除的位置都不在,删了个寂寞
    }
    *e = L->data[i-1];//将要删除的东西存放在一个地方,而不是直接删除
    if (i<L->length) {
        for (k=i; k<L->length; k++) {
            L->data[k-1] = L->data[k];//将后面的东西排上去
        }
    }
    L->length--;//长度减一
    return OK;
}


