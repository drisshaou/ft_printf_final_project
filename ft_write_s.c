/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:29:21 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/14 17:44:14 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_s(t_parse *parsed, char *tmp)
{
	char	chr;
	char	*str;
	size_t	len;
	size_t	ret;
	size_t	size;

	chr = (parsed->is_0_filled) ? '0' : ' ';
	str = ft_prec_s(parsed, tmp);
	len = ft_strlen(str);
	ret = 0;
	size = (parsed->is_width && parsed->width > len) ? parsed->width - len : 0;
	if (parsed->is_left)
	{
		ret += ft_putstr(str);
		while (size-- > 0)
			ret += ft_putchar(chr);
	}
	else
	{
		while (size-- > 0)
			ret += ft_putchar(chr);
		ret += ft_putstr(str);
	}
	free(str);
	return (ret);
}

char	*ft_prec_s(t_parse *parsed, char *tmp)
{
	char	*str;
	char	*new_str;

	new_str = (tmp == NULL) ? ft_strdup("(null)") : ft_strdup(tmp);
	if (parsed->is_prec && parsed->prec < ft_strlen(new_str))
		str = ft_substr(new_str, 0, parsed->prec);
	else
		str = ft_strdup(new_str);
	free(new_str);
	return (str);
}
