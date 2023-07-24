#ifndef MAIN_HEADER
#define MAIN_HEADER
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* CUSTOM FLAGS */
#define FUNC_MINUS 1
#define FUNC_PLUS 2
#define FUNC_ZERO 4
#define FUNC_HASH 8
#define FUNC_SPACE 16

/* CUSTOM SIZES */
#define SZ_LONG 2
#define SZ_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: format input.
 * @fn: function.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: format input.
 * @fm_t: function.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print_func(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** UTILITY FUNCTIONS ******************/
int prt_a_char(va_list types, char buffer[],
			int flags, int width, int precision, int size);
int prt_a_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int prt_a_percent(va_list types, char buffer[], int flags, int width, int precision, int size);

int prt_a_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int prt_a_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int prt_a_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int prt_a_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int prt_a_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int prt_a_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);

int prt_a_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);

int prt_a_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);

int prt_a_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);

int obtain_flags(const char *format, int *i);
int obtain_width(const char *format, int *i, va_list list);
int obtain_precision(const char *format, int *i, va_list list);
int obtain_size(const char *format, int *i);

int prt_a_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);

int prt_a_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

int handle_print_char(char c, char buffer[], int flags, int width, int precision, int size);
int print_number(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);
int print_num(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
int print_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);

int print_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);

/****************** UTILITY 2 ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
