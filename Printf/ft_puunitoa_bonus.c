/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puunitoa_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:15:25 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 16:56:34 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_uintlen(unsigned int n)
{
	unsigned int	num;
	int				len;

	num = n;
	len = 0;
	if (n == 0)
		len = 1;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	unsigned int	num;
	int				len;
	char			*str;

	len = ft_uintlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	num = n;
	if (n == 0)
		str[0] = '0';
	while (len > 0)
	{
		str[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (str);
}

static char	*ft_prep_uint_str(unsigned int n, t_content *fwp)
{
	char	*str;
	char	*prec_str;

	str = ft_uitoa(n);
	if (!str)
		return (NULL);
	prec_str = ft_app_preci_num(ft_strdup(str), fwp->p_precision);
	if (!prec_str)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (prec_str);
}

int	ft_puunitoa(unsigned int n, t_content *fwp)
{
	char	*padded_str;
	int		len;

	padded_str = ft_prep_uint_str(n, fwp);
	if (!padded_str)
		return (0);
	len = ft_strlen(padded_str);
	if (fwp->w_width > len)
	{
		if (fwp->f_minus)
			padded_str = ft_left_jus(padded_str, fwp->w_width);
		else if (fwp->f_zero_pad && fwp->p_precision == -1)
			padded_str = ft_right_justify(padded_str, fwp->w_width, 1);
		else
			padded_str = ft_right_justify(padded_str, fwp->w_width, 0);
		len = ft_strlen(padded_str);
	}
	write(1, padded_str, len);
	free(padded_str);
	return (len);
}
