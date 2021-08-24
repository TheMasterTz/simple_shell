#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

typedef struct variables
{
	char **av;
	char *buffer;
	char **env;
	char **argv;
	int status;
	char **commands;
	size_t count;
} vars_t;

typedef struct builtins
{
	char *name;
	void (*f)(vars_t *);
} builtins_t;

unsigned int _strlen(char *str);
ssize_t _puts(char *str);
char *_strcat(char *strc1, char *strc2);

int _strcmp(char * s1, char * s2);
void _strcpy(char *dest, char *src);
char *_strdup(const char *strtodup);
#endif
