#include "main.h"
/**
 * get_size - Calculates the argument casting size
 * @frmat: Formatted string specified to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *frmat, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (frmat[curr_i] == 'l')
		size = SZ_LONG;
	else if (frmat[curr_i] == 'h')
		size = SZ_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
	return (size);
}
