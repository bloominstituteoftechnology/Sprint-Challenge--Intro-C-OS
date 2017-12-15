// Write a linked list in C with int payloads in each node.
// Write a function to allocate a new node. Write another function 
// to add that node to the end of the list.
// Bonus: search for a node, delete a node.

//Find out if int payload means the data type or something else

#include <stdio.h> 
#include <stdlib.h>

// declare a struct to represent the node and data
typedef struct new_node() {
    struct new_node *head
    struct new_node *next; // pointer to address of next
    int data;
} node;


// adds a node to end of linked list
typedef struct new_node *append_node(int i) {
    typedef struct new_node *list_node = malloc(sizeof(struct new_node));
    list_node- = NULL;  //TO DO check to see if NULL 
    list_node->next = NULL;

    // TO DO code to add node to end of list
    // find end of the list 
    // insert node and data
    // NOT SURE??
    while (list_node->next != NULL) {
        list_node = list_node->next;
    }

    list_node->next = next;
    list_node->data = data;

    return list_node;
}

// TO DO need to call function(s) to drive code and print output
int main(void) {
     
    // Don't forget to free memory 
    return 0;
}