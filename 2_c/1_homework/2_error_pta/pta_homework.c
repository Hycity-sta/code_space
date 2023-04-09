//pta作业
//这里输入的数组是有序递增的

#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

struct arr {
    int data[maxsize];
    int last;
};
typedef struct arr * ptoarr;
typedef ptoarr list;

void input(list,int);
void output(list,int);
void deal(list,list,list);

int main() {

    int n1,n2;

    list arr1 = (list)malloc(sizeof(struct arr));
    list arr2 = (list)malloc(sizeof(struct arr));
    list arr3 = (list)malloc(sizeof(struct arr));

    scanf("%d %d",&n1,&n2);
    arr1->last = n1;
    arr2->last = n2;
    input(arr1,n1);
    input(arr2,n2);
    deal(arr1,arr2,arr3);
    output(arr3,arr3->last);
}

//向数组内插入数据
void input(list ar, int n) {
    for (int i=0;i<n;i++)
        scanf("%d",&ar->data[i]);
}

//输出一整个数组
void output(list ar, int n) {
    for (int i=0;i<n;i++) {
        if (i==n-1) {
            printf("%d",ar->data[i]);
            break;
        }
        printf("%d ",ar->data[i]);
    }
}

//对数组进行处理
//将两个顺序表中同样的元素存入第三个表
void deal(list ar,list br, list cr) {
    int count=0;
    for (int i=0; i<ar->last;i++) {
        for (int k=0;k<br->last;k++) {
            if(ar->data[i] == br->data[k])
                cr->data[count++] = br->data[k];
        }
    }
    cr->last = count;
}
