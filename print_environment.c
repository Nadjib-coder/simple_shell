#include "shell.h"

/**
 * print_environment - a function that prints
 * the current environment
 * Return: Nothing.
 */
void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

