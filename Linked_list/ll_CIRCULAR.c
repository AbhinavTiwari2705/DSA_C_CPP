#include<stdio.h>
#include<stdlib.h>


struct Node
{

    int data;
    struct Node *next;
};

void travesal(struct Node* head){
    struct Node *p=head;
    do{
        printf("%d ",p->data);
        
        p=p->next;
    }while(p!=head);

    
}

struct Node* ins_first(struct Node* head,int data){
    struct Node *p=head->next;
    struct Node* ptr= (struct Node*)(malloc(sizeof(struct Node)));
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
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

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