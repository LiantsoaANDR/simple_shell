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
	dest[l] = '\0';

	return (dest);
}
/**
 * _atoi - convert a string into an integer
 * @s: the string to convert
 * Return: the interger
 */
int _atoi(char *s)
{
	int sign = 1, i = 0;
	unsigned int res = 0;

	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}

	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}

	return (res);
}
