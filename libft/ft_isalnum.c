/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:14:13 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/14 20:14:16 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_isalpha(int value)
{
	if ((value > 64 && value < 91) || (value > 96 && value < 123))
		return (1);
	else
		return (0);
}

static int	my_isdigit(int value)
{
	if (value > 47 && value < 58)
		return (1);
	else
		return (0);
}

int	ft_isalnum(int value)
{
	if (my_isalpha(value) == 1 || my_isdigit(value) == 1)
		return (1);
	else
		return (0);
}
