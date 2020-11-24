#include "shellHeader.h"

/**
 *printPrompt-print $
 *Return: void
 */
int printPrompt(void)
{
	int print = 0;
	char *prompt = "$ ";

	if (isatty(STDIN_FILENO) != 0)
		print = write(STDOUT_FILENO, prompt, 2);
	if (print == -1)
		return (-1);
	return (0);
}

/**
 *sigint-stop control c
 *Return:void
 *@sig:signal
 */
void sigint (int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$", 3);
}


/**
 *printEnv-print enviornment
 *Return:1 hopefully
 *@env:env data
 */
int printEnv(char **env)
{
	char **current = env;

	while (*current)
	{
		_puts(*current);
		current++;
	}
	return (1);
}

/**
 *main-main shell function
 *Return: 0 or -1 if failure
 *@argc:number of args
 *@argv:value of args
 *@env:enviornment
 */
int main(int argc, char **argv, char **env)
{
	char *input = NULL;
	char **subInputs = NULL;
	size_t length = 1024;
	int read = 0;

	(void)argc;
	(void)argv;
	signal(SIGINT, sigint);
	while (1)
	{
		printPrompt();

		input = malloc(1024);
		if (input == NULL)
			return (-1);
		read = getline(&input, &length, stdin);
		if (read == -1)
		{
			_putchar('\n');
			free(input);
			return (-1);
		}
		if (read == 0)
			continue;
		if (input[read - 1] == '\n')
			input[read - 1] = '\0';

		if (_strcmp(input, "exit") == 0)
		{
			free(input);
			return (0);
		}
		if (_strcmp(input, "env") == 0)
			printEnv(env);
		subInputs = ShellStrtok(input, " ");
		if (subInputs != NULL)
			executeProg(subInputs, env);
		free(input);
	}
	return (0);
}
