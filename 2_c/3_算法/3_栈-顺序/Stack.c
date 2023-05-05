#include <stdio.h>
#include <stdlib.h>

// 定义栈的结构体
typedef struct {
    int *data;  // 存储元素的数组指针
    int top;    // 栈顶指针
    int size;   // 栈的最大容量
} Stack;

// 初始化一个空栈
void init(Stack *s, int size) {
    s->data = (int *)malloc(sizeof(int) * size);
    s->top = -1;
    s->size = size;
}

// 判断栈是否为空
int is_empty(Stack *s) {
    return s->top == -1;
}

// 判断栈是否已满
int is_full(Stack *s) {
    return s->top == s->size - 1;
}

// 将元素item压入栈顶
void push(Stack *s, int item) {
    if (is_full(s)) {
        printf("Error: stack is full\n");
        return;
    }
    s->top++;
    s->data[s->top] = item;
}

// 弹出并返回栈顶元素
int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Error: stack is empty\n");
        exit(1);
    }
    int item = s->data[s->top];
    s->top--;
    return item;
}

// 返回栈顶元素但不弹出
int peek(Stack *s) {
    if (is_empty(s)) {
        printf("Error: stack is empty\n");
        exit(1);
    }
    return s->data[s->top];
}

// 返回栈中元素的个数
int size(Stack *s) {
    return s->top + 1;
}
