/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmallard <pmallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:03:41 by pmallard          #+#    #+#             */
/*   Updated: 2022/11/13 20:08:13 by pmallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_form(va_list args, const char form);
int	ft_printpercentage();
int	ft_printnbr(int n);
int	ft_printstr(char *str);
int	ft_printchar(int c);
int	ft_nbrlen(long nb);
char	*ft_itoa(int nb);

#endif