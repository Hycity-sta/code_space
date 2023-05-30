#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void PercDown(int *, int, int);
void beHeap(int *, int);
void arrtoString(int *, int);

int main(int argc, char *argv[]) {
    int a[] = {34,48,13,20,23,22};
    int a_total = sizeof(a)/sizeof(a[0]);

    beHeap(a,a_total);
    
    return 0;
}


void PercDown(int arr[], int root_in, int total) {
	int Par_in, Ch_in;
	int t;

	t = arr[root_in];

	for (Par_in = root_in; (Par_in * 2 + 1) < total; Par_in = Ch_in) {
		Ch_in = Par_in * 2 + 1;
		if ( (Ch_in != total - 1) && (arr[Ch_in] < arr[Ch_in + 1])) {
			Ch_in++;
		}
		if (t >= arr[Ch_in]) break;
		else arr[Par_in] = arr[Ch_in];
	}

	arr[Par_in] = t;
}

//将一个数组打印出来
void arrtoString(int * arr,int total) {
    for (int i=0;i<total;i++) {
        printf("%d ", arr[i]);
    }
}

void beHeap(int arr[], int total) {
    printf("befor is: ");
    arrtoString(arr,total);
    
	for (int i = total / 2 - 1; i >= 0; i--) {
		PercDown(arr, i, total);
	}
    
    printf("\nafter is: ");
    arrtoString(arr,total);
    printf("\n\n");
}
