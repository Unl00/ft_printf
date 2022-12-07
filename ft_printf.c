/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmallard <pmallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:46:54 by pmallard          #+#    #+#             */
/*   Updated: 2022/12/07 20:00:05 by pmallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *form, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%')
		{
			i++;
			count += ft_form(args, form[i]);
		}
		else
			count += ft_printchar(form[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	ft_form(va_list args, const char form)
{
	int	length;

	length = 0;
	if (form == 'c')
		length += ft_printchar(va_arg(args, int));
	else if (form == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (form == 'p')
		length += ft_printptr(va_arg(args, unsigned long int));
	else if (form == 'i' || form == 'd')
		length += ft_printnbr(va_arg(args, int));
	else if (form == 'u')
		length += ft_printnbr_u(va_arg(args, unsigned int));
	else if (form == 'x')
		length += ft_printx(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (form == 'X')
		length += ft_printx(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (form == '%')
		length += ft_printchar('%');
	return (length);
}
