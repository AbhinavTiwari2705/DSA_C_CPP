#include<stdio.h>
#include<stdlib.h>


struct ListNode
{

    int data;
    struct ListNode *next;
};

void travesal(struct ListNode* head){
    struct ListNode *p=head;
    do{
        printf("%d ",p->data);
        
        p=p->next;
    }while(p!=head);

    
}

struct ListNode* ins_first(struct ListNode* head,int data){
    struct ListNode *p=head->next;
    struct ListNode* ptr= (struct ListNode*)(malloc(sizeof(struct ListNode)));
    ptr->data=data;
     while (p->next != head){
        p=p->next;
     }

    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}


int main()
{
    struct ListNode *head;
    struct ListNode *second;
    struct ListNode *third;
    struct ListNode *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    second = (struct ListNode *)malloc(sizeof(struct ListNode));
    third = (struct ListNode *)malloc(sizeof(struct ListNode));
    fourth = (struct ListNode *)malloc(sizeof(struct ListNode));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = head;

    travesal(head);
    printf("\n");

    head=ins_first(head,90);
    travesal(head);
    printf("\n");

    return 0;
}