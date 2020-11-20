#include "shellHeader.h"

/**
 *execute-executes given command
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
	return;
}

/**
 *executeBuiltin-custom commands
 *Return: void
 *@argv:input
 */
/*
void executeBuiltin(char **argv)
{
	int i;

	builtin_t function[] = {
		{"env", func_exit},
		{"exit", func_exit},
		{NULL, NULL}
	};

	for (i = 0; *(function + i)-input, i++)
	{
		if (_strcmp(*(function + i)->cmd, argv[0]) == 0)
		{
			function = *(function + i)->func;
			return(function(argv));
		}
	}
	return (-1);
}
*/