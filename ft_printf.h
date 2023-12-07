/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:22:26 by gabrfern          #+#    #+#             */
/*   Updated: 2023/12/06 15:22:27 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *text, ...);
void	ft_putnbu_fd(unsigned int n, int fd, int *result);
void	ft_putnbr_fd(int n, int fd, int *result);
void	ft_putstr_fd(char *s, int fd, int *result);
void	ft_puthex_fd(unsigned long long n, int fd, int prefix, int *result);
void	ft_puthex_upper_fd(unsigned long long n, int fd, int *result);
void	ft_putchar_fd(char c, int fd, int *result);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif
