#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 // 队列最大长度

// 定义队列结构体
typedef struct {
    int data[MAXSIZE]; // 存储元素的数组
    int front; // 队头指针
    int rear; // 队尾指针
} SeqQueue;

// 初始化队列
void initQueue(SeqQueue *queue) {
    queue->front = queue->rear = -1;
}

// 判断队列是否为空
int isQueueEmpty(SeqQueue *queue) {
    return queue->front == queue->rear;
}

// 判断队列是否已满
int isQueueFull(SeqQueue *queue) {
    return queue->rear == MAXSIZE - 1;
}

// 入队操作
int enQueue(SeqQueue *queue, int value) {
    if (isQueueFull(queue)) {
        printf("Queue is full\n");
        return 0;
    }
    queue->data[++queue->rear] = value;
    return 1;
}

// 出队操作
int deQueue(SeqQueue *queue, int *value) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return 0;
    }
    *value = queue->data[++queue->front];
    return 1;
}

// 获取队头元素
int getFront(SeqQueue *queue, int *value) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return 0;
    }
    *value = queue->data[queue->front + 1];
    return 1;
}

// 获取队列长度
int getQueueLength(SeqQueue *queue) {
    return queue->rear - queue->front;
}

// 测试代码
int main() {
    SeqQueue queue;
    initQueue(&queue);

    printf("Enqueue 1, 2, 3...\n");
    enQueue(&queue, 1);
    enQueue(&queue, 2);
    enQueue(&queue, 3);

    int value;
    getFront(&queue, &value);
    printf("Front element: %d\n", value);

    deQueue(&queue, &value);
    printf("Dequeue element: %d\n", value);

    getFront(&queue, &value);
    printf("Front element: %d\n", value);

    printf("Queue length: %d\n", getQueueLength(&queue));

    return 0;
}
