/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pustring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:11:07 by ksng              #+#    #+#             */
/*   Updated: 2025/05/16 22:39:22 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_app_preci_str(char *str, int precision)
{
    int len;
    int i;
    char *new_str;

	if (!str)
        return NULL;

	len = ft_strlen(str);
	i = 0;
    if (precision == -1 || precision >= len)
        return str;
    new_str = malloc(precision + 1);
    if (!new_str)
        return NULL;
    while (i < precision)
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    free(str);
    return new_str;
}

int ft_pustring(char *str, t_content *fwp)
{
	char *trunc;
	char *formatted;
	int len;
	
	if (!str)
    {
        if (str == 0 || fwp->p_precision > 5)
            trunc = ft_strdup("(null)");
        else
            trunc = ft_strdup("");
    }
    else
    	trunc = ft_app_preci_str(ft_strdup(str), fwp->p_precision);

    if (!trunc)
	{
        return (0);
	}

	formatted = trunc;
	if (fwp->w_width > (int)ft_strlen(formatted))
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
