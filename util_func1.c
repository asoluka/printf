#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * prt_a_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int prt_a_unsigned(va_list types, char buffer[],
			    int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (print_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * prt_a_octal - Prints an unsigned number in octal notation
 * @types: arguments list
 * @buffer: buffer
 * @flags: flags
 * @width: width input
 * @precision: precision
 * @size: size
 * Return: string length
 */
int prt_a_octal(va_list types, char buffer[],
			 int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & FUNC_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (print_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * prt_a_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: arguments list
 * @buffer: buffer
 * @flags: flags
 * @width: width input
 * @precision: precision
 * @size: size
 * Return: string length
 */
int prt_a_hexadecimal(va_list types, char buffer[],
				  int flags, int width, int precision, int size)
{
	return (prt_a_hexa(types, "0123456789abcdef", buffer,
				    flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * prt_a_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: arguments list
 * @buffer: buffer
 * @flags: flags
 * @width: width input
 * @precision: precision
 * @size: size
 * Return: string length
 */
int prt_a_hexa_upper(va_list types, char buffer[],
				 int flags, int width, int precision, int size)
{
	return (prt_a_hexa(types, "0123456789ABCDEF", buffer, flags,
				    'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * prt_a_hexa - Prints a hexadecimal number in lower or upper
 * @types: arguments list
 * @map_to: Array of values to map to numbers
 * @buffer: Buffer
 * @flags:  flags
 * @flag_ch: Calculates active flags
 * @width: width input
 * @precision: Precision
 * @size: Size
 * Return: string length
 */
int prt_a_hexa(va_list types, char map_to[], char buffer[],
			int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & FUNC_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (print_unsgnd(0, i, buffer, flags, width, precision, size));
}

