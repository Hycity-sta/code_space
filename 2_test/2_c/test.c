#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define FALSE 0
#define OK 1
#define TRUE 1
#define MAXSIZE 100
typedef int ElemType;
typedef int Status;

struct list{
    ElemType data[MAXSIZE];
    int length;
};
typedef struct list *p;

int main() {
    p st;
    st->length=4;
    printf("%d",st->length);
    return 0;
}

