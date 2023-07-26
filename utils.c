#include "main.h"

/**
 * its_prntabl - Evaluates if char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int its_prntabl(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * appnd_hex_code - Append ascci in hexadecimal code to buff
 * @buff: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */
int appnd_hex_code(char ascii_code, char buff[], int i)
{
	char project_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buff[i++] = '\\';
	buff[i++] = 'x';

	buff[i++] = project_to[ascii_code / 16];
	buff[i] = project_to[ascii_code % 16];

	return (3);
}

/**
 * its_a_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int its_a_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * change_size_number - Casts a number to the specified size
 * @number: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of number
 */
long int change_size_number(long int number, int size)
{
	if (size == LONG_SIZE)
		return (number);
	else if (size == SHORT_SIZE)
		return ((short)number);

	return ((int)number);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @number: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of number
 */
long int convert_size_unsgnd(unsigned long int number, int size)
{
	if (size == LONG_SIZE)
		return (number);
	else if (size == SHORT_SIZE)
		return ((unsigned short)number);

	return ((unsigned int)number);
}
