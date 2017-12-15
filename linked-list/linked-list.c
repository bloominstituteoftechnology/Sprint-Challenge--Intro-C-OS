#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;


void printList() {
   struct node *print = head;
   printf(" [ ");
	
   while(print != NULL) {
      printf("(id:%d, data:%d) ",print->key,print->data);
      print = print->next;
   }
	
   printf(" ]\n\n");
}

void new_node(int key, int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->key = key;
   link->data = data;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}

// append_node()

struct node* append_node(int key, int newdata) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
   //if data found, return the current Link
   printf("Found: (id:%d, data:%d) \n\n",current->key,current->data);
   current->data = newdata;
    printf("Appended: (id:%d, data:%d) \n\n",current->key,current->data);
   return current;
    
}

int main(void) {
   new_node(1,10);
   new_node(2,20);
   new_node(3,30);
   new_node(4,1);
   new_node(5,40);
   new_node(6,56); 
   
   printf("\nOriginal List: "); 
   printList();
   append_node(4,7);
   printf("Appended List: "); 
   printList();

}
