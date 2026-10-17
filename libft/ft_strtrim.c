/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 23:26:39 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/15 23:26:41 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

static void	begin(char const *s1, char const *set, size_t *tmp, size_t *i)
{
	while (s1[*i])
	{
		if (!is_sep(s1[*i], set))
		{
			*tmp = 1;
			break ;
		}
		(*i)++;
	}
}

static void	end(char const *s1, char const *set, size_t *tmp)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (!is_sep(s1[i], set))
		{
			*tmp = ft_strlen(s1) - 1 - i;
			break ;
		}
		i--;
	}
}

static char	*result_fill(char *str, size_t *tmp)
{
	char			*result;
	size_t			i;

	result = malloc(ft_strlen(str) - *tmp + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < ft_strlen(str) - *tmp)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	tmp;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	tmp = 0;
	str = NULL;
	begin(s1, set, &tmp, &i);
	str = (char *)&s1[i];
	if (*str == '\0' && tmp == 1)
		return ((char *)s1);
	if (*str == '\0' && tmp == 0)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return ((char *)str);
	}
	tmp = 0;
	end(s1, set, &tmp);
	str = result_fill(str, &tmp);
	return (str);
}
