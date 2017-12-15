#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head;

struct node* new_node(int data) {

    struct node* newNode = malloc(sizeof(struct node));

    newNode->next = NULL;
    newNode->data = data;

    return newNode;
}

void append_node(struct node* list, struct node* node)
{
    while (list->next != NULL) {
        list = list->next;
    }

    list->next = node;
}

struct node* search(struct node* list, int data) {

    while (list != NULL) {
        if (list->data == data) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

void delete(struct node* list, int data) {
    
    struct node* iterator = list;

    while (iterator != NULL) {
        if (iterator->next->data == data) {
            printf("success node with provided data removed %d\n", data);
            break;
        }
        iterator = iterator->next;
    }

    if (iterator != NULL) {
        struct node* tmp = iterator->next;
        iterator->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }

}


int main(void) 
{

    struct node* tail = new_node(5);
    struct node* newNode = new_node(6);
    struct node* head = tail;

    append_node(tail, newNode);

    struct node* node = new_node(10);

    append_node(tail, node);

    delete(tail, 6);

    struct node* result = search(tail, 10);
    if (result == 0) {
        printf("unsuccess node was not found %d\n", result);
    } else {
        printf("success node found %d\n", result->data);
    }
    
    while (head->next != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }

    return 0;

}