#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode * Snode;
typedef struct BinTreeNode * Bnode;

struct StackNode {
    Bnode data;
    Snode next;
};

struct BinTreeNode {
    int val;
    Snode left;
    Snode right;
};

struct BStack_ {
    Snode top;
    int count;
};
typedef struct BStack_ * BStack;

