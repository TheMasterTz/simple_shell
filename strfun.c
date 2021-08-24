#include "shell.h"

unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	for (len = 0; str[len]; len++);
	return (len);
}
