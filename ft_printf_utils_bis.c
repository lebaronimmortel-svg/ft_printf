/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:31:16 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/22 20:31:18 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	measure(long long n)
{
	int	cpt;

	cpt = 0;
	if (n < 0)
	{
		n = -n;
		cpt += 1;
	}
	while (n > 9)
	{
		n = n / 10;
		cpt += 1;
	}
	return (cpt + 1);
}

void	aux_c(va_list args, int *cnt)
{
	ft_putchar_fd(va_arg(args, int), 1);
	(*cnt)++;
}

void	aux_s(va_list args, int *cnt)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*cnt) += 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		(*cnt) += ft_strlen(str);
	}
}

void	aux_d(va_list args, int *cnt)
{
	int	param;

	param = va_arg(args, int);
	ft_putnbr_fd((int)param, 1);
	(*cnt) += measure(param);
}

void	aux_i(va_list args, int *cnt)
{
	int	param;

	param = va_arg(args, int);
	ft_putnbr_fd((int)param, 1);
	(*cnt) += measure(param);
}
