/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:07:53 by ksng              #+#    #+#             */
/*   Updated: 2025/05/16 10:42:51 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int ft_puchar(int c, t_content *fwp)
{
	char s;
	char str[2];
	char *formatted;
	int len;

	s = (char)c;
	str[0] = s;
	str[1] = '\0';
	formatted = ft_strdup(str);
	if (fwp->w_width > 1)
	{
		if (fwp->f_minus)
			formatted = ft_left_jus(formatted, fwp->w_width);
		else
			formatted = ft_right_jus_spc_zero(formatted, fwp->w_width, 1);
	}
	len = ft_strlen(formatted);
	write(1, formatted, len);
	free(formatted);
	return (len);
}
