#include "shell.h"

#define MAX_INPUT_SIZE 1024

void display_prompt() {
    printf("#cisfun$ ");
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        // Display prompt
        display_prompt();

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle Ctrl+D (end of file)
            printf("\n");
            break;
        }

        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        // Fork a new process
        pid_t pid = fork();

        if (pid == -1) {
            // Handle fork error
            perror("Fork error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            // Execute the command using execve
            if (execlp(input, input, (char *)NULL) == -1) {
                // Handle execution error
                perror("Execution error");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            // Wait for the child process to complete
            wait(NULL);
        }
    }

    return 0;
}
