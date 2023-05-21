// 这个二叉树是由前序遍历序列的方式创建的
// 这里求叶子结点的方式是在二叉树的前序遍历的基础上进行了一些改装

#include <stdio.h>
#include <stdlib.h>
typedef struct BinTreeNode * BinTree;
struct BinTreeNode {
    int Data;
    BinTree Left;
    BinTree Right;
};

//用先序遍历的改进
void InorderPrintLeaves( BinTree T) {
	if(T==NULL) return ;

	InorderPrintLeaves(T->Left);

	if(T->Left==NULL&&T->Right==NULL) //叶子结点的两个分支都是空的
        printf(" %c",T->Data); 

	InorderPrintLeaves(T->Right);
}
