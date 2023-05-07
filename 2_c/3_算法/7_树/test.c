#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// 中序遍历二叉树
void inorderTraversal(TreeNode root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode root = NULL;
    const int nodeValues[] = {4, 2, 6, 1, 3, 5, 7};
    const int count = sizeof(nodeValues) / sizeof(int);

    // 记录程序开始执行的时间
    clock_t startTime = clock();

    for (int i = 0; i < count; ++i) {
        root = insertNode(root, nodeValues[i]);
    }

    // 记录程序结束执行的时间
    clock_t endTime = clock();
    
    inorderTraversal(root); // 中序遍历二叉树

    double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("\nTotal time taken by the program is %lf seconds\n", totalTime);
    return 0;
}
