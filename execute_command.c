#include "shell.h"

/**
 * execute_command - a function that execute a command
 * @command: the path of the command
 * Return: nothing.
 */
void execute_command(const char *command)
{
	pid_t pid = fork();
	int status;

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
		/* execve only returns if an error occurs */
		perror("Exec failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		wait(&status);
		if (WIFEXITED(status))
		{
			printf("child process exited with status %d\n", WEXITSTATUS(status));
		}
	}
}

