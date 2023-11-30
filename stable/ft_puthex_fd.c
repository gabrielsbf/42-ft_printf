#include "ft_printf.h"

void	ft_puthex_fd(int n, int fd)
{
	unsigned int	hex_v;

	hex_v = (unsigned int) n;
	ft_putnbr_fd(n,1);
	ft_putchar_fd('\n', 1);
	char replace_v[17];

	ft_strlcpy(replace_v, "0123456789abcdef", 17);

	while(n / 16 > 15)
	{
		ft_putchar_fd(replace_v[n % 16], 1);
		n = n / 16;
	}
	ft_putchar_fd(replace_v[n % 16], 1);
}
