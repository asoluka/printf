#include "main.h"
/**
 * handle_f_width - Calculates the printing width
 * @frmat: Formatted string specified to print the arguments.
 * @a: List of arguments to be printed.
 * @lst: lst of arguments.
 *
 * Return: width.
 */
int handle_f_width(const char *frmat, int *a, va_list lst)
{
	int curr_a;
	int width = 0;

	for (curr_a = *a + 1; frmat[curr_a] != '\0'; curr_a++)
	{
		if (is_digit(frmat[curr_a]))
		{
			width *= 10;
			width += frmat[curr_a] - '0';
		}
		else if (frmat[curr_a] == '*')
		{
			curr_a++;
			width = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*a = curr_a - 1;

	return (width);
}
