/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmallard <pmallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:13:24 by pmallard          #+#    #+#             */
/*   Updated: 2022/11/13 20:06:59 by pmallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int	count;
	int	i;

	i = 0;
	count = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%')
		{
			count += ft_form(args, form[i + 1]);
			i++;
		}
		else
			count += ft_putchar(form[i]);
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
	// else if (form == 'p')
	// 	length += 
	// else if (form == 'd')
	// 	length += 
	else if (form == 'i')
		length += ft_printnbr(va_arg(args, int));
	// else if (form == 'u')
	// 	length +=
	// else if (form == 'u')
	// 	length += 
	// else if (form == 'x')
	// 	length += 
	// else if (form == 'X')
		// length += 
	else if (form == '%')
		length += ft_printpercentage();
	return (length);
}

int	ft_printpercentage()
{
	write(1, '%', 1);
	return (1);
}

int	ft_printnbr(int n)
{
	int	count;
	char	*num;

	count = 0;
	num = ft_itoa(n);
	count += ft_printStr(num);
	free(num);
	return (count);
}

// int	ft_printPtr(void *ptr)
// {
	
// }

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		write(1, 'null', 4);
		return (4);
	}
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_printchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_nbrlen(long nb)
{
	int	i;

	i = 0 + (nb == 0);
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int		len;
	long		n;
	char	*res;

	n = nb;
	len = ft_nbrlen(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	res[len--] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (res);
}