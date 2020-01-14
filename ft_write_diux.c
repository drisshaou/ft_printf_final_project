/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_diux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:29:06 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/14 19:12:54 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_diux(t_parse *parsed, long nbr)
{
	char	*tmp;
	size_t	is_neg;
	size_t	len;
	size_t	ret;

	tmp = ft_get_nbr_base(parsed->type, nbr);
	is_neg = (nbr < 0 && parsed->type != 'x' && parsed->type != 'X') ? 1 : 0;
	len = ft_strlen(tmp);
	ret = 0;
	if ((!parsed->is_width && !parsed->is_prec) ||
	(!(parsed->prec >= len || parsed->width >= len + is_neg) && nbr != 0))
		ret += ft_fill_0_diux(is_neg, tmp, 0);
	else if (parsed->is_width && !parsed->is_prec)
	{
		if (parsed->width < len + is_neg)
			parsed->width = len + is_neg;
		if (parsed->is_0_filled)
			ret += ft_fill_0_diux(is_neg, tmp, parsed->width - len - is_neg);
		else
			ret += ft_padding_diux(parsed, is_neg, tmp, 0);
	}
	else
		ret += ft_width_n_prec_diux(parsed, nbr, tmp);
	free(tmp);
	return (ret);
}

size_t	ft_width_n_prec_diux(t_parse *parsed, long nbr, char *tmp)
{
	size_t	is_neg;
	size_t	len;
	size_t	ret;

	is_neg = (nbr < 0 && parsed->type != 'x' && parsed->type != 'X') ? 1 : 0;
	len = ft_strlen(tmp);
	ret = 0;
	if (parsed->prec >= len || parsed->width >= len + is_neg)
	{
		if (parsed->prec == 0 && nbr == 0)
			ret += ft_padding_diux(parsed, is_neg, "", 0);
		else
		{
			parsed->prec = (parsed->prec < len) ? len : parsed->prec;
			if (parsed->width < parsed->prec + is_neg)
				parsed->width = parsed->prec + is_neg;
			ret += ft_padding_diux(parsed, is_neg, tmp, parsed->prec - len);
		}
	}
	return (ret);
}

size_t	ft_padding_diux(t_parse *parsed, size_t is_neg, char *tmp, size_t size)
{
	size_t	len;
	size_t	ret;

	len = ft_strlen(tmp);
	ret = 0;
	if (parsed->is_left)
	{
		ret += ft_fill_0_diux(is_neg, tmp, size);
		while (parsed->width-- > (len + size + is_neg))
			ret += ft_putchar(' ');
	}
	else
	{
		while (parsed->width-- > (len + size + is_neg))
			ret += ft_putchar(' ');
		ret += ft_fill_0_diux(is_neg, tmp, size);
	}
	return (ret);
}

char	*ft_get_nbr_base(char type, long nbr)
{
	char	*base;
	long	val;

	if (type == 'X' || type == 'x')
		base = (type == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	else
		base = "0123456789";
	val = (type != 'X' && type != 'x' && nbr < 0) ? -nbr : nbr;
	return (ft_ulltoa_base(val, base));
}

size_t	ft_fill_0_diux(size_t is_neg, char *tmp, size_t size)
{
	size_t	ret;

	ret = (is_neg) ? ft_putchar('-') : 0;
	while (size > 0 && size-- > 0)
		ret += ft_putchar('0');
	ret += ft_putstr(tmp);
	return (ret);
}
