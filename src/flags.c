#include "../inc/ft_printf.h"

void get_special_chars(char *prefix, int type)
{
    if (type == XS)
        ft_strcpy(prefix, "0x");
    else if (type == XL)
        ft_strcpy(prefix, "0X");
    else if (type == O)
        ft_strcpy(prefix, "0");
}

int parse_flags(const char *format, argument *arg)
{
    int     i;

    i = 0;
    if (*format == '%')
        format++;
    while (i < arg->size)
    {
        if (!ft_strchr("#0-+ ", format[i]))
            break;
        if (format[i] == '#')
            get_special_chars(arg->special, arg->type);
        if (format[i] == '0')
            arg->field_filling = arg->alignment == RIGHT ? '0': ' ';
        if (format[i]== '-')
        {
            arg->alignment = LEFT;
            arg->field_filling = ' ';
        }
        if (format[i] == ' ')
            arg->sign_display = arg->sign_display ? '+' : ' ';
        if (format[i] == '+')
            arg->sign_display = '+';
        i++;
    }
    return i;
}