#include "Sqlist.h"

int main() {
    
	SqList myList;
	int e = 0, pre_e = 0, next_e = 0;

	initList(&myList);

	insertElem(&myList, 1, 5);
	insertElem(&myList, 2, 7);
	insertElem(&myList, 3, 3);
    
	printf("List is Empty?: %d\n", isEmpty(myList));
	printf("ListLength: %d\n", getLength(myList));

	traverse(myList, visit);
	printf("\n");
	printf("\n");

	getElem(myList, 2, &e);
	printf("GetElem: %d\n", e);

	printf("LocateElem: %d\n", getElemLocate(myList, 7));

	getPriorElem(myList, 7, &pre_e);
	printf("PriorElem: %d\n", pre_e);

	getNextElem(myList, 7, &next_e);
	printf("NextElem: %d\n", next_e);

	delElem(&myList, 2, &e);
	traverse(myList, visit);
	printf("\n");
	printf("\n");

	clearList(&myList);
	printf("List is Empty?: %d\n", isEmpty(myList));

	return 0;
}

