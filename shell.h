#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

#define ARG_MAX 256
#define delimeter ":"

char *path_handle(char *commandinput);
void display_prompt(void);
void our_print(const char *message);
void handle_com_line_args(char *new_input, char *args[]);
void prog_invoke(char *my_path, char *my_args[]);
void my_comm(char **my_string, size_t *size);
void input_handle(char *string_input);
void output_my_environ(void);

#endif
