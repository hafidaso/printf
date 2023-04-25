#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @arg: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *arg, params_t *params, va_list ap)
{
	int d = 0;

	if (*arg != '.')
		return (arg);
	arg++;
	if (*arg == '*')
	{
		d = va_arg(ap, int);
		arg++;
	}
	else
	{
		while (_isdigit(*arg))
			d = d * 10 + (*arg++ - '0');
	}
	params->precision = d;
	return (arg);
}

