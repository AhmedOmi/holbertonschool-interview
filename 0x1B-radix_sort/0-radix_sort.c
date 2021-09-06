#include "sort.h"
/**
 * max - Returns the max
 * @array: pointer of int
 * @size: int
 * Return: return maximum
 */
int max(int *array, int size)
{
    int maximum, i;
    maximum = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > maximum)
            maximum = array[i];
    }
    return (maximum);
}

/**
 * sort - sorting array
 * @array: pointer of int
 * @size: int
 * @index: index of int
 * Return: void
 */
void sort(int *array, int size, int index)
{
    int a, b, c, d, tmp, i;
    a = 0;
    while (a < size)
    {
        b = (array[a] / index) % 10;
        c = a;
        while (c < size)
        {
            d = (array[c] / index) % 10;
            if (b > d)
            {
                tmp = array[c];
                for (i = c - 1; i >= a; i--)
                {
                    array[i + 1] = array[i];
                }
                array[a] = tmp;
                a = -1;
                break;
            }
            c++;
        }
        a++;
    }
}

/**
 * radix_sort - sorting array with redix
 * @array: pointer of int
 * @size: size_t
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
    int a, maximum, i;
    if (array == NULL || size < 2)
        return;
    a = (int)size;
    maximum = max(array, a);
    i = 1;
    while ((maximum / i) > 0)
    {
        sort(array, a, i);
        print_array(array, size);
        i *= 10;
    }
}
