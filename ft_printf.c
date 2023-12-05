#include "ft_printf.h"
//CORRECT "p" i have to use hexadecimal value
//Conclusão - Vou colocar as funções para em void ainda
// com o parametro "result" como memória do ponteiro para armazenar
// o valor

static int	return_arg(va_list args, char type, int i)
{
	if (!ft_strchr("cspdiuxX%", type))
		return (i - 1);
	if (type == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (type == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (type == 'p')
		ft_puthex_fd(va_arg(args, unsigned long ), 1, 1, 0);
	else if (type == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (type == 'u')
		ft_putnbu_fd(va_arg(args, unsigned int), 1);
	else if (type == 'x')
		ft_puthex_fd(va_arg(args, unsigned long), 1, 0, 0);
	else if (type == 'X')
		ft_puthex_fd(va_arg(args, unsigned long), 1, 0, 1);
	else if (type == '%')
		ft_putchar_fd('%', 1);
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
		}
		if(text[i] == '\0')
			break;
		ft_putchar_fd(text[i], 1);
		result++;
		i++;
	}
	va_end(args);
	return (result);
}

int	main()
{
	#include <limits.h>
	int val = 200;
	int *pointer = &val;
	int ft_printf_result = ft_printf("FT_PRINTF: Fazendo %d novo teste %s\n", 15, "pointer");
	printf("%d\n", ft_printf_result);
	int printf_result = printf("PRINTF: Fazendo %d novo teste %s\n", 15, "pointer");
	printf("%d\n", printf_result);
}
