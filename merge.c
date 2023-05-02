// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.



#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};
void addNode(struct ListNode **sorted, int val)
{
    struct ListNode *tmp = *sorted;
    if (!(*sorted))
    {
        (*sorted) = malloc(sizeof(struct ListNode));
        (*sorted)->val = val;
        (*sorted)->next = NULL;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(struct ListNode));
    tmp->next->val = val;
    tmp->next->next = NULL;
}
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *sorted = NULL;
    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            addNode(&sorted, list1->val);
            list1 = list1->next;
        }
        else
        {
            addNode(&sorted, list2->val);
            list2 = list2->next;
        }
    }
    while (list1)
    {
        addNode(&sorted, list1->val);
        list1 = list1->next;
    }
    while (list2)
    {
        addNode(&sorted, list2->val);
        list2 = list2->next;
    }
    return (sorted);
}
int main(void)
{
    struct ListNode *one = malloc(sizeof(struct ListNode));
    one->val = 1;
    one->next = malloc(sizeof(struct ListNode));
    one->next->val = 5;
    one->next->next = malloc(sizeof(struct ListNode));
    one->next->next->val = 7;
    one->next->next->next = NULL;
    struct ListNode *onef = malloc(sizeof(struct ListNode));
    onef->val = 2;
    onef->next = malloc(sizeof(struct ListNode));
    onef->next->val = 9;
    onef->next->next = malloc(sizeof(struct ListNode));
    onef->next->next->val = 78;
    onef->next->next->next = NULL;

    struct ListNode *ok = mergeTwoLists(one, onef);

    while (ok)
    {
        printf("%d\n", ok->val);
        ok = ok->next;
    }
}
