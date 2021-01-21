#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * listint_len - prints elements of a list
 * @h: pointer of list
 * Return: int
 */
int listint_len(listint_t **h)
{
    int k;
    listint_t *current = *h;
    k = 0;
    while (current != NULL)
    {
        k++;
        current = current->next;
    }
    return (k);
}
/**
 * is_palindrome - prints all elements of a list
 * @head: pointer of list
 * Return: int
 */
int is_palindrome(listint_t **head)
{
    int s = listint_len(head);
    int arr[4000];
    int i;
    listint_t *nd = *head;
    while (nd)
    {
        for (i = 0; i < s; i++)
        {
            arr[i] = nd->n;
            nd = nd->next;
        }
    }
    for (i = 0; i <= s / 2 && s != 0; i++)
    {
        if (arr[i] != arr[s - i - 1])
        {
            return (0);
        }
    }
    return (1);
}
