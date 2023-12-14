#include "shell.h"
/**
 * path_handle - This function creates a path for the shell to find commands.
 * @path_duplicate: a character pointer for the strtok sys call
 * @commandinput: an argument for the path_handle function
 *
 * Return: return NULL success.
 */
char *path_handle(char *commandinput)
{
	char *path_duplicate;
	char *my_token;
	char path_length[PATH_MAX];
	char *getpath;

	if (access(commandinput, X_OK) == 0)
		return (strdup(commandinput));
	getpath = getenv("PATH");
	if (getpath == NULL)
	{
		perror("failed to get path");
		exit(EXIT_FAILURE);
	}
	path_duplicate = strdup(getpath);
	if (path_duplicate == NULL)
	{
		perror("failed to duplicate path\n");
		exit(EXIT_FAILURE);
	}
	my_token = strtok(path_duplicate, ":");
	while (my_token != NULL)
	{
		snprintf(path_length, sizeof(path_length), "%s, %s", my_token, commandinput);
		if (access(path_length, X_OK) == 0)
		{
			free(path_duplicate);
			return (strdup(path_length));
		}
		my_token = strtok(NULL, ":");
	}
	free(path_duplicate);
	return (NULL);
}

