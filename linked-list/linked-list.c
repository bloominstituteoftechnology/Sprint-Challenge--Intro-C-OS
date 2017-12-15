#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
struct node {
    struct node* last; 
    struct node* next;
    int payload; 
};

struct node* new_node(struct node* head, int payload)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->last = head;
    newNode->next = NULL;
    newNode->payload = payload;
    
    return newNode;
}

void append_node(struct node* head, struct node* newNode)
{
    struct node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
}

void loop (struct node* list){
  int index = 1;
  while(list->next != NULL)
  {
    printf("%d.Payload:%d\n", index, list->payload);
    index++;
    list = list->next;
  }
  printf("%d.Payload:%d\n", index, list->payload);
}

int main(void) {
    pid_t pid = vfork();
    struct node* head = new_node(NULL, 7);
    append_node(head, new_node(head, 77));
    append_node(head, new_node(head, 777));
    append_node(head, new_node(head, 7777));
    append_node(head, new_node(head, 77777));
    append_node(head, new_node(head, 777777));
    append_node(head, new_node(head, 7777777));
    append_node(head, new_node(head, 77777777));
    append_node(head, new_node(head, 777777777));

    if(pid != 0){
      printf("Process:%d\n", pid);
      loop(head);
    }
    exit(0);
    //return 0;
}