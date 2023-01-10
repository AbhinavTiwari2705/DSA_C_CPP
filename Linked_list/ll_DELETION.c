#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
// case 1 Deleting the first node 
// -> Time complexity:  O(1)

struct Node * del_first(struct Node *head){
    struct Node* ptr=head;
    head=head->next;

    free(ptr);
    return head;

}

void traversal(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// Deleting a node in between
// ->Time complexity : O(n)
 
struct Node* del_btw(struct Node *head,int index){
    struct Node *p=head;
    
    struct Node *q=head->next;

    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }

    p->next=q->next;
    free(q);
    return head;
    
}
// Deleting the last node
// ->Time complexity : O(n)


struct Node *del_last(struct Node *head)
{
    struct Node *p=head;
    struct Node *q=head->next;

    while(q->next!=NULL){
        p=p->next;
        q=q->next;

    }

    p->next=NULL;
    free(q);
    return head;
}

// Deleting the element with a given value from the linked list
// ->Time complexity : O(n)

struct Node * del_val(struct Node *head,int value){
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
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

    second->data = 37;
    second->next = third;

    third->data = 97;
    third->next = fourth;

    fourth->data = 74;
    fourth->next = fifth;

    fifth->data = 98;
    fifth->next = NULL;

    traversal(head);
    printf("\n");
    head=del_first(head);

    traversal(head);
    printf("\n");

    head = del_btw(head,2 );

    traversal(head);
    printf("\n");

    head = del_last(head);

    traversal(head);
    printf("\n");

    head = del_val(head,97);

    traversal(head);
    printf("\n");

    return 0;
}