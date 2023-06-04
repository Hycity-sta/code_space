#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char option[20];
	int flag = 1;
	while (flag == 1) {
		system("cls");
		printf("--------this is a menu-------\n");
		printf("please enter your choice:");
		gets(option);
		if (strcmp(option, "1") == 0) {
			printf("function 1 was called.....\n");
		} else if (strcmp(option, "2") == 0) {
			printf("function 2 was called.....\n");
		} else if (strcmp(option, "3") == 0) {
			printf("function 3 was called.....\n");
		} else if (strcmp(option, "4") == 0) {
			printf("thank you for your operation....\n");
			flag = 0;
		} else {
			printf("your input is error, please input an integer from 1 to 4...\n");
		}

		system("pause");
	}
	return 0;
}
