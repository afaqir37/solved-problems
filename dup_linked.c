#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
      int val;
     struct ListNode *next;
 } ListNode;

ListNode* deleteDuplicates(ListNode* head){
    if (!head || !(head->next))
        return (head);
    ListNode *nice = head;
    ListNode *save = head->next;
    ListNode *ok;
    while (head)
    {
       if (head->next && head->val == head->next->val)
       {
            ok = head;
            head = head->next;
            free(ok);
        }
        head = head->next;
    }
    return (head);
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
    ok->next->next->next->next = NULL;
    // ok->next->next->next->next->val = 3;
    // ok->next->next->next->next->next = malloc(sizeof(ListNode));
    // ok->next->next->next->next->next->val = 3;
    // ok->next->next->next->next->next->next = NULL;

    ListNode *head = ok;
    ListNode *new = deleteDuplicates(head);
    while (new)
    {
        printf("%d ", new->val);
        new = new->next;
        }
        return 0;

        }


