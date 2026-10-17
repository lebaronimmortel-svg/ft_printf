/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:14:03 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/14 20:14:06 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		memory = malloc(0);
		if (!memory)
			return (NULL);
		return (memory);
	}
	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	memory = malloc(nmemb * size);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)memory)[i] = 0;
		i++;
	}
	return (memory);
}
