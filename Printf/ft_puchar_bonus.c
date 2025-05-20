/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puchar_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:07:53 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 16:56:04 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_puchar(int c, t_content *fwp)
{
	char	padding;
	int		i;

	i = 1;
	padding = ' ';
	if (fwp->w_width > 1)
	{
		if (fwp->f_minus)
		{
			write(1, &c, 1);
			while (i++ < fwp->w_width)
				write(1, &padding, 1);
		}
		else
		{
			while (i++ < fwp->w_width)
				write(1, &padding, 1);
			write(1, &c, 1);
		}
		return (fwp->w_width);
	}
	else
		write(1, &c, 1);
	return (1);
}
