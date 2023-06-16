#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - Frees a doubly linked list.
 * @head: Pointer to the head of the list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;


	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
