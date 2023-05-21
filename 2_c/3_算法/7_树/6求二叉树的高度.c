#include <stdio.h>
#include <stdlib.h>

typedef struct BinTreeNode * BinTree;
struct BinTreeNode {
    int Data;
    BinTree Left;
    BinTree Right;
};


//用递归来求二叉树的高度
//这个画一个图就好明白了,画一个两层的还有一个三层的满二叉树就懂了
//如果不存在结点,就是0, 叶子结点的为1, 一直往上层递增
int GetHeight(BinTree BT) {
    int HL, HR, MaxH;
    if (BT) {
        HL = GetHeight(BT->Left);
        HR = GetHeight(BT->Right);
        MaxH = HL>HR ? HL:HR;
        return (MaxH+1);
    } 
    else {
        return 0;
    }
}
