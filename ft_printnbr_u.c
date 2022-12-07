/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmallard <pmallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:11:33 by pmallard          #+#    #+#             */
/*   Updated: 2022/12/07 20:15:58 by pmallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrulen(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count++;
	while (nb > 0)
	{
		nb = nb / 10;
		count ++;
	}
	return (count);
}

int	ft_printnbr_u(unsigned int nb)
{
	int	count;

	count = ft_nbrulen(nb);
	if (nb > 9)
	{
		ft_printnbr(nb / 10);
		ft_printnbr(nb % 10);
	}
	else if (nb > 0)
		ft_printchar(nb + '0');
	else if (nb == 0)
		ft_printchar('0');
	return (count);
}
