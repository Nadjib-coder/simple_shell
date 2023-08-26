#include "shell.h"

/**
 * main - entry point of a super simple shell
 * @argc: the number of argument
 * @argv: the argument
 * Return: 0 (Sucess);
 */
int main(int __attribute__((unused))argc, char *argv[])
{
	char *input = NULL, *prompt,
	     *args[] = {"/bin/exit/", NULL}, *env[] = {NULL};
	size_t input_size = 0;
	ssize_t read;
	int interactive = isatty(STDIN_FILENO), cmd_num = 1;

	while (1)
	{
		char *cmd_args[11];

		prompt = interactive ? "($) " : "";
		printf("%s", prompt);
		fflush(stdout);
		read = getline(&input, &input_size, stdin);
		if (read == -1)
			break;
		if (read > 0 && input[read - 1] == '\n')
			input[read - 1] = '\0';
		if (strncmp(input, "exit", 4) == 0)
			exit(0);
		if (strncmp(input, "env", 3) == 0)
		{
			print_environment();
			continue;
		}
		if (is_empty(input))
			continue;
		split_input(input, cmd_args);
		execute_command(argv[0], cmd_args, cmd_num);
		cmd_num++;
	}
	execve("/bin/exit/", args, env);
	free(input);
	return (0);
}

