/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:13:37 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/14 20:13:42 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*my_memset(void *s, int c, size_t n)
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

void	ft_bzero(void *s, size_t n)
{
	my_memset(s, 0, n);
}
