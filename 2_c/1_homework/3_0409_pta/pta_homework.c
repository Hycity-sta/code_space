//向一个链表输入数据, 然后求出倒数第n个元素
//输入的第一个是n, 之后输入要存入链表的数据,以-1结尾, -1不存入链表
//这里的代码是爆改网络上一个大佬的
#include<stdio.h>
#include<stdlib.h>
//EOF在io头文件里面宏定义成了-1
struct node{
	int date;
	struct node* next;
};

int main(){
	struct node* list = (struct node*)malloc(sizeof(struct node));
	list->date = 0x7fffffff;
	list->next = NULL;

	long long k;
	scanf("%lld",&k);

	int date;//用户输入
    //头插法创建链表然后输入数据
	while(scanf("%d",&date)!=EOF && date>=0){
		struct node* newnode = (struct node*)malloc(sizeof(struct node));
		newnode->date = date;
		newnode->next = list->next;
		list->next = newnode;
	}

	long long count = 1;//计数器
	struct node* p = list->next;//第一个有数据的结点

	while(p!=NULL){
		if(count==k)break;
		else {
			count++;
            p = p->next;
        }
	}
	if(p!=NULL) printf("%d",p->date);
	else printf("NULL");
	return 0;
}


