/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:14:00 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 13:35:49 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_prep_int_str(int nbr, int neg, t_content *fwp)
{
    char *str;
    char *prec_str;
    char *sign_space_str;

    str = ft_itoa(nbr);
    if (!str)
        return (NULL);
    
    prec_str = ft_app_preci_num(str, fwp->p_precision);
    if (!prec_str)
        return (NULL);
    
    sign_space_str = ft_app_plus_and_space(prec_str, neg, fwp);
    if (!sign_space_str)
        return (NULL);
    
    return (sign_space_str);
}


int	ft_puitoa(int nbr, t_content *fwp)
{
	int		neg;
	char	*padded_str;
	int		len;

	neg = 0;
	if (nbr < 0)
		neg = 1;
	padded_str = ft_prep_int_str(nbr, neg, fwp);
	if (!padded_str)
		return (0);
	len = ft_strlen(padded_str);
	if (fwp->w_width > len)
		padded_str = ft_handle_width(padded_str, fwp);
	if (!padded_str)
		return (0);
	len = ft_strlen(padded_str);
	write(1, padded_str, len);
	free(padded_str);
	return (len);
}
