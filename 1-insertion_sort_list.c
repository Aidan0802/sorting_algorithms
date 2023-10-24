#include "sort.h"

/**
 * insertion_sort_list - Sorts a double linked list
 * in ascending order
 * @list: Address of double linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next, *insertion_point = current;
	listint_t *search = current->prev, *temp = *list;

	if (*list == NULL)
		return;

	while (search != NULL && search->n > current->n)
		search = search->prev;

	if (search == NULL)
	{
		current->prev->next = current->next;
		if (current->next != NULL)
			current->next->prev = current->prev;
		current->prev = NULL;
		current->next = *list;
		(*list)->prev = current;
		*list = current;
	}
	else
	{
		insertion_point = search->next;
		current->prev->next = current->next;
		if (current->next != NULL)
			current->next->prev = current->prev;
		current->prev = search;
		current->next = insertion_point;
		search->next = current;
		if (insertion_point != NULL)
			insertion_point->prev = current;
	}

	while (temp != NULL)
	{
		printf("%d", temp->n);
		if (temp->next != NULL)
			printf(", ");
		temp = temp->next;
	}
	printf("\n");
}
