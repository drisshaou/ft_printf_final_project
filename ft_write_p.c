/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 05:03:23 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/14 19:12:56 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_p(t_parse *parsed, void *addr)
{
	intptr_t	nbr;
	char		*tmp;
	size_t		len;
	size_t		ret;

	nbr = (addr == NULL) ? 0 : (intptr_t)addr;
	tmp = ft_ulltoa_base(nbr, "0123456789abcdef");
	len = ft_strlen(tmp);
	ret = 0;
	if ((!parsed->is_width && !parsed->is_prec) ||
	(!(parsed->prec >= len || parsed->width >= len + 2) && nbr != 0))
		ret += ft_fill_0_p(tmp, 0);
	else if (parsed->is_width && !parsed->is_prec)
	{
		if (parsed->width < len + 2)
			parsed->width = len + 2;
		if (parsed->is_0_filled)
			ret += ft_fill_0_p(tmp, parsed->width - len - 2);
		else
			ret += ft_padding_p(parsed, tmp, 0);
	}
	else
		ret += ft_width_n_prec_p(parsed, nbr, tmp);
	free(tmp);
	return (ret);
}

size_t	ft_width_n_prec_p(t_parse *parsed, intptr_t nbr, char *tmp)
{
	size_t	len;
	size_t	ret;

	len = ft_strlen(tmp);
	ret = 0;
	if (parsed->prec >= len || parsed->width >= len + 2)
	{
		if (parsed->prec == 0 && nbr == 0)
			ret += ft_padding_p(parsed, "", 0);
		else
		{
			parsed->prec = (parsed->prec < len) ? len : parsed->prec;
			if (parsed->width < parsed->prec + 2)
				parsed->width = parsed->prec + 2;
			ret += ft_padding_p(parsed, tmp, parsed->prec - len);
		}
	}
	else
		ret += ft_fill_0_p("", 0);
	return (ret);
}

size_t	ft_padding_p(t_parse *parsed, char *tmp, size_t size)
{
	size_t	len;
	size_t	ret;

	len = ft_strlen(tmp);
	ret = 0;
	if (parsed->is_left)
	{
		ret += ft_fill_0_p(tmp, size);
		while (parsed->width-- > (len + size + 2))
			ret += ft_putchar(' ');
	}
	else
	{
		while (parsed->width-- > (len + size + 2))
			ret += ft_putchar(' ');
		ret += ft_fill_0_p(tmp, size);
	}
	return (ret);
}

size_t	ft_fill_0_p(char *tmp, size_t size)
{
	size_t	ret;

	ret = ft_putstr("0x");
	while (size > 0 && size-- > 0)
		ret += ft_putchar('0');
	ret += ft_putstr(tmp);
	return (ret);
}
