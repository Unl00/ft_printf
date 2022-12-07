/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmallard <pmallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:45:16 by pmallard          #+#    #+#             */
/*   Updated: 2022/12/07 20:11:13 by pmallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_printnbr(int nb)
{
	int	count;

	count = ft_nbrlen(nb);
	if (nb == -2147483648)
	{
		return (write (1, "-2147483648", 11));
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb > 9)
	{
		ft_printnbr(nb / 10);
		ft_printnbr(nb % 10);
	}
	else
		ft_printchar(nb + '0');
	return (count);
}
