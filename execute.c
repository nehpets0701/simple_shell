#include "shellHeader.h"

/**
 *executeProg-executes given command
 *Return: void
 *@argv: given command/tokens
 */
void executeProg(char **argv)
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
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error:");
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
