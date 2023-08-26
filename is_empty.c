#include "shell.h"

/**
 * is_empty - a function that handle empty imput
 * @input: the input user
 * Return: 0 (Success), 1 (failed).
 */
int is_empty(const char *input)
{
	size_t i;

	for (i = 0; i < strlen(input); i++)
	{
		if (!isspace(input[i]))
		{
			return (0);
		}
	}
	return (1);
}

