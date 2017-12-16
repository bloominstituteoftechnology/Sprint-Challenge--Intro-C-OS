#include <stdio.h>

typedef struct node {
  int value;
  struct node* next;
} node;

node *head = NULL;
node *current = NULL;

new_node(int value)
{
  node *n = malloc(sizeof(node));
  n->data = data;
  n->next = next;

  return n;
}

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

void append_node(node **h, node *n)
{	
  if (*h == NULL) {
		*h = n;
		return;
}
	node *p = *h;

	while (p->next != NULL) {
		p = p->next;
	}

	p->next = n;
}


int main(void) {
  return 0;
}