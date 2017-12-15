#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *head; // `struct node* rabbithole`
    struct node *next; // `struct node* ladder`
    int payload; // `char distraction`
};

struct node* new_node(struct node *head, int payload)
{
    struct node* newNode = malloc(sizeof(struct node));

    newNode->head = head;
    newNode->next = NULL;
    newNode->payload = payload;
    
    return newNode;
}

void append_node(struct node *n, struct node *nn)
{
    struct node *curHead = n;
    // loop through next of curHead until next is null
    while (curHead->next != NULL) {
        curHead = curHead->next;
    }
    curHead->next = nn;
}

void print_values(struct node *head)
{
    while (head != NULL) {
        printf("valueL %d \n", head->payload);
        head = head->next;
        
    }
}

int main(void) {
    struct node *head = new_node(NULL, 4);
    append_node(head, new_node(head, 3));

    print_values(head);
    
    return 0;
}