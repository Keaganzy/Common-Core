/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:57:07 by ksng              #+#    #+#             */
/*   Updated: 2025/05/17 17:44:30 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_findp(char s, t_content *fwp)
{
	if (s == '.')
	{
		fwp->p_precision = 0;
		
		return (1);
	}
	if ('0' <= s && s <= '9')
	{
		fwp->p_precision *= 10;
		fwp->p_precision += s - '0';
		return (1);
	}
	return (0);
}

static int ft_findwidth(char s, t_content *fwp)
{
	if ('0' <= s && s <= '9')
	{
		fwp->w_width *= 10;
		fwp->w_width += s - '0';
		return (1);
	}
	return (0);
}

static int ft_findflag(char s, t_content *fwp)
{
	if (s == '-')
		fwp->f_minus = 1;
	else if (s == '0')
		fwp->f_zero_pad = 1;
	else if (s == ' ')
		fwp->f_space = 1;
	else if (s == '#')
		fwp->f_hash = 1;
	else if (s == '+')
		fwp->f_plus = 1;
	else
		return 0;
	return 1;
}

void ft_findfwp(const char *s, t_content *fwp, int *i)
{
	while (ft_findflag(s[*i], fwp))
		(*i)++;
	while (ft_findwidth(s[*i], fwp))
		(*i)++;
	while (ft_findp(s[*i], fwp))
		(*i)++;
}
