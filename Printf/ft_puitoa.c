/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:14:00 by ksng              #+#    #+#             */
/*   Updated: 2025/05/16 18:23:13 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

// Helper function to apply precision to a numeric string
char	*ft_app_preci_num(char *str, int precision)
{
	int		len;
	char	*prec_str;
	int		i;

	if (precision == -1)
		return (str);
	len = ft_strlen(str);
	if (precision <= len)
		return (str);
	prec_str = malloc(precision + 1);
	if (!prec_str)
		return (NULL);
	i = 0;
	if (str[0] == '-')
	{
		prec_str[i++] = '-';
		len--;
	}
	while (i < precision - len)
		prec_str[i++] = '0';
	while (*str != '\0')
		prec_str[i++] = *str++;
	prec_str[i] = '\0';
	/* free(str); */
	return (prec_str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	size;

	size = 0;
	while (*s1 != '\0' && *s2 != '\0' && size < n)
	{
		if (*s1 != *s2)
		{
			break ;
		}
		s1++;
		s2++;
		size++;
	}
	if (size == n)
		return (0);
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

// Helper to apply +, and space flags.
char	*ft_app_plus_and_space(char *str, int neg, t_content *fwp)
{
	char	*result;

	if (neg || !(ft_strncmp(str, "(nil)", 5)))
		return (str);
	if (fwp->f_plus)
	{
		result = ft_strjoin("+", str);
		free(str);
		return (result);
	}
	else if (fwp->f_space)
	{
		result = ft_strjoin(" ", str);
		free(str);
		return (result);
	}
	return (str);
}

char *ft_prep_int_str(int nbr, int neg, t_content *fwp)
{
	char *str;
	char *prec_str;
	char *sign_space_str;

	str = ft_itoa(nbr);
	prec_str = ft_app_preci_num(str, fwp->p_precision);
	if (!prec_str)
        free(str);
	sign_space_str = ft_app_plus_and_space(prec_str, neg, fwp);
	if (!sign_space_str)
    {
        free(str);
        free(prec_str);
    }
	if (!prec_str || !sign_space_str)
		return (NULL);
	/* free(str);
	free(prec_str); */
	return (sign_space_str);
}

int ft_puitoa(int nbr, t_content *fwp)
{
	int neg;
	char *padded_str;
	int len;

	neg = 0;
	if (nbr < 0)
		neg = 1;
	padded_str = ft_prep_int_str(nbr, neg, fwp);
	if (!padded_str)
        return 0;
	len = ft_strlen(padded_str);
	if (fwp->f_zero_pad && fwp->p_precision == -1 && !fwp->f_minus)
		padded_str = ft_right_jus_spc_zero(padded_str, fwp->w_width, 0);
	else if (fwp->f_minus)
		padded_str = ft_left_jus(padded_str, fwp->w_width);
	else
		padded_str = ft_right_jus_spc_zero(padded_str, fwp->w_width, 1);
	len = ft_strlen(padded_str);
	write(1, padded_str, len);
    free(padded_str);
    return len;
}
