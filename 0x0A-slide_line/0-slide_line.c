#include "slide_line.h"

/**
 * slide_line - Slide and merge an array of ints
 * @line: Array to slide
 * @size: Size of the array
 * @direction: Direction in which to slide the array
 * Return: 0 on failure otherwise 1
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t count = 0, sec = 0, i;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	for (i = 0; i < size; i++)
	{
		sec = line[i];
		count += sec;

	}
	return (1);
}
