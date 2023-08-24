#include "shell.h"

/**
 * execute_command - a function that execute a command
 * @program_name: the program name.
 * @command: the path of the command
 * Return: nothing.
 */
void execute_command(const char *program_name, const char *command)
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
		char *args[2];

		args[0] = strdup(command);
		args[1] = NULL;
		execve(command, args, envp);

		free(args[0]);
		perror(program_name);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}

