#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode* BNode;
//这里没有单独封装一个结构体用来实现栈
// 定义二叉树结构体
struct TreeNode {
    int val;
    BNode left;
    BNode right;
};

// 创建新节点
BNode createNode(int val) {
    BNode node = (BNode)malloc(sizeof(struct TreeNode));
    node->val = val;
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
    if (val < root->val)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);
    return root;
}

// 中序遍历二叉树（非递归实现）
void inorderTraversal(BNode root) {
    if (root == NULL) return;

    // 定义一个栈来维护节点的访问顺序
    BNode stack[100];
    int top = -1;

    while (1) {
        // 将所有左子节点推入栈中
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }
        // 如果栈为空，则遍历结束
        if (top == -1) break;
        // 弹出栈顶元素并输出
        root = stack[top--];
        printf("%d ", root->val);
        // 访问右子节点
        root = root->right;
    }
}

int main() {
    BNode root = NULL;
    const int nodeValues[] = {4, 2, 6, 1, 3, 5, 7};
    const int count = sizeof(nodeValues) / sizeof(int);

    for (int i = 0; i < count; ++i) { root = insertNode(root, nodeValues[i]); }

    inorderTraversal(root); // 中序遍历二叉树

    return 0;
}
