#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define EMPTY -1 //用于空头结点的空值 

typedef int ElemType;
typedef int Status;

typedef struct Node * Ptolist;
typedef Ptolist Node;
struct Node {
    ElemType data;
    Node next;
};


typedef struct LinkQueue * PtoLinkQueue;
typedef PtoLinkQueue queue;
struct LinkQueue {
    Node front,rear;
};

//创建一个带头结点的空队列
//空队列中的front和rear都指向空的头结点
queue InitLinkQueue(queue q, Node s) {
    q = (queue)malloc(sizeof(struct LinkQueue));
    s = (Node)malloc(sizeof(struct Node));
    s->next = NULL;
    s->data = EMPTY;
    q->front = s;
    q->rear = s;
    return q;
}

Status EnQueue(queue q, ElemType e) {
    Node s = (Node)malloc(sizeof(struct Node));
    s->data = e;
    s->next = NULL;
    q->rear->next = s; //将当前的队尾结点的下一个指向s
    q->rear = s; //更新对尾结点为现在的s
    return OK;
}

Status DeQueue(queue q, ElemType *e) {
    Node p;
    if (q->front==q->rear)
        return ERROR;
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;

    if (q->rear == p)
        q->rear = q->front; //队列中只有一个元素的情况下, 出队后就没有元素了, 所以要将rear指回空头结点
    free(p);
    return OK;
}

int main() {
    Node myNode;
    queue myqueue = InitLinkQueue(myqueue, myNode);
    EnQueue(myqueue,3);
    int e;
    //DeQueue(myqueue,&e);
    printf("%d",myqueue->rear->data);
    return 0;
}

