#include "shell.h"
/**
 * main - The start of the program.
 * input_handle - This function takes a string as input, removes the newline character at the end of the string, and then passes the string.
 * @string_input: A character pointer.
 *
 * Return: return NULL for the void function. for the main function, return (0) success.
 */
void input_handle(char *string_input)
{
	char *args[ARG_MAX];
	size_t length;

	length = strlen(string_input);
	if (length > 0 && string_input[length - 1] == '\n')
		string_input[length - 1] = '\0';
	handle_com_line_args(string_input, args);
	prog_invoke(args[0], args);
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int p = 1;

		while (p < argc)
		{
			input_handle(argv[p]);
			p++;
		}
	}
	else
	{
		char *string_input = NULL;
		size_t sz = 0;

		while (1)
		{
			if (isatty(STDIN_FILENO))
			{
				display_prompt();
				my_comm(&string_input, &sz);
				if (strcmp(string_input, "exit\n") == 0)
				{
					free(string_input);
					break;
				}
				else
					input_handle(string_input);
			}
		}
	}
	return (0);
}

