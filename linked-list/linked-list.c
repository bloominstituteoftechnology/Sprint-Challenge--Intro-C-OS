
#include <stdio.h>

#include <stdlib.h>

struct node 
{
    int value;
    struct node *next;
};
struct list {
    struct node *head;
};

struct node* new_node() {
    struct node *newNode = malloc(sizeof(struct node));
    puts("hi");
    newNode-> next = malloc(sizeof(struct node));
    puts("hi");
    newNode-> next = NULL;
    newNode-> value = 0;
    puts("hi");
    return new_node;
};

int append_node(struct node *list_head, int x) {
    struct node *current;
    puts("oh");
    *current = *list_head;
    puts("oh");
    while(list_head -> next != NULL) {
        current = current -> next;
    puts("oh");
    }
    puts("oh");
    current -> next = new_node();
    puts("oh");
    current = current -> next;
    puts("oh");
    current -> value = x;
    puts("oh");
    return 0;
}

int main(void) {
    
    
    puts("hi");
    struct node *nodeA;
    puts("nodeA made");
    nodeA = new_node();
    
    printf("%d", 3);
    puts("nodeA got malloced");
    struct node nodeB;
    nodeB = *nodeA;
    int r = nodeB.value;
    printf("%d \n", r);
    append_node(nodeA, 3);
    printf("%d \n", 3);
//nodeA -> value

}