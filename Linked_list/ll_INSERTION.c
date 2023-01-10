#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void traversal(struct Node* ptr){

    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

// case 01  Inserting at the beginning        
    // -> Time complexity:  O(1)

struct Node* ins_at_beginning(struct Node* head,int data){
    struct Node* ptr=(struct Node*)(malloc(sizeof(struct Node*)));
    ptr->data=data;
    ptr->next=head;
    return ptr;
    

}

// Case-02 Inserting in between->
// Time complexity : O(n)

struct Node* ins_btw(struct Node* head,int index,int data){
    struct Node * ptr =(struct Node*)(malloc(sizeof(struct Node*)));
    struct  Node * p = head;
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
struct Node * ins_after_node(struct Node* head,struct Node *prevNode,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;


    
    
}
// Inserting at the end 
// -> Time complexity:  O(n)

struct Node *ins_at_end(struct Node *head,  int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node* p=head;
     while(p->next!=NULL){
        p=p->next;
     }


     p->next=ptr;
     ptr->next=NULL;

    
    return head;
}

int main()
{
    struct Node * head=(struct Node*)(malloc(sizeof(struct Node)));
    
    struct Node * second=(struct Node*)(malloc(sizeof(struct Node)));
    struct Node * third=(struct Node*)(malloc(sizeof(struct Node)));
    struct Node * fourth=(struct Node*)(malloc(sizeof(struct Node)));
    struct Node * fifth=(struct Node*)(malloc(sizeof(struct Node)));

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