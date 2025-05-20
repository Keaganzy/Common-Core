/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_i_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:35:05 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 13:35:45 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prepend_prefix(char *str, char *prefix)
{
	char	*result;
	int		prefix_len;
	int		str_len;

	prefix_len = ft_strlen(prefix);
	str_len = ft_strlen(str);
	result = malloc(prefix_len + str_len + 1);
	if (!result)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(result, prefix, prefix_len + 1);
	ft_strlcpy(result + prefix_len, str, str_len + 1);
	free(str);
	return (result);
}

char	*ft_handle_hex_prefix(char *str, t_content *fwp)
{
	char	*num_part;
	char	prefix[3];
	char	*padded;

	prefix[0] = '0';
	prefix[1] = str[1];
	prefix[2] = '\0';
	num_part = ft_strdup(str + 2);
	free(str);
	if (!num_part)
		return (NULL);
	padded = ft_right_jus_spc_zero(num_part, fwp->w_width - 2, 0);
	if (!padded)
		return (NULL);
	return (ft_prepend_prefix(padded, prefix));
}

char	*ft_add_sign_to_padded(char *str, char sign, int width)
{
	char	*padded;
	char	*result;

	padded = ft_right_jus_spc_zero(str, width, 0);
	if (!padded)
		return (NULL);
	result = malloc(ft_strlen(padded) + 2);
	if (!result)
	{
		free(padded);
		return (NULL);
	}
	result[0] = sign;
	ft_strlcpy(result + 1, padded, ft_strlen(padded) + 1);
	free(padded);
	return (result);
}

char	*ft_handle_sign_padding(char *str, char sign, int width)
{
	char	*temp;
	char	*result;

	temp = ft_right_jus_spc_zero(str, width, 0);
	if (!temp)
		return (NULL);
	result = malloc(ft_strlen(temp) + 2);
	if (!result)
	{
		free(temp);
		return (NULL);
	}
	result[0] = sign;
	ft_strlcpy(result + 1, temp, ft_strlen(temp) + 1);
	free(temp);
	return (result);
}

char	*ft_handle_width(char *str, t_content *fwp)
{
	char	*temp;
	char	sign;
	int		has_prefix;

	has_prefix = (str[0] == '-' || str[0] == '+' || str[0] == ' ' || 
				 (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')));
	if (fwp->f_zero_pad && fwp->p_precision == -1 && !fwp->f_minus && has_prefix)
	{
		if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
			return (ft_handle_hex_prefix(str, fwp));
		sign = str[0];
		temp = ft_strdup(str + 1);
		free(str);
		if (!temp)
			return (NULL);
		return (ft_add_sign_to_padded(temp, sign, fwp->w_width - 1));
	}
	else if (fwp->f_zero_pad && fwp->p_precision == -1 && !fwp->f_minus)
		return (ft_right_jus_spc_zero(str, fwp->w_width, 0));
	else if (fwp->f_minus)
		return (ft_left_jus(str, fwp->w_width));
	return (ft_right_jus_spc_zero(str, fwp->w_width, 1));
}