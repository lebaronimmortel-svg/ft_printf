/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:59:07 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/26 14:59:09 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	aux_percent(int *cnt)
{
	ft_putchar_fd('%', 1);
	(*cnt)++;
}

static char	get_next(char const *s, int i)
{
	while (s[i] == ' ')
		i++;
	return (s[i]);
}

static void	skip_spaces(char const *s, int *i, int *cnt)
{
	char	c;

	c = (get_next(s, *i));
	if (s[*i] == ' ' && (c == 'd' || c == 'i' || c == 'p'))
	{
		ft_putchar_fd(' ', 1);
		(*cnt)++;
		while (s[*i] == ' ')
			(*i)++;
	}
	else
	{
		while (s[*i] == ' ')
			(*i)++;
	}
}

static void	check_format(char const *s, int *i, int *cnt, va_list args)
{
	skip_spaces(s, i, cnt);
	if (s[*i] == 'c')
		aux_c(args, cnt);
	else if (s[*i] == 's')
		aux_s(args, cnt);
	else if (s[*i] == 'p')
		aux_p(args, cnt);
	else if (s[*i] == 'd')
		aux_d(args, cnt);
	else if (s[*i] == 'i')
		aux_i(args, cnt);
	else if (s[*i] == 'u')
		aux_u(args, cnt);
	else if (s[*i] == 'x')
		aux_x(args, cnt);
	else if (s[*i] == 'X')
		aux_xx(args, cnt);
	else if (s[*i] == '%')
		aux_percent(cnt);
	else
		return ;
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	va_start(args, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] != '%')
		{
			write(1, &s[i], 1);
			cnt++;
		}
		else
		{
			i++;
			check_format(s, &i, &cnt, args);
		}
		i++;
	}
	va_end(args);
	return (cnt);
}
