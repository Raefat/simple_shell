#ifndef _SHELL_H
#define _SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#define DELIM "\n \t"
extern char **environ;


char **parse_tokens(char *command, int *num_tokens);
void free_tokens(char **tokens, int *num_tokens);
int token_count(const char *commands);
int execute_cmd(char **commands, char *filename,
                int *num_tokens, char *buffer);


/* paths and env */

char *get_paths();
char *get_matched_path(const char *command);
char *full_path_maker(const char *path, const char *command);
int is_command_path(const char *command);
int exec_builtins(char *command);

/* string functions */

int _strncmp(const char *str1, const char *str2, size_t n);
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *str);
unsigned int _strlen(const char *s);
char* _strcpy(char* destination, const char* source);
char *_strcat(char *dest, const char *src);

#endif
