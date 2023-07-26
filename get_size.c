#include "main.h"
/**
 * get_size - Calculates the argument casting size
 * @frmat: Formatted string specified to print the arguments
 * @a: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *frmat, int *a)
{
	int current_a = *a + 1;
	int size = 0;

	if (frmat[current_a] == 'l')
		size = SZ_LONG;
	else if (frmat[current_a] == 'h')
		size = SZ_SHORT;

	if (size == 0)
		*a = current_a - 1;
	else
		*a = current_a;
	return (size);
}
