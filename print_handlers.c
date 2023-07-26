#include "main.h"

/**
 * handle_print_char - Prints string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision indicator
 * @size: Size indicator
 *
 * Return: Number of printed chars.
 */
int handle_print_char(char c, char buffer[],
int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FUNC_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & FUNC_MINUS)
			return (write(1, &buffer[0], 1) +
				write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1],
				width - 1) + write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * print_number - Prints a string
 * @is_negatv: List of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision indicator
 * @size: Size indicator
 *
 * Return: Number of chars printed.
 */
int print_number(int is_negatv, int ind, char buffer[],
int flags, int width, int precision, int size)
{
	int lngth = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_c = 0;

	UNUSED(size);

	if ((flags & FUNC_ZERO) && !(flags & FUNC_MINUS))
		padd = '0';
	if (is_negatv)
		extra_c = '-';
	else if (flags & FUNC_PLUS)
		extra_c = '+';
	else if (flags & FUNC_SPACE)
		extra_c = ' ';

	return (print_num(ind, buffer, flags, width, precision,
		lngth, padd, extra_c));
}

/**
 * print_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buff
 * @buffer: Buffer
 * @flags: Flags
 * @width: wdth
 * @prec: Precision indicator
 * @lngth: Number lngth
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int print_num(int ind, char buffer[], int flags, int width,
int prec, int lngth, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)

		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < lngth)
		padd = ' ';
	while (prec > lngth)
		buffer[--ind] = '0', lngth++;
	if (extra_c != 0)
		lngth++;
	if (width > lngth)
	{
		for (i = 1; i < width - lngth + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & FUNC_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], lngth) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & FUNC_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], lngth));
		}
		else if (!(flags & FUNC_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], lngth - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], lngth));
}

/**
 * print_unsgnd - Writes an unsigned number
 * @is_negatv: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buff
 * @buffer: Array of chars
 * @flags: Flags indicators
 * @width: Width indicator
 * @precision: Precision indicator
 * @size: Size indicator
 *
 * Return: Number of written chars.
 */
int print_unsgnd(int is_negatv, int ind, char buffer[],
int flags, int width, int precision, int size)
{
	int lngth = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negatv);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < lngth)
		padd = ' ';

	while (precision > lngth)
	{
		buffer[--ind] = '0';
		lngth++;
	}

	if ((flags & FUNC_ZERO) && !(flags & FUNC_MINUS))
		padd = '0';

	if (width > lngth)
	{
		for (i = 0; i < width - lngth; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & FUNC_MINUS)
		{
			return (write(1, &buffer[ind], lngth) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], lngth));
		}
	}

	return (write(1, &buffer[ind], lngth));
}

/**
 * print_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buff
 * @lngth: Length of number
 * @width: Width indicator
 * @flags: Flags indicator
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int print_pointer(char buffer[], int ind, int lngth,
int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > lngth)
	{
		for (i = 3; i < width - lngth + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & FUNC_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], lngth) + write(1, &buffer[3], i - 3));
		}
		else if
			(!(flags & FUNC_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], lngth));
		}
		else if (!(flags & FUNC_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], lngth - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';

	if (extra_c)
		buffer[--ind] = extra_c;

	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
