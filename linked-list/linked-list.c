#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int *value;
    struct node *next;
} node;

node *new_node(int *x)
{
    node n;
    node *nd = malloc(sizeof(n));
    nd->value = x;
    nd->next = NULL;
    return nd;
}

int *append_node(node *n, node *d)
{
    n->next = d;
    return 0;
}

int search(int *val, node *head_node)
{
    node *m = head_node;
    int *z = val;
    while (&*(m)->value != z || &*(m)->next != NULL)
    {
        m = &*(m)->next;
    }
    if (&*(m)->value == z)
    {
        return 1;
    }
    return 0;
}

int main(void) {
    int val1 = 3;
    int val2 = 5;
    node *nd1 = new_node(&val1);
    node *nd2 = new_node(&val2);
    append_node(nd1, nd2);
    node *y = &*(nd1)->next;
    int *z = &*(y)->value;
    printf("The next node's value is %d\n", *(z));
    int found = search(&val2, nd1);
    printf("The value 5 found? %d\n", found);
    free(nd1);
    free(nd2);
    return 0;
}