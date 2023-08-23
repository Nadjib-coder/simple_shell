#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100

int main(void) {
    char input[MAX_INPUT_LENGTH];
    char prompt[] = "#cisfun$ ";
    pid_t child_pid;

    while (1) {
        printf("%s", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            execlp(input, input, NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        } else {
            int status;
            waitpid(child_pid, &status, 0);

            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                if (exit_status != 0) {
                    fprintf(stderr, "%s: Command '%s' exited with status %d\n", prompt, input, exit_status);
                }
            }
        }
    }

    return 0;
}

