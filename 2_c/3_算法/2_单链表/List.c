#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// 创建一个新的链表节点
ListNode* createNode(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 插入一个新的节点到链表头部
void addHead(ListNode** head, int val) {
    ListNode* newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

// 插入一个新的节点到链表尾部
void addTail(ListNode** head, int val) {
    ListNode* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    ListNode* p = *head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
}

// 删除链表中第一个值为val的节点
void deleteNode(ListNode** head, int val) {
    ListNode* p = *head;
    if (p == NULL) {
        return;
    }
    if (p->val == val) {
        *head = p->next;
        free(p);
        return;
    }
    while (p->next != NULL) {
        if (p->next->val == val) {
            ListNode* temp = p->next;
            p->next = temp->next;
            free(temp);
            return;
        }
        p = p->next;
    }
}

// 查找链表中第一个值为val的节点
ListNode* searchNode(ListNode* head, int val) {
    ListNode* p = head;
    while (p != NULL) {
        if (p->val == val) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// 输出链表中所有节点的值
void printList(ListNode* head) {
    ListNode* p = head;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

int main() {
    ListNode* head = NULL;

    // 测试插入和输出操作
    addHead(&head, 1);
    addHead(&head, 2);
    addTail(&head, 3);
    addTail(&head, 4);
    printf("Initial list: ");
    printList(head);

    // 测试删除操作
    deleteNode(&head, 2);
    printf("After deleting node with value 2: ");
    printList(head);

    // 测试查找操作
    ListNode* node = searchNode(head, 3);
    if (node != NULL) {
        printf("Found node with value 3.\n");
    } else {
        printf("Did not find node with value 3.\n");
    }

    return 0;
}
