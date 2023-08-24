#include "shell.h"

/**
 * execute_command - a function that execute a command
 * @command: the path of the command
 * Return: nothing.
 */
void execute_command(const char *program_name, const char *command)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		/* Child process */
		char *envp[] = {NULL}; /* Empty environment */
		char *args[2];

		args[0] = strdup(command);
		args[1] = NULL;
		execve(command, args, envp);

		/* free the memory allocated by strdup */
		free(args[0]);

		/* printf error message withe program's name */
		perror(program_name);

		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}

