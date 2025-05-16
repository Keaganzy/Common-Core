/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puhexnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:28:05 by ksng              #+#    #+#             */
/*   Updated: 2025/05/16 21:12:13 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa_base(unsigned int n, int uppercase)
{
	unsigned int	num;
	int		len;
	char	*str;
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	num = n;
	len = 0;
	if (n == 0)
		len = 1;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	num = n;
	if (n == 0)
		str[0] = '0';
	while (len > 0)
	{
		str[len - 1] = base[num % 16];
		num /= 16;
		len--;
	}
	return (str);
}

// Helper to apply the '#' flag
static char	*apply_hash(char *str, int uppercase, t_content *fwp)
{
	char	*prefix;
	char	*result;

	if (fwp->f_hash && str[0] != '0')
	{
		if (uppercase)
			prefix = "0X";
		else
			prefix = "0x";
		result = ft_strjoin(prefix, str);
		free(str);
		return (result);
	}
	return (str);
}

// Function to prepare the hexadecimal string
static char	*ft_prep_hex_str(unsigned int n, int uppercase, t_content *fwp)
{
	char	*str;
	char	*prec_str;
	char	*hash_str;

	str = ft_uitoa_base(n, uppercase);
	if (!str)
		return (NULL);
	prec_str = ft_app_preci_num(ft_strdup(str), fwp->p_precision);
	if (!prec_str)
	{
		free(str);
		return (NULL);
	}
	hash_str = apply_hash(ft_strdup(prec_str), uppercase, fwp);
	if (!hash_str)
	{
		free(str);
		free(prec_str);
		return (NULL);
	}
	free(str);
	free(prec_str);
	return (hash_str);
}

// Function to output hexadecimal string with formatting options
static void	ft_puthex_body(char *padded_str, int len)
{
	write(1, padded_str, len);
	free(padded_str);
}

int	ft_puthex(unsigned int n, int uppercase, t_content *fwp)
{
	char	*padded_str;
	int		len;

	padded_str = ft_prep_hex_str(n, uppercase, fwp);
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
	ft_puthex_body(padded_str, len);
	return (len);
}

// Function to handle %x and %X
int	ft_puhexnbr(unsigned int n, char c, t_content *fwp)
{
	int		uppercase;

	if (c == 'X')
		uppercase = 1;
	else
		uppercase = 0;
	return (ft_puthex(n, uppercase, fwp));
}
