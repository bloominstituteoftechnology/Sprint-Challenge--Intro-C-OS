
#include <stdio.h>
#include <stdlib.h>

struct linkedList {
  struct linkedList* next;
  int value;
};

struct linkedList* new_node(int value)
{
  struct linkedList* list = malloc(sizeof(struct linkedList));

  (*list).value = value;
  (*list).next = NULL;

  return list;
}

void append_node(struct linkedList* listHeadNode, int value)
{

  struct linkedList* currentNode = listHeadNode;

  while((*currentNode).next != NULL) {
    currentNode = (*currentNode).next;
  }

  struct linkedList* newNode = new_node(value);

  (*currentNode).next = newNode;
}

struct linkedList* find_node(struct linkedList* listHeadNode, int value)
{
  struct linkedList* currentNode = listHeadNode;

  while ((*currentNode).next != NULL) {
    if((*currentNode).value == value) {
      return currentNode;
    }

    currentNode = (*currentNode).next;
  }

  return currentNode;
}

void delete_node(struct linkedList* listHeadNode, int value)
{
  struct linkedList* currentNode = listHeadNode;
  struct linkedList* priorNode;

  while((*currentNode).next != NULL) {

    if((*currentNode).value == value) {
      printf("Deleting node #%d\n", (*currentNode).value);
      if (priorNode != NULL) {
        (*priorNode).next = (*currentNode).next;
      }
      free(currentNode);
    }

    priorNode = currentNode;
    currentNode = (*currentNode).next;
  }

  // Concern: How do we then find out what the address is of the new head node if the head node is deleted.
  // Consider: Returning the head node address pointer.
}

void print_list(struct linkedList* listHeadNode)
{
  struct linkedList* currentNode = listHeadNode;
  while(currentNode != NULL) {
    printf("Node #%d\n", (*currentNode).value);
    currentNode = (*currentNode).next;
  }
}

void free_mem(struct linkedList* listHeadNode)
{
  struct linkedList* currentNode = listHeadNode;

  while(currentNode != NULL) {
    struct linkedList* removalNode = currentNode;
    currentNode = (*currentNode).next;
    free(removalNode);
  }
}

int main(void) {
  struct linkedList* myLinkedList = new_node(1);

  append_node(myLinkedList, 2);
  append_node(myLinkedList, 3);
  append_node(myLinkedList, 4);
  append_node(myLinkedList, 5);

  printf("List of all nodes:\n");

  print_list(myLinkedList);

  struct linkedList* nodeThree = find_node(myLinkedList, 3);
  printf("This is node #%d\n", (*nodeThree).value);

  printf("Delete Node #3\n");

  delete_node(myLinkedList, 3);

  printf("List of all nodes:\n");
  print_list(myLinkedList);

  printf("Freeing Memory...\n");
  free_mem(myLinkedList);
}
