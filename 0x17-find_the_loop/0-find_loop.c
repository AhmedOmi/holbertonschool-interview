#include "lists.h"
/**
* find_listint_loop - finds the loop in a linked list.
* @head: pointer of listint_t
* Return: listint_t
**/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *s, *f;

	if (!head || !(head->next))
		return (NULL);

	s = head->next;
	f = head->next->next;

	while (f && f->next)
	{
		if (s == f)
			break;
		s = s->next;
		f = f->next->next;
	}

	if (s != f)
		return (NULL);

	s = head;
	while (s != f)
	{
		s = s->next;
		f = f->next;
	}

	return (s);
}
