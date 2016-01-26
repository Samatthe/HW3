#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	list_t *previous;
	list_t *current;
	if(new_element->index <= head->index)
	{
		new_element->next = head;
		head = new_element;
	}
	else
	{
		previous = head;
		while(previous != NULL && previous->index < new_element->index)
		{
			current = previous;
			previous = previous->next;
		}
		if(previous != NULL)
		{
			new_element->next = current;
			current->next = new_element;
		}
		else
		{
			new_element->next = NULL;
			current->next = new_element;
		}
	}
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t *temp = NULL;
	list_t *last = head->next;
	list_t *tempHead = head;
	while(last != NULL)
	{
		temp = last->next;
		last->next = tempHead;
		tempHead = last;
		last = temp;
	}
	head = tempHead;
	return head;
}

