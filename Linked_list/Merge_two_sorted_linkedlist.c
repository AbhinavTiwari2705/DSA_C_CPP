#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
    
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *ptr1 = head;
    struct ListNode *ptr2 = head->next;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    while (ptr2 != NULL)
    {
        printf("ptr1=%d\n", ptr1->val);
        printf("ptr2=%d\n", ptr2->val);
        if (ptr1->val == ptr2->val)
        {
            ptr2 = ptr2->next;
            ptr1->next = ptr2;
        }
        else
        {
            ptr1->next = ptr2;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

       
    }

    return head;
}

void Display(struct ListNode *ptr)
{

    while (ptr)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{

    if (list2 == NULL) return list1;
    if (list1 == NULL) return list2;
    


    struct ListNode *head=list1;

    if (list1->val < list2->val)
    {
        head = list2;
        list2 = list2->next;
    }

    else
    {
        
        list1 = list1->next;
    }
    struct ListNode *current = head;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {

            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;

        // printf("current%d\n",current->val);
        // printf("l1%d\n",list1->val);
        // printf("l2%d\n",list2->val);
    }
    
    if (list1 != NULL)
    {
        current->next = list1;
    }
    if (list2 != NULL)
    {
        current->next = list2;
    }

    return head;
}

int main()
{
    struct ListNode *head = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *second = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *third = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *fourth = (struct ListNode *)(malloc(sizeof(struct ListNode)));

    head->val = 1;
    head->next = second;

    second->val = 4;
    second->next = third;

    third->val = 4;
    third->next = fourth;

    fourth->val = 6;
    fourth->next = NULL;

    struct ListNode *head1 = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *second1 = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *third1 = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    struct ListNode *fourth1 = (struct ListNode *)(malloc(sizeof(struct ListNode)));

    head1->val = 1;
    head1->next = second1;

    second1->val = 3;
    second1->next = third1;

    third1->val = 4;
    third1->next = fourth1;

    fourth1->val = 6 ;
    fourth1->next = NULL;

    

    // Display(mergeTwoLists(head1, head));
    Display(deleteDuplicates(head));
    // deleteDuplicates(head);

    return 0;
}