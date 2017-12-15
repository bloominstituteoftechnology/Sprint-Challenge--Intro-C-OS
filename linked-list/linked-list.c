#include <stdlib.h>
#include <stdio.h>

struct LinkedList {
  struct LinkedList* next;
  int value;
};

typedef struct LinkedList *node;

node new_node() {
  node newNode = malloc(sizeof(struct LinkedList));

  newNode->next = NULL;

  return newNode;
}

node append_node(node head, int val) {
  node c = head;
  node newNode = new_node();
  newNode->value = val;
  while(c->next != NULL) {
    c = c->next;
  }

  c->next = newNode;

  return head;
}

node search(node current, int val) {
  if(current == NULL)
    return NULL;
  if(current->value == val)
    return current;
  return search(current->next, val);
}

node delete_node(node current, int val) {
  if(current == NULL)
    return NULL;
  
  if(current->value == val) {
    node temp = current->next;
    free(current);

    return temp;
  }

  current->next = delete_node(current->next, val);

  return current;
}

void destroy_list(node head) {
  node temp;
  while(head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

void print_list(node current) {
  if(current == NULL) {
    printf("NULL\n");
    return;
  }
  printf("%d -> ", current->value);
  print_list(current->next);
}

int main(void) {
  node head = new_node();

  head = append_node(head, 1);
  head = append_node(head, 26);
  head = append_node(head, 11);
  head = append_node(head, 42);
  head = append_node(head, 13);
  head = append_node(head, 6);

  print_list(head);

  node found;
  if((found = search(head, 11)) != NULL) {
    printf("Found node: %d\n", found->value);
  }

  head = delete_node(head, 42);

  if(search(head, 42) == NULL) {
    printf("Node deleted\n");
  }

  print_list(head);

  destroy_list(head);

  return 0;
}