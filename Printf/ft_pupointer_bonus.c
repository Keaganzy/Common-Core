/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pupointer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:12:10 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 18:39:06 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_putnil(void)
{
	char	*str;

	str = malloc(6);
	if (!str)
		return (NULL);
	ft_strlcpy(str, "(nil)", 6);
	return (str);
}

static char	*ft_initialize_hex_string(int total_len, int padding_len)
{
	char	*hex_str;

	hex_str = malloc(total_len + 1);
	if (!hex_str)
		return (NULL);
	ft_memset(hex_str, 0, total_len + 1);
	hex_str[0] = '0';
	hex_str[1] = 'x';
	ft_memset(hex_str + 2, '0', padding_len);
	return (hex_str);
}

static char	*ft_format_pointer_string(unsigned long addr, int precision)
{
	char	*hex_str;
	int		hex_len;
	int		total_len;
	int		padding_len;

	if (addr == 0)
	{
		hex_str = ft_putnil();
		return (hex_str);
	}
	hex_len = ft_counthex(addr);
	padding_len = 0;
	if (precision > hex_len)
		padding_len = precision - hex_len;
	total_len = 2;
	if (precision > hex_len)
		total_len += precision;
	else
		total_len += hex_len;
	hex_str = ft_initialize_hex_string(total_len, padding_len);
	if (!hex_str)
		return (NULL);
	ft_puhexanum(hex_str + 2 + padding_len, addr, hex_len);
	ft_reversestr(hex_str + 2 + padding_len);
	return (hex_str);
}

static char	*ft_handle_width_padding(char *str, t_content *fwp, int *len)
{
	char	*padded;

	if (fwp->f_minus)
		padded = ft_left_jus(str, fwp->w_width);
	else if (fwp->f_zero_pad)
		padded = ft_right_justify(str, fwp->w_width, 0);
	else
		padded = ft_right_justify(str, fwp->w_width, 0);
	if (!padded)
	{
		free(str);
		return (NULL);
	}
	*len = ft_strlen(padded);
	return (padded);
}

int	ft_pupointer(unsigned long addr, t_content *fwp)
{
	char	*formatted;
	char	*ptr_str;
	int		len;
	int		precision;

	precision = 0;
	if (fwp->p_precision != -1)
		precision = fwp->p_precision;
	ptr_str = ft_format_pointer_string(addr, precision);
	if (!ptr_str)
		return (0);
	formatted = ft_app_plus_and_space(ptr_str, 0, fwp);
	if (!formatted)
	{
		free(ptr_str);
		return (0);
	}
	len = ft_strlen(formatted);
	if (fwp->w_width > len)
		formatted = ft_handle_width_padding(formatted, fwp, &len);
	write(1, formatted, len);
	free(formatted);
	return (len);
}
