#include "regex.h"

/**
 * regex_match - function that checks whether a given pattern matches a given string
 * @str: string to scan
 * @pattern: is the regular expression
 * Return: int 1 or 0
 */

int regex_match(char const *str, char const *pattern)
{
    int p, e;

    if (!str || !pattern)
        return (0);

    e = *(pattern + 1) == '*';
    p = *str && (*str == *pattern || *pattern == '.');

    if (!*str && !e)
        return (*pattern ? 0 : 1);
    else if (p && e)
        return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
    else if (p && !e)
        return (regex_match(str + 1, pattern + 1));
    else if (e)
        return (regex_match(str, pattern + 2));
    return (0);
}
