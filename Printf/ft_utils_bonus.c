/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:12:09 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 18:30:32 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_left_jus(char *str, int width)
{
	int		len;
	char	*new_str;
	int		i;

	len = ft_strlen(str);
	new_str = malloc(width + 1);
	i = 0;
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	while (i < width)
	{
		new_str[i] = ' ';
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*ft_right_jus_spc_zero(char *str, int width, int space)
{
	int		len;
	char	*new_str;
	int		i;
	char	pad;
	int		j;

	len = ft_strlen(str);
	new_str = malloc(width + 1);
	i = -1;
	if (!new_str)
		return (NULL);
	if (space)
		pad = ' ';
	else
		pad = '0';
	while (++i < width - len)
		new_str[i] = pad;
	j = -1;
	while (++j < len)
		new_str[i + j] = str[j];
	new_str[i + j] = '\0';
	free(str);
	return (new_str);
}

char	*ft_right_justify(char *str, int width, int pad_zero)
{
	if (pad_zero == 1)
		return (ft_right_jus_spc_zero(str, width, 0));
	return (ft_right_jus_spc_zero(str, width, 1));
}

//used by x X i and u
char	*ft_create_padded_num(char *str, int precision, int pad, int len)
{
	char	*res;
	int		i;
	int		j;
	int		negadd;

	res = malloc(precision + 1 + pad);
	if (!res)
		return (NULL);
	i = 0;
	if (pad)
		res[i++] = str[0];
	negadd = 0;
	if (pad && str[0] == '-')
		negadd = 1;
	j = precision - len + pad + negadd;
	while (i < j)
		res[i++] = '0';
	j = pad;
	while (str[j])
		res[i++] = str[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_app_preci_num(char *str, int precision)
{
	int		len;
	int		pad;
	char	*ret;

	if (precision == 0 && str[0] == '0')
	{
		free(str);
		return (ft_strdup(""));
	}
	if (precision == -1)
		return (str);
	len = ft_strlen(str);
	pad = 0;
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
		pad = 1;
	if (precision <= (len - pad))
		return (str);
	ret = ft_create_padded_num(str, precision, pad, len);
	free(str);
	return (ret);
}
