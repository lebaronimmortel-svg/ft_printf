/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:17:41 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/14 20:17:43 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dst;

	dst = s;
	while (n > 0)
	{
		*dst = (unsigned char) c;
		dst++;
		n--;
	}
	return (s);
}
