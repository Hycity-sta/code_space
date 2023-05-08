#include <stdlib.h>
#include <stdio.h>


typedef struct TreeNode * BNode;
// 定义二叉树结构体
struct TreeNode {
    int val;
    BNode left;
    BNode right;
};


// 创建新节点
BNode createNode(int val) {
    BNode node = malloc(sizeof(struct TreeNode));
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
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

//二叉树的中序遍历
void InorderTraversal(BNode BT) {
    if (BT) {
        InorderTraversal(BT->left);
        printf("%d",BT->val);
        InorderTraversal(BT->right);
    }
}

//二叉树的先序遍历
void PreorderTraversal(BNode BT) {
    if (BT) {
        printf("%d",BT->val);
        PreorderTraversal(BT->left);
        PreorderTraversal(BT->right);
    }
}

//二叉树的后序遍历
void PostorderTraversal(BNode BT) {
    if (BT) {
        PostorderTraversal(BT->left);
        PostorderTraversal(BT->right);
        printf("%d",BT->val);
    }
}


int main(int argc, char *argv[])
{
    
    return 0;
}
