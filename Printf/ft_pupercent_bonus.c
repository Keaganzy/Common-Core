/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pupercent_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:41:30 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 16:56:18 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_pupercent(t_content *fwp)
{
	char	*padded_str;
	int		len;

	padded_str = ft_strdup("%");
	if (!padded_str)
		return (0);
	len = ft_strlen(padded_str);
	if (fwp->w_width > len)
	{
		if (fwp->f_minus)
			padded_str = ft_left_jus(padded_str, fwp->w_width);
		else if (fwp->f_zero_pad)
			padded_str = ft_right_justify(padded_str, fwp->w_width, 1);
		else
			padded_str = ft_right_justify(padded_str, fwp->w_width, 0);
		len = ft_strlen(padded_str);
	}
	write(1, padded_str, len);
	free(padded_str);
	return (len);
}
