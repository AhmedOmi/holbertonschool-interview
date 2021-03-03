#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given
 * unsigned integer is a palindrome.
 * @n: number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long aux = n, power;

	for (power = 1; aux >= 1; power *= 10)
		aux = aux / 10;
	power /= 10;
	while (power > 1)
	{
		if (n / power != n % 10)
			return (0);
		n = (n % power) / 10;
		power /= 100;
	}
	return (1);
}
