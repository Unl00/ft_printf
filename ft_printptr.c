/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmallard <pmallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 02:02:20 by pmallard          #+#    #+#             */
/*   Updated: 2022/12/05 20:11:59 by pmallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		count += write(1, "0", 1);
	else
	{
		count += ft_ptrlen(ptr);
		ft_putptr(ptr);
	}
	return (count);
}

int	ft_ptrlen(unsigned long ptr)
{
	int	count;

	count = 0;
	while (ptr)
	{
		ptr /= 16;
		count++;
	}
	return (count);
}

void	ft_putptr(unsigned long ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_printchar(ptr + '0');
		else
			ft_printchar(ptr - 10 + 'a');
	}
}