#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define error 0
#define ok 1

#define maxsize

typedef int ElemType;
typedef int Status;
typedef struct Node * P_Node;
typedef P_Node List;

struct Node {
    ElemType data;
    P_Node next;  
};

/**
 *下面是一些对单链表进行的操作.
 *这里的单链表都是带空头结点的单链表.
 */

//初始化一段链表


//为一段链表赋值


//求这一段链表的表长


//按序号来查找链表中对应的值


//按值来查找链表中是否有对应的值,并返回这个节点的位置


//删除在链表中具体位置中的节点


