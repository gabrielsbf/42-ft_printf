/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:19:39 by gabrfern          #+#    #+#             */
/*   Updated: 2023/12/06 15:19:40 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_fd(unsigned long long n, int fd, int prefix, int *result)
{
	char	replace_v[17];

	if (prefix == 1)
	{
		if(n == 0)
		{
			write(1, "(nil)", 5);
			*result = *result + 5;
			return ;
		}
		ft_putstr_fd("0x", 1, result);
		prefix = 0;
	}
	ft_strlcpy(replace_v, "0123456789abcdef", 17);
	if (n >= 16)
	{
		ft_puthex_fd(n / 16, fd, prefix, result);
		ft_puthex_fd(n % 16, fd, prefix, result);
	}
	else
		ft_putchar_fd(replace_v[n % 16], fd, result);
}

void	ft_puthex_upper_fd(unsigned long long n, int fd, int *result)
{
	char	replace_v[17];

	ft_strlcpy(replace_v, "0123456789ABCDEF", 17);
	if (n >= 16)
	{
		ft_puthex_upper_fd(n / 16, fd,  result);
		ft_puthex_upper_fd(n % 16, fd, result);
	}
	else
		ft_putchar_fd(replace_v[n % 16], fd, result);
}
