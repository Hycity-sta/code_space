// 这里的二叉树也是用先序遍历序列来创建的
// 用递归好处理, 每一层递归返回它自己以及自己的分支节点的个数

#include <stdio.h>
#include <stdlib.h>

typedef struct BinTreeNode * BinTree;
struct BinTreeNode {
    int data;
    BinTree lchild;
    BinTree rchild;
};

//求二叉树结点的个数
int NodeCount ( BinTree T) {
	if(T != NULL) 
        return (NodeCount(T->lchild) + NodeCount(T->rchild) + 1);
	return 0;
}



