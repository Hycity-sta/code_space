#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void initStack(BStack s) {
    s->top = NULL;
    s->count = 0;
}

int isEmpty(BStack s) {
    return (s->top == NULL);
}

void Push(BStack s, Bnode x) {
    Snode p;
    p = malloc(sizeof(struct StackNode));
    p->data = x;
    p->next = s->top;
    s->top = p;
    s->count++;
}

Bnode Pop(BStack s) {
    Bnode p;
    p = s->top->data;
    s->top = s->top->next;
    s->count--;
    return p;
}
