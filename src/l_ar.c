#include "ft_printf.h"

void show_mem_a(unsigned short *a, int flag)
{
	int i = 1;
	printf("%d |", a[0]);
	while (i <= a[0])
		printf("%d", a[i++]);
	printf("\n");
	if (flag)
		exit(1); 
}

unsigned short		*long_write_lint(unsigned long n)
{
	int					i;
	int					len;
	unsigned short  	*result;

	len = getsize(n) + 1;
	i = 1;
	result = (unsigned short *)malloc(sizeof(unsigned short) * len);
	if (!result)
		exit(1);
	long_nbzero(result, len);
	result[0] = len - 1;
	while (n) {
		result[i++] = n % 10;
		n /= 10;
	}
	return (result);
}

void		long_write_double_ipart(unsigned short *result, \
											unsigned res_len, unsigned ipart)
{
	int		i;

	i = res_len - 1;
	result[0] = res_len - 1;
	i = res_len - 1;
	while (ipart)
	{
		result[i++] = ipart % 10;
		ipart /= 10;
	}
}

void		long_write_double_fpart(unsigned short *result, \
											unsigned res_len, double fpart)
{
	int		i;
	int		tmp;

	i = res_len - 1 - 1;
	tmp = 0;
	while (i >= 1)
	{
		fpart *= 10;
		tmp = fpart;
		result[i--] = tmp;
		fpart -= tmp;
	}
}

unsigned short 		*long_write_double(long double d, char flag)
{
	unsigned long	ipart;
	double			fpart;
	unsigned		res_len;
	unsigned short	*result;

	ipart = d;
	fpart = d - ipart;
	if (flag)
		ipart++;
	res_len = 1 + RIGOR + 1;
	result = (unsigned short *)malloc(sizeof(unsigned short) * res_len);
	if (!result)
		exit(1);
	long_nbzero(result, res_len);
	long_write_double_ipart(result, res_len, ipart);
	long_write_double_fpart(result, res_len, fpart);
	return (result);
}

int long_toa_wipart(char *dest, t_sme *rounded)
{
	int i;
	int j;
	int len;

	i = 0;
	j = rounded->rounded[0];
	len = rounded->point - 1;
	if (rounded->sign == -1)
		dest[i++] = '-';
	while (len)
	{
		dest[i++] = rounded->rounded[j--] + '0';
		len--;
	}
	dest[i] = 0;
	return (i);
}

int long_toa_wfpart(char *dest, int i, t_sme *rounded)
{
	int len;
	int counter;
	int ipart;
	int j;

	len = rounded->rounded[0];
	counter = 0;
	ipart = i;
	j = rounded->sign == - 1 ? 2 : 1;
	while (counter < rounded->afterpoint)
	{
		if (counter >= rounded->rounded[0] - ipart)
		{
			dest[i++] = '0';
			counter++;
			continue;
		}
		dest[i] = rounded->rounded[len-i+j] + '0';
		i++;
		counter++;
	}
	dest[i] = 0;
	return (i);
}

char 				*long_toa(t_sme *rounded, char *specdot)
{
	char 				*result;
	int 				str_len;
	int					point;
	int					end;

	str_len = rounded->point - 1 + rounded->afterpoint;
	str_len += (rounded->afterpoint || *specdot) ? 1 : 0;
	str_len += (rounded->sign < 0) ? 1 : 0;
	result = (char *)malloc(sizeof(char) * str_len + 1);
	if (!result)
		exit(1);
	point = long_toa_wipart(result, rounded);
	if (rounded->afterpoint)
		result[point++] = '.';
	end = long_toa_wfpart(result, point, rounded);
	if (*specdot && !rounded->afterpoint)
	{
		result[end] = '.';
		result[end + 1] = 0;
	}
	*specdot = 0;
	return (result);
}

void get_term(t_sme *n, unsigned short *term)
{
	int term_len;
	int i;
	int ipart;
	int fpart;

	ipart = n->point - 1;
	fpart = (n->afterpoint > n->result[0] - ipart) ? n->result[0] - ipart : n->afterpoint;
	term_len = n->result[0] - ipart - fpart;
	i = 1;
	term[0] = term_len;
	while (i < term[0])
		term[i++] = 0;
	term[i] = 5;
}

char				*long_round(t_sme *n, char *specdot)
{
	unsigned short	number1[n->result[0] + 1];
	unsigned short	number2[n->result[0] + 1];
	char			*final;

	long_nbcopy(number1, n->result);
	get_term(n, number2);
	n->rounded = long_add(number1, number2, &n->point);
	final = long_toa(n, specdot);
	return (final);
}
