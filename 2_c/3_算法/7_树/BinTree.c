#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;
typedef struct TNode * Position;
typedef Position BinTree;
//二叉树的链表结构
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

//二叉树的中序遍历
void InorderTraversal(BinTree BT) {
    if (BT) {
        InorderTraversal(BT->Left);
        printf("%d",BT->Data);
        InorderTraversal(BT->Right);
    }
}

//二叉树的先序遍历
void PreorderTraversal(BinTree BT) {
    if (BT) {
        printf("%d",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

//二叉树的后序遍历
void PostorderTraversal(BinTree BT) {
    if (BT) {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf("%d",BT->Data);
    }
}

//二叉树的中序遍历的非递归实现
void InorderTraversal_(BinTree BT) {
    BinTree T;
    Stack S = CreateStack();
    T = BT;
    while (T || !isEmpty(S)) {
        while (T) {
            Push(S,T);
            T = T->Left;
        }
        T = Pop(S);
        printf("%d",T->Data);
        T = T->Right;
    }
}

int main(int argc, char *argv[])
{
    
    return 0;
}
