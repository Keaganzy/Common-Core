/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:43:01 by ksng              #+#    #+#             */
/*   Updated: 2025/05/17 17:43:38 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_initcontent(t_content *fwp)
{
	fwp->f_hash = 0;
	fwp->f_minus = 0;
	fwp->f_plus = 0;
	fwp->f_zero_pad = 0;
	fwp->f_space = 0;
	fwp->w_width = 0;
	fwp->p_precision = -1;
}

static int ft_printcontent(const char *s, va_list args, int *i)
{
	int count;
	t_content fwp;
	ft_initcontent(&fwp);
	count = 0;
	ft_findfwp(s, &fwp, i);
	if (s[*i] == 'c')
		return (ft_puchar(va_arg(args, int), &fwp));
	else if (s[*i] == 's')
		return (ft_pustring(va_arg(args, char *), &fwp));
	else if (s[*i] == 'p')
		return (ft_pupointer(va_arg(args, unsigned long), &fwp));
	else if (s[*i] == 'd' || s[*i] == 'i')
		return (ft_puitoa(va_arg(args, int), &fwp));
	else if (s[*i] == 'u')
		return (ft_puunitoa(va_arg(args, unsigned int), &fwp));
	else if (s[*i] == 'x' || s[*i] == 'X')
		return (ft_puhexnbr(va_arg(args, unsigned int), s[*i], &fwp)); 
	else if (s[*i] == '%')
		return (ft_pupercent(&fwp));
	else
		(*i)--;
	return (0);
}

int ft_printf(const char *s, ...)
{
	va_list args;
	int count;
	int i;
	
	count = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_printcontent(s, args, &i);
		}
		else
		{
			ft_putchar(s[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}


