#include "main.h"

/**
 * rep_prnt_char - Prints string
 * @c: char types.
 * @buff: Buffer array to handle print
 * @flgs:  Calculates active flags.
 * @wdth: get width.
 * @precisn: precision indicator
 * @size: Size indicator
 *
 * Return: Number of printed chars.
 */
int rep_prnt_char(char c, char buff[],
int flgs, int wdth, int precisn, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precisn);
	UNUSED(size);

	if (flgs & FUNC_ZERO)
		padd = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (wdth > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < wdth - 1; i++)
			buff[BUFF_SIZE - i - 2] = padd;

		if (flgs & FUNC_MINUS)
			return (write(1, &buff[0], 1) +
				write(1, &buff[BUFF_SIZE - i - 1], wdth - 1));
		else
			return (write(1, &buff[BUFF_SIZE - i - 1],
				wdth - 1) + write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/**
 * prnt_num - Prints a string
 * @is_negatv: List of arguments
 * @ind: char types.
 * @buff: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @wdth: get wdth.
 * @precisn: precision indicator
 * @size: Size indicator
 *
 * Return: Number of chars printed.
 */
int prnt_num(int is_negatv, int ind, char buff[],
int flgs, int wdth, int precisn, int size)
{
	int lngth = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_charactr = 0;

	UNUSED(size);

	if ((flgs & FUNC_ZERO) && !(flgs & FUNC_MINUS))
		padd = '0';
	if (is_negatv)
		extra_charactr = '-';
	else if (flgs & FUNC_PLUS)
		extra_charactr = '+';
	else if (flgs & FUNC_SPACE)
		extra_charactr = ' ';

	return (print_num(ind, buff, flgs, wdth, precisn,
		lngth, padd, extra_charactr));
}

/**
 * print_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buff
 * @buff: Buffer
 * @flgs: Flags
 * @wdth: wdth
 * @prec: Precision indicator
 * @lngth: Number lngth
 * @padd: Pading char
 * @extra_charactr: Extra char
 *
 * Return: Number of printed chars.
 */
int print_num(int ind, char buff[], int flgs, int wdth,
int prec, int lngth, char padd, char extra_charactr)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0' && wdth == 0)

		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		buff[ind] = padd = ' ';
	if (prec > 0 && prec < lngth)
		padd = ' ';
	while (prec > lngth)
		buff[--ind] = '0', lngth++;
	if (extra_charactr != 0)
		lngth++;
	if (wdth > lngth)
	{
		for (i = 1; i < wdth - lngth + 1; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (flgs & FUNC_MINUS && padd == ' ')
		{
			if (extra_charactr)
				buff[--ind] = extra_charactr;
			return (write(1, &buff[ind], lngth) + write(1, &buff[1], i - 1));
		}
		else if (!(flgs & FUNC_MINUS) && padd == ' ')
		{
			if (extra_charactr)
				buff[--ind] = extra_charactr;
			return (write(1, &buff[1], i - 1) + write(1, &buff[ind], lngth));
		}
		else if (!(flgs & FUNC_MINUS) && padd == '0')
		{
			if (extra_charactr)
				buff[--padd_start] = extra_charactr;
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[ind], lngth - (1 - padd_start)));
		}
	}
	if (extra_charactr)
		buff[--ind] = extra_charactr;
	return (write(1, &buff[ind], lngth));
}

/**
 * prnt_unsigned - Writes an unsigned number
 * @is_negatv: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buff
 * @buff: Array of chars
 * @flgs: Flags indicators
 * @wdth: Width indicator
 * @precisn: Precision indicator
 * @size: Size indicator
 *
 * Return: Number of written chars.
 */
int prnt_unsigned(int is_negatv, int ind, char buff[],
int flgs, int wdth, int precisn, int size)
{
	int lngth = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negatv);
	UNUSED(size);

	if (precisn == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		return (0);

	if (precisn > 0 && precisn < lngth)
		padd = ' ';

	while (precisn > lngth)
	{
		buff[--ind] = '0';
		lngth++;
	}

	if ((flgs & FUNC_ZERO) && !(flgs & FUNC_MINUS))
		padd = '0';

	if (wdth > lngth)
	{
		for (i = 0; i < wdth - lngth; i++)
			buff[i] = padd;

		buff[i] = '\0';

		if (flgs & FUNC_MINUS)
		{
			return (write(1, &buff[ind], lngth) + write(1, &buff[0], i));
		}
		else
		{
			return (write(1, &buff[0], i) + write(1, &buff[ind], lngth));
		}
	}

	return (write(1, &buff[ind], lngth));
}

/**
 * prnt_pointr - Write a memory address
 * @buff: Arrays of chars
 * @ind: Index at which the number starts in the buff
 * @lngth: Length of number
 * @wdth: Width indicator
 * @flgs: Flags indicator
 * @padd: Char representing the padding
 * @extra_charactr: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int prnt_pointr(char buff[], int ind, int lngth,
int wdth, int flgs, char padd, char extra_charactr, int padd_start)
{
	int i;

	if (wdth > lngth)
	{
		for (i = 3; i < wdth - lngth + 3; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (flgs & FUNC_MINUS && padd == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_charactr)
				buff[--ind] = extra_charactr;
			return (write(1, &buff[ind], lngth) + write(1, &buff[3], i - 3));
		}
		else if
			(!(flgs & FUNC_MINUS) && padd == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_charactr)
				buff[--ind] = extra_charactr;
			return (write(1, &buff[3], i - 3) + write(1, &buff[ind], lngth));
		}
		else if (!(flgs & FUNC_MINUS) && padd == '0')
		{
			if (extra_charactr)
				buff[--padd_start] = extra_charactr;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[ind], lngth - (1 - padd_start) - 2));
		}
	}
	buff[--ind] = 'x';
	buff[--ind] = '0';

	if (extra_charactr)
		buff[--ind] = extra_charactr;

	return (write(1, &buff[ind], BUFF_SIZE - ind - 1));
}
