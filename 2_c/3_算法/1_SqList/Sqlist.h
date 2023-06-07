#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef struct {
	int data[MAXSIZE];
	int length;
} SqList;

void initList(SqList * L);
void destroyList(SqList * L);
void clearList(SqList * L);

bool isEmpty(SqList L);
int getLength(SqList L);
bool getElem(SqList L, int i, int * e);
int getElemLocate(SqList L, int e);
bool getPriorElem(SqList L, int cur_e, int * pre_e);
bool getNextElem(SqList L, int cur_e, int * next_e);

bool insertElem(SqList * L, int i, int e);
bool delElem(SqList * L, int i, int * e);

void traverse(SqList L, void (*visit_)(int));
void visit(int e);
