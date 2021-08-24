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

