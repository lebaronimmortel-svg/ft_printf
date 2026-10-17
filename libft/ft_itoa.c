/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:23:21 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/16 11:23:23 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	measure(int n)
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

static int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

static void	int_min_fill(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
}

static void	fill(char *str, int n, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i = 1;
	}
	while (i < size)
	{
		str[i] = n / ft_recursive_power(10, size - i - 1) + 48;
		n = n % ft_recursive_power(10, size - i - 1);
		i++;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	size;

	if (n == -2147483648)
	{
		str = malloc(12 * sizeof(char));
		if (!str)
			return (NULL);
		int_min_fill(str);
		return (str);
	}
	size = measure(n);
	str = malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	fill(str, n, size);
	return (str);
}
