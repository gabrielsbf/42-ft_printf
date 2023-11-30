#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

int		ft_printf(const char *, ...);
void	ft_putnbu_fd(unsigned int n, int fd);
void	ft_puthex_fd(unsigned long n, int fd, int prefix, int is_upper);
void	ft_putchar_fdnr(char c, int fd);

#endif
