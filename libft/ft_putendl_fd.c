/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:03:38 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/16 21:03:39 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	char	c;

	if (!s)
		return ;
	i = 0;
	c = '\n';
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, &c, 1);
}
