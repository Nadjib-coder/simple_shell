#include "shell.h"
#include <libgen.h>

/**
 * execute_command - a function that execute a command
 * @program_name: the program name.
 * @command: the path of the command
 * Return: nothing.
 */
void execute_command(const char *program_name, const char *command)
{
	int status;
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
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
		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
		{
			char *executable = strdup(command);
			char *base = basename(executable);

			fprintf(stderr, "%s: %s: %s\n", program_name, base, "command not found");

			free(executable);
		}
	}
}

