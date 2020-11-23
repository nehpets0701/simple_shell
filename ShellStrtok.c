#include "shellHeader.h"
#include <string.h>
#include <stdlib.h>

/**
 * ShellStrtok - break strings into token using delimiters
 *
 * @s: content of the string
 *
 * @delim: delimiters used to split the string
 *
 * Return: tokens from string
 */

char **ShellStrtok(char *s, char *delim)
{
	char **tok;
	char *str;
	int i = 1, index = 0;

	while (s[index])
	{
		if (s[index] == *delim)
			i++;
		index++;
	}

	tok = malloc(sizeof(char *) * (i + 1));
	if (tok == NULL)
		return (NULL);
	tok[i] = NULL;

	i = 0;
	str = strtok(s, delim);
	while (1)
	{
		if (str == NULL)
			break;
		tok[i] = malloc(sizeof(char) * _strlen(str) + 1);
		if (tok[i] == NULL)
		{
			i = 0;
			while (tok[i] != NULL)
			{
				free(tok[i]);
				i++;
			}
			free(tok);
			return (NULL);
		}
		_strcpy(tok[i], str);
		i++;
		str = strtok(NULL, delim);
	}
	tok[i] = NULL;
	return (tok);
}
