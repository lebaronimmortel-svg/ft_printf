/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:48:25 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/22 19:48:27 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(char const *s, ...);
void	aux_c(va_list args, int *cnt);
void	aux_s(va_list args, int *cnt);
void	aux_p(va_list args, int *cnt);
void	aux_d(va_list args, int *cnt);
void	aux_i(va_list args, int *cnt);
void	aux_u(va_list args, int *cnt);
void	aux_x(va_list args, int *cnt);
void	aux_xx(va_list args, int *cnt);

#endif
