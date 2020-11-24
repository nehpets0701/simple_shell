#include "shellHeader.h"

/**
 *getPath-get path
 *Return: string
 *@env:enviornment
 */
char *getPath(char **env)
{
	char *new, *path = NULL;
	char *PATH = "PATH";
	int i, j, done = 0;

	for (i = 0; env[i] && done == 0; i++)
	{
		for (j = 0; j < 4 && done == 0; j++)
		{
			if (env[i][j] != PATH[j])
				break;
			if (env[i][j] == PATH[j] && j == 3)
			{
				path = malloc(_strlen(env[i]) + 1);
				if (path == NULL)
					return (NULL);
				_strcpy(path, env[i]);
				done = 1;
			}
		}
	}
	while (*path != '/')
		path++;
	new = malloc(_strlen(path) - 3);
	if (new == NULL)
		return (NULL);
	_strcpy(new, path);
	free(path);
	return (new);
}
