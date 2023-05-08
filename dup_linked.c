// Given the head of a sorted linked list,
// delete all duplicates such that each element appears only once.
// Return the linked list sorted as well.

// Input: head = [1,1,2]
// Output: [1,2]

// Input: head = [1,1,2,3,3]
// Output: [1,2,3]


#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
      int val;
     struct ListNode *next;
 } ListNode;

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head || !(head->next))
        return (head);

    int s = head->val;
    struct ListNode *hhead = head;
    struct ListNode *track = head;
    head = head->next;
    while(head)
    {
        if (head->val == s)
        {
            track->next = head->next;
            struct ListNode *save = head;
            head=head->next;
            free(save);
        }
        else
        {
            s = head->val;
            track = head;
            head = head->next;
        }
    }
    return (hhead);
}

int main()
{
    ListNode *ok = malloc(sizeof(ListNode));
    ok->val = 1;
    ok->next = malloc(sizeof(ListNode));
    ok->next->val = 1;
    ok->next->next = malloc(sizeof(ListNode));
    ok->next->next->val = 1;
    ok->next->next->next = malloc(sizeof(ListNode));
    ok->next->next->next->val = 2;
    ok->next->next->next->next = malloc(sizeof(ListNode));
    ok->next->next->next->next->val = 3;
    ok->next->next->next->next->next = malloc(sizeof(ListNode));
    ok->next->next->next->next->next->val = 3;
    ok->next->next->next->next->next->next = NULL;

    ListNode *head = ok;
    ListNode *new = deleteDuplicates(head);
    while (new)
    {
        printf("%d ", new->val);
        new = new->next;
    }
       

}


