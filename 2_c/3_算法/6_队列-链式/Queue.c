#include <stdio.h>
#include <stdlib.h>

// 链表节点结构体
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 队列结构体
typedef struct Queue {
    Node *front; // 队首指针
    Node *rear; // 队尾指针
} Queue;

// 初始化队列
void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// 判断队列是否为空
int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

// 入队
void enQueue(Queue *queue, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if(queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// 出队
int deQueue(Queue *queue) {
    if(isEmpty(queue)) {
        printf("队列已空，无法出队\n");
        exit(1);
    }
    Node *tmp = queue->front;
    int data = tmp->data;
    queue->front = tmp->next;
    if(queue->front == NULL) {
        queue->rear = NULL;
    }
    free(tmp);
    return data;
}

// 获取队首元素
int getFront(Queue *queue) {
    if(isEmpty(queue)) {
        printf("队列已空\n");
        exit(1);
    }
    return queue->front->data;
}

// 获取队尾元素
int getRear(Queue *queue) {
    if(isEmpty(queue)) {
        printf("队列已空\n");
        exit(1);
    }
    return queue->rear->data;
}

// 打印队列元素
void printQueue(Queue *queue) {
    if(isEmpty(queue)) {
        printf("队列为空\n");
        return;
    }
    Node *tmp = queue->front;
    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    Queue queue;
    initQueue(&queue); // 初始化队列
    enQueue(&queue, 10); // 入队
    enQueue(&queue, 20);
    enQueue(&queue, 30);
    printQueue(&queue); // 打印队列中的元素
    printf("队首元素：%d\n", getFront(&queue)); // 获取队首元素
    printf("队尾元素：%d\n", getRear(&queue)); // 获取队尾元素
    deQueue(&queue); // 出队
    printQueue(&queue); // 打印队列中的元素
    return 0;
}
