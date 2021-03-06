/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:33:09 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/14 20:30:47 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_parse_str(const char *str, va_list args)
{
	int		i;
	int		j;
	size_t	ret;

	ret = 0;
	while (*str)
	{
		i = (*str == '%') ? 1 : 0;
		while (str[i] && ((*str != '%' && str[i] != '%') ||
		(*str == '%' && !ft_is_type(str[i], TYPES))))
			i++;
		if (i > 0)
		{
			j = 0;
			if (*str == '%' && ft_is_type(str[i], TYPES) && i++)
				ret += ft_write_n_return_size(ft_substr(str, 1, i - 1), args);
			else
				while (j < i)
					ret += ft_putchar(str[j++]);
			str += i;
		}
	}
	return (ret);
}
