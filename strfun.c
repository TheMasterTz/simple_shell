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

/**
 * _strcat - function concatenates
 * @strc1: string 1
 * @strc2: string 2
 * Return: Newstring
 */
char *_strcat(char *strc1, char *strc2)
{
	char *NewString;
	unsigned int len1 = 0, len2 = 0, Newlen;
	unsigned int iter1, iter2;

	if (strc1 == NULL)
		len1 = 0;
	else
		for (len1 = 0; strc1[len1]; len1++)
			;
	if (strc2 == NULL)
		len2 = 0;
	else
		for (len2 = 0; strc2[len2]; len2++)
			;
	Newlen = len1 + len2 + 2;
	NewString = malloc(Newlen * sizeof(char));
	if (NewString == NULL)
		return (NULL);
	for (iter1 = 0; iter1 < len1; iter1++)
		NewString[iter1] = strc1[iter1];
	NewString[iter1] = '/';
	for (iter2 = 0; iter2 < len2; iter2++)
		NewString[iter1 + 1 + iter2] = strc2[iter2];
	NewString[len1 + len2 + 1] = '\0';
	return (NewString);
}
