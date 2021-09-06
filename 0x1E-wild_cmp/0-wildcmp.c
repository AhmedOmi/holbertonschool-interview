#include "holberton.h"
/**
 * wildcmp - function to compare between to string
 * @s1: pointer of char 1
 * @s2:  pointer of char 2
 * Return: int 
 *
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 == '*')
	{
		if (!*s1 && s2[1])
			return (0);
		if (wildcmp(s1, s2 + 1))
			return (1);
		else
			return (wildcmp(s1 + 1, s2));
	}
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
