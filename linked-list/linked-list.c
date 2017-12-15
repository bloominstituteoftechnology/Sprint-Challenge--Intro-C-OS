#include <stdio.h>
#include <stdlib.h>

struct ll {
	int val;
	struct ll* next;
} ll;

struct ll* new_node(int val)
{
	// allocate memory
	struct ll *node = malloc(sizeof(struct ll));

	node->val = val;
	node->next = NULL;

	return node;
}

void append_node(struct ll* list, int val)
{
	// go to end of list
	while (list->next != NULL) {
		list = list->next;
	}

	// instantiate newNode
	struct ll* newNode = new_node(val);

	// add newNode to end of the list
	list->next = newNode;
}

// searches for node in linked list, if found, returns the index
int search_node(struct ll* list, int searchVal)
{
	int index = 0;
	while (list->next != NULL) {
		if (list->val == searchVal) {
			return index;
			// break;
		}
		index++;
		list = list->next;
	}
	return -1;
}

void delete_node(struct ll** head_ref, int searchVal)
{
	// check if deleted node is the first node
	// if its in the middle, point the nodes previous to the nodes next
	// do we delete and free the memory of the nodes memory?

	struct ll* tmp = *head_ref, *prev;

	// If head node is the prospected deleted node
	if (tmp != NULL && tmp->val == searchVal)
	{
		// point head to the next node, essentially removing the head.
		*head_ref = tmp->next;
		// free the memory used by the head
		free(tmp);
		// return the linked list
		return;
	}

	// Search for the searchVal to be deleted, keep track of the
	// previous node as we need to change 'prev->next'
	while (tmp != NULL && tmp->val != searchVal)
	{
		// keep track of the previous node
		prev = tmp;
		// point the current tmp to the next node
		tmp = tmp->next;
	}

	// if searchVal wasnt found, return the linked list
	if (tmp == NULL) return;

	// Unlink the node from linked list
	prev->next = tmp->next;

	// free the memory of the unlinked node
	free(tmp);
}

int main(void) {
	return 0;
}