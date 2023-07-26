#include "main.h"
/**
 * get_precisn - Calculates the printing precision
 * @frmat: Formatted string specified to print the arguments
 * @i: List of arguments to be printed.
 * @lst: list of arguments.
 *
 * Return: Precision.
 */
int get_precisn(const char *frmat, int *i, va_list lst)
{
	int curr_i = *i + 1;
	int precisn = -1;

	if (frmat[curr_i] != '.')
		return (precisn);
	precisn = 0;
	for (curr_i += 1; frmat[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(frmat[curr_i]))
		{
			precisn *= 10;
			precisn += frmat[curr_i] - '0';
		}
		else if (frmat[curr_i] == '*')
		{
			curr_i++;
			precisn = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precisn);
}
