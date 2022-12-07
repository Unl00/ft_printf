/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmallard <pmallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:29:40 by pmallard          #+#    #+#             */
/*   Updated: 2022/12/07 19:56:08 by pmallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count += 1;
	while (nb > 0)
	{
		count++;
		nb /= 16;
	}
	return (count);
}

int	ft_printx(unsigned int nb, char *base)
{
	int	count;

	count = 0;
	if (nb < 16)
		count += ft_printchar(base[nb]);
	else if (nb >= 16)
	{
		count += ft_printx(nb / 16, base);
		count += ft_printx(nb % 16, base);
	}
	return (count);
}
