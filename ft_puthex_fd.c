#include "ft_printf.h"

void	ft_puthex_fd(int n, int fd)
{
	unsigned int	hex_v;

	hex_v = (unsigned int) n;
	ft_putnbu_fd(hex_v, fd);
	char replace_v[17];
	ft_strlcpy(replace_v, "0123456789abcdef", 17);

	if (n > 16)
	{
		ft_puthex_fd(n / 16, fd);
		ft_puthex_fd(n % 16, fd);
	}
	else
		ft_putchar_fd(replace_v[n % 16], fd);

}
