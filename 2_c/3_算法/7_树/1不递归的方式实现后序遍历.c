#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//这里的栈是用临时的数组来定义的,并没有专门封装成一个数据结构
typedef struct TreeNode* TreeNode;

// 定义二叉树结构体
struct TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
};

// 创建新节点
TreeNode createNode(int val) {
    TreeNode node = (TreeNode)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 插入节点到二叉树中
TreeNode insertNode(TreeNode root, int val) {
    if (root == NULL) {
        root = createNode(val);
        return root;
    }
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

void postorderTraversal(TreeNode root) {
    if (root == NULL) {
        return;
    }

    TreeNode stack[100];    // 定义原栈
    int top = -1;           // 初始化栈顶指针
    stack[++top] = root;

    TreeNode assistStack[100];      // 定义辅助栈
    int assistTop = -1;             // 初始化辅助栈顶指针

    while (top != -1) {     // 如果原栈不为空，则继续遍历
        TreeNode node = stack[top--];
        assistStack[++assistTop] = node;

        if (node->left != NULL) {
            stack[++top] = node->left;
        }
        if (node->right != NULL) {
            stack[++top] = node->right;
        }
    }

    while (assistTop != -1) {       // 遍历辅助栈并输出各个节点值
        printf("%d ", assistStack[assistTop--]->val);
    }
}

int main() {
    TreeNode root = NULL;
    const int nodeValues[] = {4, 2, 6, 1, 3, 5, 7};
    const int count = sizeof(nodeValues) / sizeof(int);

    for (int i = 0; i < count; ++i) {
        root = insertNode(root, nodeValues[i]);
    }

    postorderTraversal(root); // 后序遍历二叉树

    return 0;
}
