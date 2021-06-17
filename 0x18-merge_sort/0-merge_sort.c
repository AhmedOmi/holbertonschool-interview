#include "sort.h"
/**
 * top_down_merge - divide an array
 * @A: sarray int
 * @begin: begin of array
 * @middle: middle of array
 * @end: end of array
 * @B: array B
 * Return: void
 */
void top_down_merge(int *A, int begin, int middle, int end, int *B)
{
	int i, j, k;

	i = begin;
	j = middle;

	for (k = begin; k < end; k++)
	{
		if (i < middle && (j >= end || (A[i] <= A[j])))
		{
			B[k] = A[i];
			i += 1;
		}
		else
		{
			B[k] = A[j];
			j += 1;
		}
	}
	for (k = begin; k < end; k++)
	{
		A[k] = B[k];
	}
}
/**
 * top_down_split_merge - Split the array
 * @B: array B
 * @begin: begin of array
 * @end: end of array
 * @A: array
 * Return: void
 */
void top_down_split_merge(int *B, int begin, int end, int *A)
{
	int middle, i;

	if (end - begin <= 1)
		return;
	middle = (end + begin) / 2;
	top_down_split_merge(B, begin, middle, A);
	top_down_split_merge(B, middle, end, A);

	printf("Merging...\n");
	printf("[left]: ");
	for (i = begin; i < middle; i++)
	{
		printf("%d", A[i]);
		if (i + 1 < middle)
			printf(", ");
	}
	printf("\n");

	printf("[right]: ");
	for (i = middle; i < end; i++)
	{
		printf("%d", A[i]);
		if (i + 1 < end)
			printf(", ");
	}
	printf("\n");

	top_down_merge(B, begin, middle, end, A);

	printf("[Done]: ");
	for (i = begin; i < end; i++)
	{
		printf("%d", A[i]);
		if (i + 1 < end)
			printf(", ");
	}
	printf("\n");
}
/**
 * merge_sort - Sort an array of integers
 * @array: pointer int
 * @size: size_t
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int s, i, *b;

	if (size < 2)
		return;
	s = size;
	b = (int *) malloc(s * sizeof(int));
	for (i = 0; i < s; i++)
	{
		b[i] = array[i];
	}
	top_down_split_merge(b, 0, s, array);
	free(b);
}
