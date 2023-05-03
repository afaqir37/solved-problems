// You are given a large integer represented as an integer array digits, 
// where each digits[i] is the ith digit of the integer. 
// The digits are ordered from most significant to least significant in left-to-right order. 
// The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.

// Input: digits = [4,3,2,1]
// Output: [4,3,2,2]

// Input: digits = [9]
// Output: [1,0]


#include <stdio.h>
#include <stdlib.h>

typedef struct t_ok
{
    int val;
    struct t_ok *next;
} s_ok;

int ft_count_node(s_ok *list)
{
    int counter = 0;
    while (list)
    {
        counter++;
        list = list->next;
    }
    return (counter);
}

void ft_addnode(s_ok **list, int val)
{
    if (!*list)
    {
        *list = malloc(sizeof(s_ok));
        (*list)->val = val;
        (*list)->next = NULL;
        return;
    }
    s_ok *tmp = *list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(s_ok));
    tmp->next->val = val;
    tmp->next->next = NULL;
}

void ft_free_list(s_ok *list)
{
    s_ok *tmp;
    while (list)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}
int *plusOne(int *digits, int digitsSize, int *returnSize)
{

    s_ok *list = NULL;
    int i = digitsSize - 1;
    int counter;
    int *k;
    while (i >= 0)
    {
        ft_addnode(&list, digits[i]);
        i--;
    }

    s_ok *tmp = list;
    int carry = 0;
    tmp->val += 1;

    while (tmp)
    {
        tmp->val += carry;
        if (tmp->val == 10)
        {
            tmp->val = 0;
            carry = 1;
            tmp = tmp->next;
            if (!tmp)
                ft_addnode(&list, 1);
        }
        else
            break;
    }

    counter = ft_count_node(list);

    *returnSize = counter;

    k = malloc(counter * sizeof(int));
    if (!k)
        return (NULL);
    counter--;

    while (counter >= 0)
    {
        k[counter] = list->val;
        counter--;
        list = list->next;
    }

    ft_free_list(list);

    return (k);
}
int main()
{
    int size;
    int ok[] = {7, 2, 8, 5, 0, 9, 1, 2, 9, 5, 3, 6, 6, 7, 3, 2, 8, 4, 3, 7, 9, 5, 7, 7, 4, 7, 4, 9, 4, 7, 0, 1, 1, 1, 7, 4, 0, 0, 6};
    int *k = plusOne(ok, 39, &size);
    for (int i = 0; i < size; i++)
        printf("%d ", k[i]);
    free(k);
}