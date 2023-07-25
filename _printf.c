#include "main.h"

void prt_a_buffer(char buffer[], int *buff_ind);

/**
 * _printf - custom printf function
 * @format: format input.
 * Return: appropriate formated text.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				prt_a_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			prt_a_buffer(buffer, &buff_ind);
			flags = obtain_flags(format, &i);
			width = obtain_width(format, &i, list);
			precision = obtain_precision(format, &i, list);
			size = obtain_size(format, &i);
			++i;
			printed = handle_print_func(format, &i, list,
								   buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	prt_a_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * prt_a_buffer - print buffer
 * @buffer: chars array input
 * @buff_ind: string index to interpolate values
 */
void prt_a_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
