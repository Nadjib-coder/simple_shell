#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
	}
	else if (pid == 0)
	{
		/* Child process */
		char *envp[] = {NULL}; /* Empty environment */
		char *args[2];
	       	
		args[0] = strdup(command);
		args[1] = NULL;
		execve(command, args, envp);
		/* execve only returns if an error occurs */
		fprintf(stderr, "Exec failed for command: %s\n", command);
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
		printf("shell> ");
		fflush(stdout);
		read = getline(&input, &input_size, stdin);
		if (read == -1)
		{
			printf("Exiting shell...\n");
			break; /* Exit on Ctrl+D or error */
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

