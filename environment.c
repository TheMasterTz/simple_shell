#include "shell.h"

void free_env(char **env)
{
	unsigned int iter;

	for (iter = 0; env[iter] != NULL; iter++)
		free(env[iter]);
	free(env);
}


