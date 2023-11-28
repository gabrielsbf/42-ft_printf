#include "ft_printf.h"
//CORRECT "p" i have to use hexadecimal value
static int	return_arg(va_list args, char type, int i)
{
	char formats[10];

	ft_strlcpy(formats, "cspdiuxX%", 10);
	if (!ft_strchr(formats, type))
		return (i - 1);
	if (type == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (type == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (type == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (type == 'u')
		ft_putnbu_fd(va_arg(args, unsigned int), 1);
	else if (type == 'p')
		ft_puthex_fd(va_arg(args, int), 1);
	return (i + 1);
}

int	ft_printf(const char * text, ...)
{
	va_list args;
	int	result;
	int i;

	result = 0;
	i = 0;
	va_start(args, text);
	while (text[i] != '\0')
	{
		if(text[i] == '%' && text[i++] != '\0')
		{
			i = return_arg(args, text[i], i);
			if (text[i] != '%')
				result++;
		}
		if(text[i] == '\0')
			break;
		ft_putchar_fd(text[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
	va_end(args);
	return (result);
}

int	main()
{
	int val = 200;
	int *pointer = &val;

	ft_printf("Fazendo %c novo teste: %p", '1', pointer);
	printf("Fazendo %c novo teste: %p\n", '1', pointer);
}
