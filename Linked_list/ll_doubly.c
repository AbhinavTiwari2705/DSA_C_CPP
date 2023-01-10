#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void traversal(struct Node* head){
    struct Node* ptr = head;
    while(ptr != NULL ){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}



int main()
{
    struct Node *head = (struct Node *)(malloc(sizeof(struct Node)));

    struct Node *second = (struct Node *)(malloc(sizeof(struct Node)));
    struct Node *third = (struct Node *)(malloc(sizeof(struct Node)));
    struct Node *fourth = (struct Node *)(malloc(sizeof(struct Node)));
    struct Node *fifth = (struct Node *)(malloc(sizeof(struct Node)));

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