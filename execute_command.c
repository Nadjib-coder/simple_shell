#include "shell.h"

/**
 * execute_command - a function that execute a command
 * @prg_name: the program name.
 * @args: the arguments of the command
 * @cmd_num: the number of command that excute
 * Return: nothing.
 */
void execute_command(const char *prg_name, char *const args[], int cmd_num)
{
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		char *envp[] = {NULL};

		execve(args[0], args, envp);
		fprintf(stderr, "%s: %d: %s: not found\n ", prg_name, cmd_num, args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}

