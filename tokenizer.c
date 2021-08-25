#include "shell.h"

char **_tokenizer(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t i, mcount = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * mcount);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	for (i = 0; (tokens[i] = strtok(buffer, delimiter)) != NULL; i++)
	{
		if (i == mcount)
		{
			tokens = N_realloc(tokens, &mcount);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return(NULL);
			}
			mcount += 10;
		}
		buffer = NULL;
	}
	return (tokens);
}
char **N_realloc(char **ptr, size_t *size)
{
	char **new;
	size_t iter;

	new = malloc(sizeof(char *) * ((*size) + 10));
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (iter = 0; iter < (*size); iter++)
		new[iter] = ptr[iter];
	free(ptr);
	return (new);
}
