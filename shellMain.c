#include "shellHeader.h"

/**
 *printPrompt-print $
 *Return: void
 */
int printPrompt(void)
{
	int print = 0;
	char *prompt = "$ ";

	if (isatty(STDIN_FILENO) == 1)
		print = write(STDOUT_FILENO, prompt, 2);
	if (print == -1)
		return (-1);
	return (0);
}


/**
 *main-main shell function
 *Return: 0 or -1 if failure
 */
int main(int argc, char **argv, char **env)
{
 	char *input = NULL;
	char **subInputs = NULL;
	size_t length = 1024;
	int read = 0;

	(void)argc;
	(void)argv;
	(void)env;

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

		if (input[read - 1] == '\n')
			input[read - 1] = '\0';

		if (_strcmp(input ,"exit") == 0)
		{
			free(input);
			return (0);
		}
		subInputs = ShellStrtok(input, " ");
		if (subInputs != NULL)
			executeProg(subInputs);
		free(input);
	}
	return (0);
}
