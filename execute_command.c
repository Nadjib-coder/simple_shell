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
	pid_t pid;
	int status;

	if (!command_exists(args[0]))
	{
		fprintf(stderr, "%s: %d: %s: not found\n", prg_name, cmd_num, args[0]);
		return;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *envp[] = {NULL}, *path;

		execve(args[0], args, envp);
		path = getenv("PATH");
		if (path != NULL)
		{
			char *path_copy = strdup(path);
			char *dir = strtok(path_copy, ":");

			while (dir != NULL)
			{
				char full_path[1024];

				snprintf(full_path, sizeof(full_path), "%s%s", dir, args[0]);
				execve(full_path, args, envp);
				dir = strtok(NULL, ":");
			}
			free(path_copy);
		}
		fprintf(stderr, "%s: %d: %s: not found\n ", prg_name, cmd_num, args[0]);
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}

