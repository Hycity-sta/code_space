#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ERROR -1
#define OK 1

#define MAXSIZE 30

typedef int ElemType;
typedef int Status;
typedef int Position;
typedef struct Node *PtoNode;
typedef PtoNode List;

struct Node {
    ElemType data[MAXSIZE];
    Position Last;
};

/*
 * 以下是一些顺序表的操作函数
 * 初始化顺序表
 * 在顺序表中查找具体的一个值
 * 在顺序表中具体的一个位置中插入具体的一个值
 * 在顺序表中删除具体位置中的这个值
 * 输出顺序表
 * 将两个顺序表中的数据合并
 */

//初始化顺序表
List MakeEmpty() {
    List L;
    L = (List)malloc(sizeof(struct Node));
    L->Last = -1;
    return L;
}

//在顺序表中查找具体的一个值
Position Find(List L, ElemType x) {
    Position i = 0;
    while (i<=L->Last && L->data[i]!=x) {
        i++;
    }
    if (i>L->Last) {
        return ERROR;
    } 
    else {
        return i;
    }
}

//在顺序表中具体的一个位置中插入具体的一个值
bool Insert(List L, ElemType x, int i) {
    //从L的指定位序i前插入一个新元素x;位序i元素的数组位置下标是i-1
    Position j;

    if (L->Last == MAXSIZE-1){
    //表空间已满,不能插入
        printf("表满");
        return false;
    }
    if (i<1 || i>L->Last+2) {
        //检查插入位序的合法性,是否在1~n+1之间. n为当前元素个数,即Last+1
        printf("位序不合法");
        return false;
    }
    for(j=L->Last; j>=i-1;j--) {
        L->data[j+1] = L->data[j];
    }
    L->data[i-1] = x;
    L->Last++;
    return true;
}

//在顺序表中删除具体位置中的这个值
bool Delete(List YouList, int i) {
    //从L中删除指定位序i的元素,该元素数组下标为i-1
    Position j;
    if(i<1 || i>YouList->Last+1) {
        printf("位序%d不存在",i);//检查空表及删除位序的合法性
        return FALSE;
    }

    for (j=i;i<=YouList->Last;j++){
        YouList->data[j-1] = YouList->data[j];//将位序i+1及以后的元素顺序向前移动
    }
    YouList->Last--;//Last仍指向最后元素
    return true;
}

//为顺序表中的data数组赋值
List Input_list(List L, int n) {
    L->Last = n;
    for(int i = 0; i< L->Last; i++) {
        scanf("%d",&L->data[i]);
    }
    return L;
}

//输出顺序表
void Print_list(List L){
    for(int i=0;i<L->Last;i++){
        printf("%d ",L->data[i]);
    }
}


//将两个顺序表中的数据合并



int main(){
    List mylist = MakeEmpty();
    mylist = Input_list(mylist,5);
    Print_list(mylist);
    return 0;
}
