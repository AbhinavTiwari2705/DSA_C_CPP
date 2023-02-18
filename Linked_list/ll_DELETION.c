#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};
// case 1 Deleting the first node 
// -> Time complexity:  O(1)

struct ListNode * del_first(struct ListNode *head){
    struct ListNode* ptr=head;
    head=head->next;

    free(ptr);
    return head;

}

void traversal(struct ListNode *ptr)
{

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// Deleting a node in between
// ->Time complexity : O(n)
 
struct ListNode* del_btw(struct ListNode *head,int index){
    struct ListNode *p=head;
    
    struct ListNode *q=head->next;

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


struct ListNode *del_last(struct ListNode *head)
{
    struct ListNode *p=head;
    struct ListNode *q=head->next;

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

struct ListNode * del_val(struct ListNode *head,int value){
    struct ListNode *p = head;
    struct ListNode *q = head->next;

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

    struct ListNode *head = (struct ListNode *)(malloc(sizeof(struct ListNode)));

    struct ListNode *second = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *third = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *fourth = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *fifth = (struct ListNode *)(malloc(sizeof(struct ListNode)));

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