#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//这里的栈是用临时的数组来定义的,并没有专门封装成一个数据结构
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

void postorderTraversal(BNode root) {
    if (root == NULL) return;

    BNode stack[100];    // 定义原栈
    int top = -1;           // 初始化栈顶指针
    stack[++top] = root;

    BNode assistStack[100];      // 定义辅助栈
    int assistTop = -1;             // 初始化辅助栈顶指针

    while (top != -1) {     // 如果原栈不为空，则继续遍历
        BNode node = stack[top--];
        assistStack[++assistTop] = node;

        if (node->left  != NULL) stack[++top] = node->left;
        if (node->right != NULL) stack[++top] = node->right;
    }

    while (assistTop != -1)       // 遍历辅助栈并输出各个节点值
        printf("%d ", assistStack[assistTop--]->data);
}

int main() {
    BNode root = NULL;
    const int nodeValues[] = {8,4,2,1,3,6,5,7,16,10,9,12,32,31,64};
    const int count = sizeof(nodeValues) / sizeof(int);

    for (int i = 0; i < count; ++i)
        root = insertNode(root, nodeValues[i]);

    postorderTraversal(root); // 后序遍历二叉树

    return 0;
}
