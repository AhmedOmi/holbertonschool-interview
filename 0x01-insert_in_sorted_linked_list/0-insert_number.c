#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insert_node - function to insert node in a list
 * @head: node Pointer of Pointer of listint_t structure
 * @number: Variable add to a node
 * Return: return new node type listint_t
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *tmp, *prev;

	if (!head)
		return (NULL);
	new = malloc(sizeof(listint_t));
	new->n = number;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	tmp = *head;
	prev = *head;
	while (tmp && tmp->n < number)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == *head)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	new->next = prev->next;
	prev->next = new;
	return (new);
}
