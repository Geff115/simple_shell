#include "shell.h"
/**
 * prog_invoke - This function executes the program
 * @my_path: path of the executable
 * @my_args: receives the number of arguments for the path.
 *
 * Return: NULL success.
 */
void prog_invoke(char *my_path, char *my_args[])
{
	int status;
	char *full_path;
	pid_t new_process;

	full_path = path_handle(my_path);
	if (full_path == NULL)
	{
		our_print("failed to find command");
		return;
	}
	new_process = fork();
	if (new_process == -1)
	{
		perror("failed to create a child process");
		exit(EXIT_FAILURE);
	}
	else if (new_process == 0)
	{
		char *envp[] = { NULL };

		if (execve(full_path, my_args, envp) == -1)
		{
			perror("failed to load the program\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free(full_path);
		wait(&status);
	}
}

