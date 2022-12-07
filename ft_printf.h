/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmallard <pmallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:03:41 by pmallard          #+#    #+#             */
/*   Updated: 2022/12/07 13:43:19 by pmallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int		ft_printf(const char *form, ...);
int		ft_form(va_list args, const char form);
int		ft_printnbr(int n);
int		ft_printstr(char *str);
int		ft_printchar(char c);
int		ft_nbrlen(int n);
int		ft_printptr(unsigned long ptr);
int     ft_ptrlen(unsigned long ptr);
int		ft_form(va_list args, const char form);
int     ft_printnbr_u(unsigned int nb);
int     ft_hexlen(unsigned long long nb);
int     ft_printx(unsigned long long nb, char *base);
void	ft_putptr(unsigned long ptr);
char	*ft_itoa(int nb);

#endif