#include "main.h"
/**
 * obt_print_func - Prints a type-based argument.
 * @fmt: Formatted string specified to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buff: Buffer array for print handling.
 * @flags: Calculates the active flags
 * @wdth: get width.
 * @precisn: Precision specification
 * @size: Size indicator
 * Return: 1 or 2;
 */
int obt_print_func(const char *fmt, int *ind,
va_list list, char buff[], int flags, int wdth, int precisn, int size)
{
	int i, uniden_length = 0, printed_chars = -1;

	fmt_t fmt_types [] = {{'c', prt_a_char}, {'s', prt_a_string},
		{'%', prt_a_percent}, {'i', prt_a_int}, {'d', prt_a_int},
		{'b', prt_a_binary}, {'u', prt_a_unsigned}, {'o', prt_a_octal},
		{'x', prt_a_hexadecimal}, {'X', prt_a_hexa_upper}, {'p', prt_a_pointer},
		{'S', prt_a_non_printable}, {'r', prt_a_reverse},
		{'R', prt_a_rot13string}, {'\0', NULL}};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(lst, buff, flags, wdth, precisn, size));
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		uniden_length += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			uniden_length += write(1, " ", 1);
		else if (wdth)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		uniden_length += write(1, &fmt[*ind], 1);
		return (uniden_length);
	}
	return (printed_chars);
}
