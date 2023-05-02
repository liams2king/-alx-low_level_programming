#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head node of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t count = 0;

	if (head == NULL)
		exit(98);

	tortoise = head;
	hare = head->next;

	while (tortoise != NULL)
	{
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		count++;

		if (hare == NULL || hare->next == NULL)
			break;

		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				printf("[%p] %d\n", (void *)tortoise, tortoise->n);
				count++;
				tortoise = tortoise->next;
				hare = hare->next;
			}
			printf("[%p] %d\n", (void *)tortoise, tortoise->n);
			count++;
			break;
		}
	}

	return (count);
}
