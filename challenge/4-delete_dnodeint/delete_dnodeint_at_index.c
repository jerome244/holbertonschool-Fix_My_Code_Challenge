#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - delete node at given index in a dlist
 * @head: address of pointer to head node
 * @index: 0-based index of node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	node = *head;
	i = 0;

	/* walk to index */
	while (node != NULL && i < index)
	{
		node = node->next;
		i++;
	}

	if (node == NULL)
		return (-1); /* index out of range */

	/* unlink node */
	if (node->prev == NULL)
	{
		/* deleting head */
		*head = node->next;
		if (node->next != NULL)
			node->next->prev = NULL;
	}
	else
	{
		/* deleting middle/tail */
		node->prev->next = node->next;
		if (node->next != NULL)
			node->next->prev = node->prev;
	}

	free(node);
	return (1);
}
