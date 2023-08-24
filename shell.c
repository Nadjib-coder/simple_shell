#include "shell.h"

/**
 * main - entry point of a super simple shell
 * Return: 0 (Sucess);
 */
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		read = getline(&input, &input_size, stdin);
		if (read == -1)
		{
			perror("Exiting shell...");
			exit(1); /* Exit on Ctrl+D or error */
		}
		if (read > 0 && input[read - 1] == '\n')
		{
			input[read - 1] = '\0';
		}
		/* Execute the command */
		execute_command(input);
	}
	/* Free allocated memory */
	free(input);
	return (0);
}

