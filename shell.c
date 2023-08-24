#include "shell.h"

/**
 * main - entry point of a super simple shell
 * @argc: the number of argument
 * @argv: the argument
 * Return: 0 (Sucess);
 */
int main(int __attribute__((unused))argc, char *argv[])
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read;
	char *prompt;
	int interactive;

	interactive = isatty(STDIN_FILENO);

	while (1)
	{
		prompt = interactive ? "($) " : "";
		printf("%s", prompt);
		fflush(stdout);

		read = getline(&input, &input_size, stdin);
		if (read == -1)
		{
			break; /* Exit on Ctrl+D or error */
		}

		if (read > 0 && input[read - 1] == '\n')
		{
			input[read - 1] = '\0';
		}

		/* Execute the command */
		execute_command(argv[0], input);
	}

	/* Free allocated memory */
	free(input);
	return (0);
}

