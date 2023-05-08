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



typedef struct StackNode* StackNode;

// 定义链表节点结构体
// 这里单独封装了一个栈用来辅助二叉树的遍历实现
struct StackNode {
    TreeNode data;
    StackNode next;
};

// 初始化栈
void initStack(StackNode* s) {
    *s = NULL;
}

// 判断栈是否为空
int isEmpty(StackNode s) {
    return s == NULL;
}

// 入栈
void push(StackNode* s, TreeNode node) {
    StackNode newNode = (StackNode)malloc(sizeof(struct StackNode));
    newNode->data = node;
    newNode->next = *s;
    *s = newNode;
}

// 出栈
TreeNode pop(StackNode* s) {
    if (isEmpty(*s)) {
        return NULL;
    }
    TreeNode node = (*s)->data;
    StackNode temp = *s;
    *s = (*s)->next;
    free(temp);
    return node;
}

void preorderTraversal(TreeNode root) {
    if (root == NULL)
        return;
    StackNode stack; // 声明一个栈
    initStack(&stack); // 初始化栈
    push(&stack, root); // 根节点入栈
    while (!isEmpty(stack)) {
        TreeNode node = pop(&stack);
        printf("%d ", node->val);
        // 先将右子树入栈，再将左子树入栈
        if (node->right != NULL) {
            push(&stack, node->right);
        }
        if (node->left != NULL) {
            push(&stack, node->left);
        }
    }
}




int main() {
    TreeNode root = NULL;
    const int nodeValues[] = {4, 2, 6, 1, 3, 5, 7};
    const int count = sizeof(nodeValues) / sizeof(int);
    for (int i = 0; i < count; ++i) {
        root = insertNode(root, nodeValues[i]);
    }
    preorderTraversal(root); // 先序遍历二叉树
    return 0;
}
