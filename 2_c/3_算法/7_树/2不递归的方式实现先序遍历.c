#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode* BNode;

// 定义二叉树结构体
struct TreeNode {
    int data;
    BNode left;
    BNode right;
};

// 创建新节点
BNode createNode(int val) {
    BNode node = (BNode)malloc(sizeof(struct TreeNode));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 插入节点到二叉树中
BNode insertNode(BNode root, int val) {
    if (root == NULL) {
        root = createNode(val);
        return root;
    }
    if (val < root->data)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);
    return root;
}



typedef struct StackNode* SNode;

// 定义链表节点结构体
// 这里单独封装了一个栈用来辅助二叉树的遍历实现
struct StackNode {
    BNode data;
    SNode next;
};

// 初始化栈
void initStack(SNode* s) {
    *s = NULL;
}

// 判断栈是否为空
int isEmpty(SNode s) {
    return s == NULL;
}

// 入栈
void push(SNode* s, BNode node) {
    SNode newNode = (SNode)malloc(sizeof(struct StackNode));
    newNode->data = node;
    newNode->next = *s;
    *s = newNode;
}

// 出栈
BNode pop(SNode* s) {
    if (isEmpty(*s)) return NULL;
    BNode node = (*s)->data;
    SNode temp = *s;
    *s = (*s)->next;
    free(temp);
    return node;
}

void preorderTraversal(BNode root) {
    if (root == NULL)
        return;
    SNode stack; // 声明一个栈
    initStack(&stack); // 初始化栈
    push(&stack, root); // 根节点入栈
    while (!isEmpty(stack)) {
        BNode node = pop(&stack);
        printf("%d ", node->data);
        // 先将右子树入栈，再将左子树入栈
        if (node->right != NULL) push(&stack, node->right);
        if (node->left  != NULL) push(&stack, node->left);
    }
}


int main() {
    BNode root = NULL;
    const int nodeValues[] = {4, 2, 6, 1, 3, 5, 7};
    const int count = sizeof(nodeValues) / sizeof(int);
    for (int i = 0; i < count; ++i) {
        root = insertNode(root, nodeValues[i]);
    }
    preorderTraversal(root); // 先序遍历二叉树
    return 0;
}
