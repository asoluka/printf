#include "main.h"
/**
 * obtain_precision - Calculates the printing precision
 * @frmat: Formatted string specified to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int obtain_precision(const char *frmat, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (frmat[curr_i] != '.')
		return (precision);
	precision = 0;
	for (curr_i += 1; frmat[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(frmat[curr_i]))
		{
			precision *= 10;
			precision += frmat[curr_i] - '0';
		}
		else if (frmat[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
