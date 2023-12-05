#include "ft_printf.h"

void	ft_select_format (va_list args, int * result, char type)
{
	if (type == 'c' || type == 's' || type == '%' )
		ft_char_count(args, result, type);
	else if (type == 'd' || type == 'y' || type == 'x'||
	type == 'X' || type == 'p')
	{
		ft_nb_count(args, result, type);
	}
}
void	ft_char_count(va_list args, int *result, char type)
{
	if (type == 'c')
		*result = *result + 1;
	if (type == 's')
		*result = *result + ft_strlen(va_arg(args, const char *));
	if (type == '%')
		*result = *result + 1;
}

void	ft_nb_count(va_list args, int *result, char type)
{
	int	i;

	if (type =='d')
		i = va_arg(args, int);
	if (type == 'u')
		i = va_arg(args, unsigned int);
	if (type == 'x' || type == 'X' || type == 'p')
		i = va_arg(args, unsigned long);
	if (type == 'd' || type == 'u' || type == 'p')
	{
		while (i / 10 >= 10)
			*result = *result + 1;
		*result = *result + 1;
	}
	if (type == 'x' || type == 'X' || type == 'p' )
	{
		while (i / 16 >= 16)
			*result = *result + 1;
		*result = *result + 1;
	}
}


