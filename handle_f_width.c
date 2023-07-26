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
	int current_a;
	int width = 0;

	for (current_a = *a + 1; frmat[current_a] != '\0'; current_a++)
	{
		if (is_digit(frmat[current_a]))
		{
			width *= 10;
			width += frmat[current_a] - '0';
		}
		else if (frmat[current_a] == '*')
		{
			current_a++;
			width = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*a = current_a - 1;

	return (width);
}
