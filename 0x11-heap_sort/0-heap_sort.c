#include <stdio.h>
#include "sort.h"
#include <stdlib.h>
/**
 * sort - sort array
 * @array: array
 * @size: array size
 * @i: walkthroug
 * @cs: complete size
 */
void sort(int *array, size_t size, int i, size_t cs)
{
int pk, lft, rgt, swp;

pk = i;
lft = 2 * i + 1;
rgt = 2 * i + 2;
if (lft < (int)size && array[lft] > array[pk])
pk = lft;
if (rgt < (int)size && array[rgt] > array[pk])
pk = rgt;
if (pk != i)
{
swp = array[i];
array[i] = array[pk];
array[pk] = swp;
print_array(array, (int)cs);
sort(array, (int)size, pk, (int)cs);
}
}
/**
 * heap_sort - sort array
 * @array: array to be sorted
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
int i, swp;
if (size == 0)
return;
for (i = (int)size / 2 - 1; i >= 0; i--)
sort(array, (int)size, i, size);
for (i = (int)size - 1; i > 0; i--)
{
swp = array[0];
array[0] = array[i];
array[i] = swp;
print_array(array, (int)size);
sort(array, i, 0, size);
}
}
