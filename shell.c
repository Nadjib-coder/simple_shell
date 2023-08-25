#include "shell.h"

/**
 * main - entry point of a super simple shell
 * @argc: the number of argument
 * @argv: the argument
 * Return: 0 (Sucess);
 */
int main(int __attribute__((unused))argc, char *argv[])
{
	char *input = NULL, *prompt;
	size_t input_size = 0;
	ssize_t read;
	int interactive;
	int cmd_num = 1;

	interactive = isatty(STDIN_FILENO);
	while (1)
	{
		int is_empty = 1;
		char *cmd_args[11];
		size_t i;

		prompt = interactive ? "($) " : "";
		printf("%s", prompt);
		fflush(stdout);
		read = getline(&input, &input_size, stdin);
		if (read == -1)
			break;
		if (read > 0 && input[read - 1] == '\n')
			input[read - 1] = '\0';
		for (i = 0; i < strlen(input); i++)
		{
			if (!isspace(input[i]))
			{
				is_empty = 0;
				break;
			}
		}
		if (is_empty)
			continue;
		if (strcmp(input, "exit") == 0)
		{
			printf("Exiting the shell...\n");
			break;
		}
		split_input(input, cmd_args);
		execute_command(argv[0], cmd_args, cmd_num);
		cmd_num++;
	}
	free(input);
	return (0);
}

