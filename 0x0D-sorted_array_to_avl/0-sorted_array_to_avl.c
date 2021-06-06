#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * mknode - create a new node
 * @array: array of integer
 * @head: head of avl_t
 * @beg: integer
 * @lst: integer
 * Return: avl_t
 */
avl_t *mknode(int *array, avl_t *head, int beg, int lst)
{
int hlf;
avl_t *new;

if (beg > lst)
return (NULL);
hlf = (beg + lst) / 2;
new = malloc(sizeof(avl_t));
if (!new)
return (NULL);

new->n = array[hlf];
new->parent = head;
new->left = mknode(array, new, beg, hlf - 1);
new->right = mknode(array, new, hlf + 1, lst);
return (new);
}
/**
 * sorted_array_to_avl - print an array of integers
 *
 * @array: array of integer
 * @size: Size_t
 *Return: avl_t
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
avl_t *sav;
int beg, hlf, lst;

if (!array)
return (NULL);
sav = malloc(sizeof(avl_t));
if (!sav)
return (NULL);
beg = 0;
lst = size - 1;
hlf = (beg + lst) / 2;
sav->n = array[hlf];
sav->parent = NULL;
sav->left = mknode(array, sav, beg, hlf - 1);
sav->right = mknode(array, sav, hlf + 1, lst);
return (sav);
}
