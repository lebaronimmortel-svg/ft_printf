/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:31:02 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/22 20:31:03 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(long long unsigned int nbr, char *base, int *cnt)
{
	char					c;
	unsigned int			lb;
	unsigned long long int	nb;

	nb = nbr;
	lb = ft_strlen(base);
	if (nb >= lb)
	{
		ft_putnbr_base(nb / lb, base, cnt);
		c = base[nb % lb];
		write(1, &c, 1);
		(*cnt)++;
	}
	else
	{
		c = base[nb % lb];
		write(1, &c, 1);
		(*cnt)++;
	}
}

void	aux_p(va_list args, int *cnt)
{
	long long unsigned	param;

	param = va_arg(args, long long unsigned);
	if (param == 0)
	{
		write(1, "(nil)", 5);
		(*cnt) += 5;
	}
	else
	{
		write(1, "0x", 2);
		(*cnt) += 2;
		ft_putnbr_base(param, "0123456789abcdef", cnt);
	}
}

void	aux_u(va_list args, int *cnt)
{
	unsigned int	param;

	param = va_arg(args, unsigned int);
	ft_putnbr_base(param, "0123456789", cnt);
}

void	aux_x(va_list args, int *cnt)
{
	unsigned int	param;

	param = va_arg(args, unsigned int);
	ft_putnbr_base(param, "0123456789abcdef", cnt);
}

void	aux_xx(va_list args, int *cnt)
{
	unsigned int	param;

	param = va_arg(args, unsigned int);
	ft_putnbr_base(param, "0123456789ABCDEF", cnt);
}
