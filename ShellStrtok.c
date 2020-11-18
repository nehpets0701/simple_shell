#include "shellHeader.h" 
#include <string.h>
#include <stdlib.h>

/**
 * _strtok - break strings into token using delimiters
 *
 * @s: content of the string
 *
 * @delim: delimiters used to split the string
 *
 * Return: tokens from string
 */ 

char *_strtok(char *s, const char *delim)
{
	char *tok;
	static char *next;
	char *p;

	if (delim == NULL)
		return (NULL);

	tok = (s) ? s : next;

	if (tok == NULL)
		return (NULL);

	p = strstr(tok, delim);

	if (p) {
		next = p + strlen(delim);
		*p = '\0';
	}

	else
		next = NULL;

	return (tok);
}
