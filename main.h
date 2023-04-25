#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"
#define PARAMS_INT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - typedef struct
 * @unsign: flag
 * @plus_flag: var
 * @space_flag: var
 * @hash_flag: var
 * @zero_flag: on if flag specified
 * @minus_flag: on if _flag specified
 * @width: var
 * @precision: var
 * @h_modifier: var
 * @l_modifier: var
 *
 */


typedef struct parameters
{
	unsigned int unsign	: 1;
	unsigned int plus_flag	: 1;
	unsigned int space_flag	: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag	: 1;
	unsigned int minus_flag	: 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier	: 1;
	unsigned int l_modifier	: 1;
} params_t;


/**
 * struct format_t - typedef struct
 *
 * @t: format
 * @f: the function that gona link the checker
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;


/* prinf.c module */
int _printf(const char *format, ...);


/* fucntion the handles what commes after %*/
/*%s*/
int print_string(va_list ap, params_t *params);
/*%c*/
int print_char(va_list ap, params_t *params);
/*%d %i % */
int print_percent(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);



/*all kind of base conversion */
/*%b*/
int print_binary(va_list ap, params_t *params);
/*%o*/
int print_octal(va_list ap, params_t *params);
/*%x %X*/
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
/*%u*/
int print_unsigned(va_list ap, params_t *params);
/*%r %R*/
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);
/*%p*/
int print_address(va_list ap, params_t *params);
/*handling %S */
int print_S(va_list ap, params_t *params);



/* the function that check the % */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* the function magic to convert any to ASCII */
char *convert(long int num, int base, int flags, params_t *params);

/*putchar handlers*/
int _puts(char *str);
int _putchar(int c);

/*usefull functions*/
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list ap);

/* string_fields.c modoule */
char *get_precision(char *p, params_t *params, va_list ap);


#endif
