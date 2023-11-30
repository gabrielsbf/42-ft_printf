#include "ft_printf.h"

void	ft_puthex_fd(unsigned long n, int fd, int prefix, int is_upper)
{
	char	replace_v[17];

	if (prefix == 1)
	{
		ft_putstr_fd("0x", 1);
		prefix = 0;
	}
	if (is_upper == 0)
		ft_strlcpy(replace_v, "0123456789abcdef", 17);
	else
		ft_strlcpy(replace_v, "0123456789ABCDEF", 17);
	if (n >= 16)
	{
		ft_puthex_fd(n / 16, fd, prefix, is_upper);
		ft_puthex_fd(n % 16, fd, prefix, is_upper);
	}
	else
		ft_putchar_fd(replace_v[n % 16], fd);
}
