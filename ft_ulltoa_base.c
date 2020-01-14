/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 04:41:15 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/08 00:53:21 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ulltoa_base(unsigned long long nbr, char *base)
{
	char	*str;
	int		nbr_final[20];
	int		len;
	int		i;
	int		base_len;

	len = (nbr == 0) ? 1 : 0;
	nbr_final[0] = 0;
	base_len = ft_strlen(base);
	while (nbr)
	{
		nbr_final[len++] = nbr % base_len;
		nbr /= base_len;
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (--len >= 0)
		str[i++] = base[nbr_final[len]];
	str[i] = '\0';
	return (str);
}
