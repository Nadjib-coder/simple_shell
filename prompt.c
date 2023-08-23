#include <stdio.h>
#include <stdlib.h>

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream) {
    ssize_t chars_read = 0;

    if (*lineptr == NULL || *n == 0) {
        *lineptr = (char *)malloc(128);
        if (*lineptr == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        *n = 128;
    }

    chars_read = getline(lineptr, n, stream);
    if (chars_read != -1 && (*lineptr)[chars_read - 1] == '\n') {
        (*lineptr)[chars_read - 1] = '\0';
        return (chars_read - 1);
    }

    return (chars_read);
}

void _prompt(void)
{
        size_t n;
        char *buffer = NULL;

        printf("$ ");
        custom_getline(&buffer, &n, stdin);
        printf("%s\n", buffer);
	free(buffer);
}

