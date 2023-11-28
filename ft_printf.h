#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

int		ft_printf(const char *, ...);
void	ft_putnbu_fd(unsigned int n, int fd);
void	ft_puthex_fd(int n, int fd);

#endif
