#include <stdio.h>
#include <stdlib.h>

//定义链表节点结构体
struct ListNode {
    int data; //数据域
    struct ListNode *next; //指针域
};

//定义栈结构体
typedef struct {
    struct ListNode *top; //栈顶指针
} Stack;

//初始化栈
void initStack(Stack *s) {
    s->top = NULL; //将栈顶指针设为NULL即可
}

//判断栈是否为空
int isEmpty(Stack *s) {
    return (s->top == NULL);
}

//入栈操作
void push(Stack *s, int x) {
    struct ListNode *p;
    p = (struct ListNode*)malloc(sizeof(struct ListNode)); //动态分配内存
    p->data = x; //给新节点赋值
    p->next = s->top; //将新节点插入到链表头部
    s->top = p; //更新栈顶指针
}

//出栈操作
int pop(Stack *s) {
    int x;
    struct ListNode *p;
    if (isEmpty(s)) { //如果栈为空，则无法进行出栈操作
        printf("Stack is empty.\n");
        exit(1); //退出程序
    }
    else {
        p = s->top; //指向栈顶节点
        x = p->data; //获取该节点的值
        s->top = p->next; //将栈顶指针下移一位
        free(p); //释放节点内存
        return x; //返回该节点的值
    }
}

//获取栈顶元素
int getTop(Stack *s) {
    if (isEmpty(s)) { //如果栈为空，则无法获取栈顶元素
        printf("Stack is empty.\n");
        exit(1); //退出程序
    }
    else {
        return s->top->data; //返回栈顶节点的值
    }
}

//打印栈中所有元素
void printStack(Stack *s) {
    struct ListNode *p;
    p = s->top; //指向栈顶节点
    while (p != NULL) { //遍历整个链表
        printf("%d ", p->data);
        p = p->next; //指针后移
    }
    printf("\n");
}

int main() {
    Stack s; //定义一个空栈
    initStack(&s); //初始化栈
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("Stack: ");
    printStack(&s); //输出栈中所有元素
    printf("Top element: %d\n", getTop(&s)); //输出栈顶元素
    pop(&s);
    printf("Stack after pop: ");
    printStack(&s); //输出栈中所有元素
    return 0;
}
