/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:43:44 by idelemen          #+#    #+#             */
/*   Updated: 2024/01/03 18:09:55 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_format(va_list *arg, char format);
int	ft_putstr(char *s);
int	ft_point(unsigned long nb, int i);
int	ft_int(int nb);
int	ft_unsigned(unsigned int nb);
int	ft_hex(unsigned int nb, char format);

#endif
