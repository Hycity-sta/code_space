#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ERROR -1
#define OK 1

#define MAXSIZE 30

typedef int ElemType;
typedef int Position;
typedef struct Node *PtoNode;
typedef PtoNode List;

struct Node {
    ElemType data[MAXSIZE];
    Position Last;//这里是数组最后一个元素的下标
    int Length;
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
    List YouList;
    YouList = (List)malloc(sizeof(struct Node));//记得需要创建一个内存空间分配给这个顺序表
    YouList->Last = -1;
    return YouList;
}

//在顺序表中查找具体的一个值,返回这个位置
Position Find(List YouList, ElemType x) {
    Position i = 0;
    while (i<=YouList->Last && YouList->data[i]!=x) {
        i++;
    }
    if (i>YouList->Last) {
        return ERROR;
    } 
    else {
        return i;
    }
}

//在顺序表中具体的一个位置中插入具体的一个值
bool Insert(List YouList, ElemType x, int i) {
    Position j;
    if (YouList->Last == MAXSIZE-1){
        printf("error: this list is full");
        return false;
    }
    if (i<1 || i>YouList->Last+2) {
        printf("位序不合法");
        return false;
    }
    for(j=YouList->Last; j>=i-1;j--) {
        YouList->data[j+1] = YouList->data[j];
    }
    YouList->data[i-1] = x;
    YouList->Last++;
    return true;
}

//在顺序表中删除具体位置中的这个值
//i是位序
bool Delete(List YouList, int i) {
    Position j;
    if(i<1 || i>YouList->Last+1) {
        printf("位序%d不存在",i);//检查空表及删除位序的合法性
        return false;
    }

    for (j=i;i<=YouList->Last;j++){
        YouList->data[j-1] = YouList->data[j];//将位序i+1及以后的元素顺序向前移动
    }
    YouList->Last--;//Last仍指向最后元素
    return true;
}

//为顺序表中的data数组赋值
bool Input_list(List YouList, int n) {
    YouList->Last = n-1;
    YouList->Length = n;
    for(int i = 0; i< n; i++) {
        scanf("%d",&YouList->data[i]);//记得带地址符
    }
    printf("\n");
    return true;
}

//输出顺序表
void Print_list(List YouList){
    for(int i=0;i<YouList->Last+1;i++){
        printf("%d ",YouList->data[i]);
    }
    printf("\n");
}


//将两个顺序表中的数据合并
void MergeList(List YouListA, List YouListB, List YouListC) {
    int i,j,k;
    i = j = 0;
    k = 1;
    while((i<YouListA->Length) && (j < YouListB->Length)) {
        if (YouListA->data[i] < YouListB->data[j]) {
            Insert(YouListC, YouListA->data[i++], k++);
        }
        else {
            Insert(YouListC, YouListB->data[j++], k++);
        }
    }

    while (i< YouListA->Length) {
        Insert(YouListC, YouListA->data[i++], k++);
    }
    while (j < YouListB->Length) {
        Insert(YouListC, YouListB->data[j++], k++);
    }
}


int main(){
    system("chcp 65001");
    List la = MakeEmpty();
    List lb = MakeEmpty();
    List lc = MakeEmpty();
    int n1,n2;

    printf("输入n1: \n");
    scanf("%d",&n1);
    printf("输入la: \n");
    Input_list(la,n1);

    printf("输入n2: \n");
    scanf("%d",&n2);
    printf("输入lb: \n");
    Input_list(lb,n2);

    Print_list(lb);
    Print_list(la);

    MergeList(la,lb,lc);
    printf("顺序表c现在是:\n");
    Print_list(lc);
    
    return 0;
}
