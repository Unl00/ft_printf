/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmallard <pmallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:11:33 by pmallard          #+#    #+#             */
/*   Updated: 2022/12/07 13:24:34 by pmallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr_u(unsigned int nb)
{
	int	count;

	count = ft_nbrlen(nb);
	if (nb > 0)
	{
		ft_printnbr(nb / 10);
		ft_printnbr(nb % 10);
	}
	else
		ft_printchar(nb + '0');
	return (count);
}