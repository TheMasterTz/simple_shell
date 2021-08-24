#include "shell.h"

/**
 * _strlen - lenght string
 * @str: string
 * Return: len
 */
unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
 * _puts - print function
 * @str: string
 * Return: len
 */
ssize_t _puts(char *str)
{
	ssize_t num = 0, len = 0;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}

