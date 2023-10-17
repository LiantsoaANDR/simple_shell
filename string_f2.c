#include "shell.h"
/**
 * _strcpy - copies the string pointed to another string
 * @dest: the string to write
 * @src: the string to copie, source
 * Return: the copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i, l = 0;

	while (src[l])
		l++;

	for (i = 0; i < l; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}
/**
 * _strcat - appends a string to an other string
 * @dest: the string that receive the other string
 * @src: the string to append
 * Return: a string from adding src to dest
 */
char *_strcat(char *dest, char *src)
{
	int i, l = 0;

	while (dest[l])
		l++;

	for (i = 0; src[i]; i++)
	{
		dest[l] = src[i];
		l++;
	}

	return (dest);
}
