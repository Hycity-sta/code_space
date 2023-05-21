#include <stdio.h>
#include <stdlib.h>

//这里只给出最基础的数据结构定义, 基本操作不给出了, 默认有就是了
typedef struct BintreeNode * BinTree;
struct BintreeNode {
    char Data;
    BinTree Left;
    BinTree Right;
};


// 包含了三种遍历的递归实现
// 还有一个层序遍历

void InorderTraversal(BinTree BT) {
	if (BT) {
		InorderTraversal(BT->Left);
		printf(" %c", BT->Data);
		InorderTraversal(BT->Right);
	}
}

void PreorderTraversal(BinTree BT) {
	if (BT) {
		printf(" %c", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

void PostorderTraversal(BinTree BT) {
	if (BT) {
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c", BT->Data);
	}
}

//用一个数组来模拟队列, 然后实现层序遍历
//不用新建一个队列结构体来实现队列了.
//如果有更高要求的话, 就要上队列了, 但是这里是算法处理
//主要是算法, 这个东西其实也不太完善, 看具体情况更改应用吧
void LevelorderTraversal(BinTree BT) {
	BinTree D[1000];
	BinTree T;
	int i = 0, j = 0; //用两个下标来模拟出队与入队
	if (!BT) 
        return;
	if (BT) {
		D[i++] = BT;
		while (i != j) {
			T = D[j++];
			printf(" %c", T->Data);
			if (T->Left) D[i++] = T->Left;//这里需要注意:在创建二叉树的时候,叶子结点后的左右结点必须做好处理, 不然容易输出失败
			if (T->Right) D[i++] = T->Right;
		}
	}
}
