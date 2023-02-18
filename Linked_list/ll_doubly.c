#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
    struct ListNode *prev;
};

void traversal(struct ListNode* head){
    struct ListNode* ptr = head;
    while(ptr != NULL ){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}



int main()
{
    struct ListNode *head = (struct ListNode *)(malloc(sizeof(struct ListNode)));

    struct ListNode *second = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *third = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *fourth = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *fifth = (struct ListNode *)(malloc(sizeof(struct ListNode)));

    head->data = 7;
    head->next = second;
    head->prev = NULL;

    second->data = 37;
    second->next = third;
    second->prev = head;

    third->data = 97;
    third->next = fourth;
    third->prev = second;

    fourth->data = 74;
    fourth->next = fifth;
    fourth->prev = third;

    fifth->data = 98;
    fifth->next = NULL;
    fifth->prev = fourth;
    traversal(head);

    

    return 0;
}