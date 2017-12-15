#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  struct Node *next;
  int value;
};

struct Node *new_node(int value) {
  struct Node *node = malloc(sizeof(struct Node));
  node->next = NULL;
  node->value = value;
  return node;
}

void append_node(struct Node* list, int value) {
  struct Node *newNode = new_node(value);
  while (list->next != NULL) {
    list = list->next;
  }
  list->next = newNode;
}

void print_list(struct Node* list) {
  while (list->next != NULL) {
    printf("%d ", list->value);
    list = list->next;
  }
  printf("%d\n", list->value); // print the last node
}

bool search(struct Node* list, int value) {
  while (list->next != NULL) {
    if(list->value == value){
      return true;
    }
    list = list->next;
  }
  if(list->value == value){  // check the last node
    return true;
  }
  return false;
}

void delete_node(struct Node* list, int value) { // couldn't figure out how to delete the head node, and there's probably memory leaks
  struct Node *temp = NULL;
  while (list->next != NULL && list->value != value) {
    temp = list;
    list = list->next;
  }
  if (list->next == NULL && list->value != value){ // node is not in the list
    return;
  }
  temp->next = list->next; 
}

int main(void) {
  struct Node *head = NULL;
  head = new_node(5);
  append_node(head, 10);
  append_node(head, 15);
  append_node(head, 20);
  print_list(head); // should print: 5 10 15 20
  printf("%s\n", search(head, 10)?"true":"false"); // should print: true
  printf("%s\n", search(head, 17)?"true":"false"); // should print: false
  delete_node(head, 10);
  print_list(head); // should print: 5 15 20
  printf("%s\n", search(head, 10)?"true":"false"); // should print: false
}