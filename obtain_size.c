#include "main.h"
/**
 * obtain_size - Calculates the argument casting size
 * @format: Formatted string specified to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int obtain_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = SZ_LONG;
	else if (format[curr_i] == 'h')
		size = SZ_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
	return (size);
}
