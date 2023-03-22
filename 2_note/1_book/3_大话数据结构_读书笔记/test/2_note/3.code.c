#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct Node * PtoNode;
typedef PtoNode LinkList;
//下面的都是带空头结点的单链表的处理方式
struct Node {
    ElemType data;//这个是数据域,存数据用的
    LinkList next;//这个是下一个表了,创建了下一个结构体
};

//大伙都叫node,就是结点的意思
/*
 * 要注意一下, 在链表里面, 空头结点的位置是i=0;
 * 第一个有数据的结点的位置是i=1;
 * 在传入函数里面的结点是空的头结点
 */
 
//获取链表第i个的值
//这里L是一个参数,相当于在内存中开辟了一个线性表, 传参数的时候就是将L指向已知的线性表,
//这样子就可以通过L来对原来的线性表进行操作了.
//这里是按位序来查找
Status GetElem(LinkList L, int i, ElemType *e) {
    int j;
    LinkList p;//声明一个节点是p,这个p就是下一个节点
    p = L->next;//让p指向下一个节点
    j = 1;
    while (p && j<i) {//下一个节点要存在才行,然后依次遍历,找到那个地方
        p = p->next;//一直进入下一个节点,在i之前停下,刚好就就指到i了
        j++;
    }
    if (!p) {
        //p不存在
        return ERROR;
    }
    *e = p->data;//没事的话就直接赋值给e
    return OK;//收工
}

//在链表第i个地方插入特定的值
//这个L是链表的头, 或者说空头结点
Status LinkInsert(LinkList L, int i, ElemType e) {
    int j;
    LinkList p, s;//搞两个节点出来,注意,这个是没有分配内存空间的
    p = L->next;//将p指向线性表的头结点
    j = 1;//设置位序为1

    //遍历链表,找到需要插入的位置
    while (p && j<i) {
        p = p->next;
        j++;
    }
    //循环结束时,p应该指向i位置的结点上
    if (!p || j>i) {
        return ERROR;//i位置上是空表,要么j这个数据出错了,实际上j这个数据经过上面的循环后是不会出错的
    }
    s = (LinkList)malloc(sizeof(struct Node));//给新结点分配一个内存空间
    s->data = e;      //设置一下新结点的数据域,填入要插入的数据
    s->next = p->next;//将新插入结点的下一个结点的地址设置为p的下一个结点的地址
    p->next = s;      //重置一下, 将p的地址指向新插入的结点
    return OK;
    //最后三步的操作顺序不能调换,画个图的话会好理解一点
    //而且一步到位,因为不用再开第三个结点来存放原来的p->next
}

//删除链表L的第i个元素
Status ListDelete(LinkList L, int i, ElemType *e){
    int j = 1;
    LinkList p,q;//还是开两个新的结点出来,便于操作
    p = L->next;//让p结点指向第一个非空结点

    while (p && j<(i-1)) {
        p = p->next;
        j++;
    }
    if (!p) {
        return ERROR;  //还是对不合理的操作重拳出击
    }

    q = p->next;       //然后用新的结点来存放要删除的结点
    p->next = q->next; //将q的后继赋值给p的后继
    *e = q->data;      //返回一下要删除结点的数据
    free(q);           //释放掉要删除结点的内存
    return OK;
}

//单链表的整表创建-头插法
//n是想要创建多少个结点
void CreateListHead(LinkList L, int n) {
    LinkList p;//新建一个节点
    int i;//这个是计数器
    L->next = NULL;//建立了一个带头结点的链表,
    for (i=0;i<n;i++) {
         p = (LinkList)malloc(sizeof(struct Node));
         p->data = 1; //随便填一个数字进去
         p->next = L->next;
         L->next = p;
    }
}

/* 头插法具体示意图
 * 这里还是再说明一下, ^表示的是空的, 也就是不存在
 * 空的头结点是说这个头结点不存数据,而不是说没有给他分配内存空间
 * 1. [L]->[^]
 * 2. [L]->[P]->[^]
 * 3. [L]->[P2]->[P]->[^]
 * 4. [L]->[P3]->[P2]->[P]->[^]
 * L是头结点, 一般情况下是的, 因为里面没有存数据和长度
 * 之后就是利用算法在尾结点前面一直插入新的结点
 * 不过因为新的结点一直在头结点之前插入,所以就叫头插法
 */

//单链表的整表创建-尾插法
//这个自然一点, 因为我们习惯在后面插入新的结点
void CreateListTail(LinkList L, int n) {
    LinkList p,r;
    int i;
    srand(time(0));
    L = (LinkList)malloc(sizeof(struct Node));
    r = L;
    for (i=0; i<n; i++) {
        p = (LinkList)malloc(sizeof(struct Node));
        p->data = rand()%100+1;
        r->next=p;
        r=p;
    }
    r->next = NULL; //记得最后的下一个指针要指向空的,因为没有了
}
/* 以下是尾插法的图示, 如果明白指针以及指针变量的赋值的话, 一切都变得很简单
 * [L]
 * [L]->[P1]
 * [L]->[P1]->[P2]
 * [L]->[P1]->[P2]->[P3]
 * [L]->[P1]->[P2]->[P3]->[^]
 */

//单链表的整表删除
Status ClearList(LinkList L) {
    LinkList p,q;
    p = L->next;
    while (p) {
        q = p->next;
        free(q);
        p = q;
    }
    L->next = NULL;
    return OK;
}

//两个链表合并成一个新的链表,并且里面的数据都是有序的
Status MerList(LinkList la, LinkList lb, LinkList lc) {
    int i,j,k;
    k = 1;
    while (la && lb) {
        if(la->data < lb->data) {
            lc->data = la->data;
        }
        else {
            lc->data = lb->data;
        }
    }
}

//下面这个操作是学校的教材上的, 不是这本大话数据结构上的, 先放在这里
//求一个链表的表长
int Length(LinkList L) {
    LinkList p;
    int cun = 0;
    p = L; //有这一步的原因是L本身是不能被改变的, 所以需要一个中间变量来进行操作
    while (p) {
        p = p->next;
        cun++;
    }
    printf("%d",cun-1);
    return cun-1;//不包括头结点
}

int main() {
    LinkList a;
    a = (LinkList)malloc(sizeof(struct Node));//给这个节点分配一个空间出来
    a->data=0;
    CreateListHead(a,3);
    printf("%d\n",a->next->data);
    Length(a);
    return 0;
}
