#include "../inc/ft_printf.h"

static void     handle_right(argument *arg, size_t *printed, char *field)
{
	if (arg->field_filling == ' ' && field)
		*printed += cputstr(field);
	if (arg->afterpoint >= 0)
	{
		*printed += cputchar(arg->sign_display);
		*printed += cputstr(arg->special);
	}
	else if (arg->type == O && arg->special)
		*printed += cputstr(arg->special);
	if (arg->field_filling == '0' && field)
		*printed += cputstr(field);
	if (arg->afterpoint >= 0 || arg->field_size > 0)
		*printed += cputstr(arg->data);
	ft_strdel(&field);
}

static void     handle_left(argument *arg, size_t *printed, char *field)
{
	if (arg->afterpoint >= 0 || arg->field_size > 0)
	{
		*printed += cputchar(arg->sign_display);
		*printed += cputstr(arg->special);
		*printed += cputstr(arg->data);
	}
	else if (arg->type == O && arg->special)
		*printed += cputstr(arg->special);
	if (field)
		*printed += cputstr(field);
	ft_strdel(&field);
}

static int     define_precision(argument *arg)
{
	int     precision;
	int		data_len;
	char	*data;

	data_len = ft_strlen(arg->data);
	precision = arg->afterpoint - data_len;
	if (arg->type >= F && arg->type <= U)
		if (precision > 0)
		{
			data = ft_memset(ft_memalloc(precision), '0', precision + data_len);
			ft_memmove(data + precision, arg->data, data_len);
			ft_strdel(&(arg->data));
			arg->data = data;
			arg->field_filling = ' ';
			return (precision);
		}
		else if (arg->afterpoint == -1 && arg->type != O)
			if (arg->field_size > 0)
			{
				data = arg->data;
				arg->data = ft_strdup(" ");
				ft_strdel(&data);
			}
	return (0);
}

size_t	        arg_print(argument *arg)
{
	int		fillsize;
	char    *field;
	size_t	printed;

	printed = 0;
	field = 0;
	fillsize = arg->field_size - ft_strlen(arg->data) - ft_strlen(arg->special)\
		- (arg->sign_display ? 1 : 0) - define_precision(arg);
	if (fillsize > 0)
		field = ft_memset(ft_memalloc(fillsize), arg->field_filling, fillsize);
	if (arg->alignment == RIGHT)
		handle_right(arg, &printed, field);
	else
		handle_left(arg, &printed, field);
	return (printed);
}