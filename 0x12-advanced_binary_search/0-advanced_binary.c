#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"
/**
 * print - print array to search
 * @array: array to search
 * @first: first element of the array
 * @last: last element of the array
 */
void print(int *array, size_t first, size_t last)
{
size_t i = first;

printf("Searching in array: ");
for (i = first; i < last; i++)
{
printf("%d, ", array[i]);
}
printf("%d\n", array[i]);
}
/**
 * rec - recursive array search
 * @array: new array
 * @first: first element of array
 * @last: last elemnt of array
 * @val: value to search
 * Return: index
 */
int rec(int *array, size_t first, size_t last, int val)
{
size_t side = (first + last) / 2;

print(array, first, last);
if (side >= last)
return (-1);
if (val == array[first])
return (first);
if (val <= array[side - 1])
return (rec(array, first, side, val));
if (val >= array[side + 1])
return (rec(array, side + 1, last, val));
return (-1);
}
/**
 * advanced_binary - binary search
 * @array: array to search
 * @size: size of array
 * @value: value to search for
 * Return: function that returns int
 */
int advanced_binary(int *array, size_t size, int value)
{
if (size == 0)
return (-1);
return (rec(array, 0, size - 1, value));
}
