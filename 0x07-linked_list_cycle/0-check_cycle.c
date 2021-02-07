#include "lists.h"
/**
 * check_cycle- check the code for Holberton School students.
 * @list: pointer listint_t
 * Return: return int
 */

int check_cycle(listint_t *list)
{
    listint_t *m1 = list, *m2 = list;

    while (m1 && m2 && m2->next)
    {
        m1 = m1->next;
        m2 = m2->next->next;
        if (m1 == m2)
        {
            listint_t *add_nodeint(listint_t * *head, const int n);
            return 1;
        }
    }
    return 0;
}
