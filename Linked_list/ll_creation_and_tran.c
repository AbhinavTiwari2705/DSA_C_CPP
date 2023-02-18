#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int data;
    struct ListNode *next;
};

void Display(struct ListNode* ptr){

    while (ptr){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }

}

int main(){
    struct ListNode *head = (struct ListNode *)(malloc(sizeof(struct ListNode))) ;
    struct ListNode *second = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *third = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *fourth = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    
    head->data=7;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data = 41;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = NULL;

    Display(head);
}