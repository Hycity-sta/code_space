#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

//下面这个就是链表了
//专业一点就是线性表的链式存储
//链表本身根据一些特点也可以继续分类的,下面是单向链表,或者带头结点的单向链表
typedef struct Node {
    ElemType data;//这个是数据域,存数据用的
    struct Node *next;//这个是下一个表了,创建了下一个结构体
}Node;//大伙都叫node,就是结点的意思
typedef struct Node *LinkList; //用一个指针来指向这个结构体

//获取链表第i个的值
//这里L是一个参数,相当于在内存中开辟了一个线性表, 传参数的时候就是将L指向已知的线性表,
//这样子就可以通过L来对原来的线性表进行操作了.
Status GetElem(LinkList L, int i, ElemType *e) {
    int j;
    LinkList p;//声明一个节点是p,这个p就是下一个节点
    p = L->next;//让p指向下一个节点
    j = i;//i是位序哦
    while (p && j<i) {//下一个节点要存在才行,然后依次遍历,找到那个地方
        p = p->next;//一直进入下一个节点,在i之前停下,刚好就就指到i了
        ++j;
    }
    if (!p || j>i) {//p不存在或者一直遍历到最后了,就说明没找到
        return ERROR;//如果循环结束,根据条件来返回错误
    }
    *e = p->data;//没事的话就直接赋值给e
    return OK;//收工
}

//在链表第i个地方插入特定的值
//这儿又有指针了, 从上下文来判断的话还是用上面的那个链表
//不过日常使用的时候就看情况了传什么东西进去了
//这个L是链表的头, 或者说头结点
Status LinkInsert(LinkList *L, int i, ElemType e) {
    int j;
    LinkList p, s;//搞两个节点出来
    p = *L;//将p指向线性表的头结点
    j = 1;//设置位序为1
    while (p && j < i) {
        p = p->next;//找到那个地方再哪
        ++j;
    }
    if (!p || j > i) {
        return ERROR;//对于不合理的操作重拳出击!
    }
    s = (LinkList)malloc(sizeof(Node));//给新结点分配一个内存空间
    s->data = e;//设置一下新结点的数据域,填入要插入的数据
    s->next = p->next;//将新插入结点的下一个结点的地址设置为p的下一个结点的地址
    p->next = s;//重置一下, 将p的地址指向新插入的结点
    return OK;
    //最后三步的操作顺序不能调换,画个图的话会好理解一点
    //而且一步到位,因为不用再开第三个结点来存放原来的p->next
}

//删除链表L的第i个元素
Status ListDelete(LinkList *L, int i, ElemType *e){
    int j;
    LinkList p,q;//还是开两个新的结点出来,便于操作
    p = *L;//让p结点变为链表的头结点
    j = 1;
    while (p->next && j<i) {//p的下一个结点要存在才行,这个与上面的不一样
        p = p->next;//还是先找到那个地方
        ++j;
    }
    if (!(p->next) || j>i) {
        return ERROR;//还是对不合理的操作重拳出击
    }
    q = p->next;//然后用新的结点来存放要删除的结点
    p->next = q->next; //将q的后继赋值给p的后继
    *e = q->data;//返回一下要删除结点的数据
    free(q);//释放掉要删除结点的内存
    return OK;//这里的链表是带有空的头结点的, 所以在计算的时候注意一下i的值
}

//单链表的整表创建-头插法
void CreateListHead(LinkList *L, int n) {
    LinkList p;//新建一个节点
    int i;//这个是计数器
    srand(time(0));//初始化随机数种子
    *L = (LinkList)malloc(sizeof(Node));//给这个节点分配一个空间出来
    (*L)->next = NULL;//建立了一个带头结点的链表,
    for (i=0;i<n;i++) {
         p = (LinkList)malloc(sizeof(Node));
         p->data = rand()%100+1;
         p->next = (*L)->next;
         (*L)->next = p;
    }
}

//单链表的整表创建-尾插法
void CreateListTail(LinkList *L, int n) {
    LinkList p,r;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L;
    for (i=0; i<n; i++) {
        p = (Node *)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next=p;
        r=p;
    }
    r->next = NULL;
}

//单链表的整表删除
Status ClearList(LinkList *L) {
    LinkList p,q;
    p = (*L)->next;
    while (p) {
        q=p->next;
        free(q);
        p=q;
    }
    (*L)->next = NULL;
    return OK;
}
