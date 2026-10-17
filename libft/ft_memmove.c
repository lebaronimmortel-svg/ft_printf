/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:16:36 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/14 20:16:38 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	if (!dest && !src)
		return (NULL);
	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (dest_cpy > src_cpy)
			dest_cpy[n - i - 1] = src_cpy[n - i - 1];
		else
			dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest);
}
