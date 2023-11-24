#include "ft_printf.h"

static int count_args(const char * text)
{
	while (*text)
		ft_
}

int	ft_printf(const char * text, ...)
{
	va_list args;
	int	result;
	int i;

	result = 0;
	i = 0;
	va_start(args, count);
	while (i++ < count)
		result += va_arg(args, int);
	ft_putnbr_fd(result, 1);
	ft_putchar_fd('\n', 1);
	va_end(args);
	return (result);
}

int	main()
{
	ft_printf(4 , 1, 3, 5, 9);
}
