#include "main.h"

/**
 * _printf - print anything
 * @format: the format string
 * Return: number of byt printed
 */

int _printf(const char *format, ...)
{
	int som = 0;
	va_list args;
	char *arg, *start;
	params_t params = PARAMS_INIT;
	
	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (arg = (char *)format; *arg; arg++)
	{
		init_params(&params, ap);
		if (*arg != '%')
		{
			som += _putchar(*arg);
			continue;
		}
		start = arg;
		arg++;
		while (get_flag(arg, &params)) /* while char at arg is flag char */
		{
			arg++; /* next char */
		}
		arg = get_width(arg, &params, ap);
		arg = get_precision(arg, &params, ap);
		if (get_modifier(arg, &params))
			arg++;
		if (!get_specifier(arg))
			som += print_from_to(start, arg,
				params.l_modifier || params.h_modifier ? arg - 1 : 0);
		else
			som += get_print_func(arg, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (som);
}
