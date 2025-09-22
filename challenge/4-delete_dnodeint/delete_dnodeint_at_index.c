#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at a given index of a dlistint_t list
 * @head: address of pointer to the head of the list
 * @index: index of the node to delete (0-based)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node, *prev, *next;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	node = *head;
	i = 0;

	/* move to target index */
	while (node != NULL && i < index)
	{
		node = node->next;
		i++;
	}

	if (node == NULL) /* index out of range */
		return (-1);

	/* deleting head */
	if (node->prev == NULL)
	{
		*head = node->next;
		if (node->next != NULL)
			node->next->prev = NULL;
		free(node);
		return (1);
	}

	/* deleting middle or tail */
	prev = node->prev;
	next = node->next;

	prev->next = next;
	if (next != NULL)
		next->prev = prev;

	free(node);
	return (1);
}
