#include "main.h"
/**
 * get_precisn - Calculates the printing precision
 * @frmat: Formatted string specified to print the arguments
 * @a: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precisn(const char *frmat, int *a, va_list lst)
{
	int current_a = *a + 1;
	int precisn = -1;

	if (frmat[current_a] != '.')
		return (precisn);
	precisn = 0;
	for (current_a += 1; frmat[current_a] != '\0'; current_a++)
	{
		if (is_digit(frmat[current_a]))
		{
			precisn *= 10;
			precisn += frmat[current_a] - '0';
		}
		else if (frmat[current_a] == '*')
		{
			current_a++;
			precisn = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*a = current_a - 1;

	return (precisn);
}
