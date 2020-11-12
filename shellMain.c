#include "shellHeader.h"

/**
 *printPrompt-print $
 *Return: void
 */
int printPrompt(void)
{
	int print = 0;
	char *prompt = "$ ";

	print = write(STDOUT_FILENO, prompt, 1);
	if (print == -1)
		return (-1);
	return (0);
}


/**
 *main-main shell function
 *Return: 0 or -1 if failure
 */
int main(void)
{
	char *input = NULL;
	size_t length = 1;
	int read = 0;

	while (1)
	{
		printPrompt();

		read = getline(&input, &length, stdin);
		if (read == -1)
			return (-1);
	}
	return (0);
}
