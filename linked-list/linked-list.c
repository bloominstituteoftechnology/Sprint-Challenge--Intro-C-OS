#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node;

/*
// Optionally another structure to hold the entire list

typedef struct list {
    node *head;
} list;
*/
node *new_node(int val)
{
    node *n = malloc(sizeof(node));

    n->val = val;
    n->next = NULL;

    return n;
}

/**
 * Search for a node
 */
node *search_node(node *h, int val)
{
    while (h != NULL) {
        if (h->val == val) {
            return h;
        }

        h = h->next;
    }
    return NULL;
}

/**
 * Append a node to a list
 */
void append_node(node **h, node *n)
{
    //Handle an empty list
    if (*h == NULL) {
        *h = n;
        return;
    }

    // Traverse list to end and append the new node
    node *p = *h;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = n;
}

/**
 * Main
 */
int main(void) {
    node *head = NULL;
    node *p;

    append_node(&head, new_node(12));
    append_node(&head, new_node(22));
    append_node(&head, new_node(32));
    append_node(&head, new_node(42));
    append_node(&head, new_node(52));

    p = search_node(head, 0);
    printf("%p\n", p);
    p = search_node(head, 32);
    printf("%p %d\n", p, p->val);

    // Output list
    p = head;
    while (p != NULL) {
        printf("%d\n", p->val);
        p = p->next;
    }
    
    return 0;
}