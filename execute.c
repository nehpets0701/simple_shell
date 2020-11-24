#include "shellHeader.h"

/**
 *executeProg-executes given command
 *Return: void
 *@argv: given command/tokens
 */
void executeProg(char **argv, char **env)
{
	pid_t child;
	int status, i = 0;

	child = fork();
	if (child == -1)
	{
		perror("Error:");
		return;
	}
	if (child == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("Error:");
			exit(0);
		}
	}
	else
		wait(&status);

	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv[i]);
	free(argv);
}
