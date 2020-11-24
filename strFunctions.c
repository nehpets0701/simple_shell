#include "shellHeader.h"

/**
 *_strcmp-compare
 *Return:0/1
 *@s1:input
 *@s2:input
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

/**
 *_strcpy-add letter
 *Return:0
 *@dest:input
 *@src:input
 */
char *_strcpy(char *dest, char *src)
{
	char *start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (start);
}

/**
 *_strlen-strlen
 *Return:unsigned int
 *@p:input
 */
unsigned int _strlen(char *p)
{
	unsigned int count = 0;

	if (p == NULL)
		return (0);

	while (*p != '\0')
	{
		count++;
		p++;
	}

	return (count);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *_puts-putschars
 *Return:0
 *@str:input
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
