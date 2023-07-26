#include "main.h"
/**
 * obtain_width - Calculates the printing width
 * @frmat: Formatted string specified to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int obtain_width(const char *frmat, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; frmat[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(frmat[curr_i]))
		{
			width *= 10;
			width += frmat[curr_i] - '0';
		}
		else if (frmat[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
