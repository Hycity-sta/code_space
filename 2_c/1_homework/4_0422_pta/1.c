#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define EMPTY -1 //用于空头结点的空值 

typedef int ElemType;

typedef struct Node * Ptolist;
typedef Ptolist Node;
struct Node {
    ElemType data;
    Node next;
};


typedef struct LinkQueue * PtoLinkQueue;
typedef PtoLinkQueue Queue;
struct LinkQueue {
    Node front,rear;
};

int count = 0;

//初始化一个队列, 头指针指的是头结点
Queue Init() {
    Queue q = (Queue)malloc(sizeof(struct LinkQueue));
    Node s = (Node)malloc(sizeof(struct Node));
    s->next = NULL;
    s->data = EMPTY;
    q->front = s;
    q->rear = s;
    return q;
}

//入队一个指定的元素
void EnQueue(Queue q, ElemType e) {
    Node s = (Node)malloc(sizeof(struct Node));
    s->data = e;
    s->next = NULL;
    q->rear->next = s; //将当前的队尾结点的下一个指向s
    q->rear = s; //更新对尾结点为现在的s
}

//出队位于队头的元素, 并打印出来
void OutQueue(Queue q) {
    if (q->front->next == NULL) { printf("\nerror:queue is empty"); return; }
    Node s = (Node)malloc(sizeof(struct Node));
    s = q->front->next;
    q->front->next = s->next;
    if (count == 0) { printf("%d",s->data); count++; }
    else printf(" %d", s->data);
    free(s);
}

void deal() {
    void OutQueue(Queue q);
    void EnQueue(Queue q, ElemType e);
    Queue Init();

    Queue A = Init();
    Queue B = Init();

    int N;
    int input;
    scanf("%d",&N);
    for (int i=0;i<N;i++) {
        scanf("%d",&input);
        if (input %2 == 0) EnQueue(B, input);
        else EnQueue(A,input);
    }

    while(A->front->next && B->front->next) {
        OutQueue(A);
        OutQueue(A);
        OutQueue(B);
    }

    while (A->front->next) OutQueue(A);
    while (B->front->next) OutQueue(B);

}


int main() {
    deal();
}
