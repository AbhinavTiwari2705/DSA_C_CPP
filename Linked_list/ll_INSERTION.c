#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int data;
    struct ListNode * next;
};

void traversal(struct ListNode* ptr){

    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

// case 01  Inserting at the beginning        
    // -> Time complexity:  O(1)

struct ListNode* ins_at_beginning(struct ListNode* head,int data){
    struct ListNode* ptr=(struct ListNode*)(malloc(sizeof(struct ListNode*)));
    ptr->data=data;
    ptr->next=head;
    return ptr;
    

}

// Case-02 Inserting in between->
// Time complexity : O(n)

struct ListNode* ins_btw(struct ListNode* head,int index,int data){
    struct ListNode * ptr =(struct ListNode*)(malloc(sizeof(struct ListNode*)));
    struct  ListNode * p = head;
    int i=0;

    while(i!=index-1){
        p=p->next;
        i++;

    }

    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;

    return head;


    
}

// case 3 Inserting at the end
// ->Time complexity : O(n)
struct ListNode * ins_after_node(struct ListNode* head,struct ListNode *prevNode,int data){
    struct ListNode * ptr=(struct ListNode *)malloc(sizeof(struct ListNode));
    ptr->data=data;

    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;


    
    
}
// Inserting at the end 
// -> Time complexity:  O(n)

struct ListNode *ins_at_end(struct ListNode *head,  int data)
{
    struct ListNode *ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
    ptr->data = data;

    struct ListNode* p=head;
     while(p->next!=NULL){
        p=p->next;
     }


     p->next=ptr;
     ptr->next=NULL;

    
    return head;
}

int main()
{
    struct ListNode * head=(struct ListNode*)(malloc(sizeof(struct ListNode)));
    
    struct ListNode * second=(struct ListNode*)(malloc(sizeof(struct ListNode)));
    struct ListNode * third=(struct ListNode*)(malloc(sizeof(struct ListNode)));
    struct ListNode * fourth=(struct ListNode*)(malloc(sizeof(struct ListNode)));
    struct ListNode * fifth=(struct ListNode*)(malloc(sizeof(struct ListNode)));

    head->data=7;
    head->next=second;
   
    second->data=37;
    second->next=third;

    third->data=97;
    third->next=fourth;

    fourth->data=74;
    fourth->next=fifth;

    fifth->data=98;
    fifth->next=NULL;

    traversal(head);
    head=ins_at_beginning(head,69);
    printf("\n");
    
    traversal(head);

    head=ins_btw(head,3,999);
    printf("\n");

    traversal(head);

    head = ins_after_node(head,second, 110);
    printf("\n");

    traversal(head);

    head = ins_at_end(head, 100000);
    printf("\n");

    traversal(head);

    return 0;
}