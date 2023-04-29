#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_o
{
    char s;
    struct s_o *next;
} t_o;

t_o *last_node(t_o *p)
{
    while (p->next)
        p = p->next;
    return p;
}

t_o *before_last_node(t_o *p)
{

    while (p->next && p->next->next)
        p = p->next;
    return p;
}
void push(t_o **p, char c)
{
    t_o *tmp;
    if (*p == NULL)
    {
        *p = malloc(sizeof(t_o));
        (*p)->s = c;
        (*p)->next = NULL;
        return;
    }
    tmp = (*p);
    tmp = last_node(tmp);
    tmp->next = malloc(sizeof(t_o));
    tmp->next->s = c;
    tmp->next->next = NULL;
}
char pop(t_o **p)
{
    char t;
    t_o *tmp;
    if (*p == NULL)
        return 0;
    t_o *hp = (*p);

    t_o *ok = last_node(*p);

    tmp = before_last_node(hp);
    t = ok->s;
    tmp->next = NULL;
    if (ok == tmp)
        *p = NULL;
    free(ok);

    return t;
}
bool isValid(char *s)
{
    t_o *mystruct = NULL;

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(')
            push(&mystruct, ')');
        else if (s[i] == '[')
            push(&mystruct, ']');
        else if (s[i] == '{')
            push(&mystruct, '}');
        else if (pop(&mystruct) != s[i])
            return false;
    }
    if (mystruct)
        return false;
    return true;
}
int main()
{
    printf("%d\n", isValid("[[({})]]"));
    printf("%d\n", isValid("[(}]"));
}