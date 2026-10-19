/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:38:18 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/15 21:38:21 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const	*str1, char const	*str2)
{
	size_t				i;
	size_t				j;
	size_t				cnt;
	char				*tab;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	j = 0;
	cnt = ft_strlen(str1) + ft_strlen(str2);
	tab = (char *) malloc ((cnt + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (str1[i] != '\0')
	{
		tab[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		tab[i + j] = str2[j];
		j++;
	}
	tab[i + j] = '\0';
	return (tab);
}
