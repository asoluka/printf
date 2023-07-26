#include "main.h"
/**
 * obt_print_func - Prints a type-based argument.
 * @frmat: Formatted string specified to print the arguments.
 * @lst: List of arguments to be printed.
 * @ind: ind.
 * @buff: Buffer array for print handling.
 * @flags: Calculates the active flags
 * @wdth: get width.
 * @precisn: Precision specification
 * @size: Size indicator
 * Return: 1 or 2;
 */
int obt_print_func(const char *frmat, int *ind,
va_list lst, char buff[], int flags, int wdth, int precisn, int size)
{
	int i, uniden_length = 0, printed_chars = -1;

	frmat_t frmat_types [] = {{'c', prnt_a_char}, {'s', prnt_a_string},
		{'%', prnt_a_percent}, {'i', prnt_a_int}, {'d', prnt_a_int},
		{'b', prnt_a_binary}, {'u', prnt_a_unsigned}, {'o', prnt_a_octal},
		{'x', prnt_a_hexadecimal}, {'X', prnt_a_hexa_upper}, {'p', prnt_a_pointer},
		{'S', prnt_a_non_printable}, {'r', prnt_a_reverse},
		{'R', prnt_a_rot13string}, {'\0', NULL}};
	for (i = 0; frmat_types[i].frmat != '\0'; i++)
		if (frmat[*ind] == frmat_types[i].frmat)
			return (frmat_types[i].fn(lst, buff, flags, wdth, precisn, size));
	if (frmat_types[i].frmat == '\0')
	{
		if (frmat[*ind] == '\0')
			return (-1);
		uniden_length += write(1, "%%", 1);
		if (frmat[*ind - 1] == ' ')
			uniden_length += write(1, " ", 1);
		else if (wdth)
		{
			--(*ind);
			while (frmat[*ind] != ' ' && frmat[*ind] != '%')
				--(*ind);
			if (frmat[*ind] == ' ')
				--(*ind);
			return (1);
		}
		uniden_length += write(1, &frmat[*ind], 1);
		return (uniden_length);
	}
	return (printed_chars);
}
