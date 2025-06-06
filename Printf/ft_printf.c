/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:43:01 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 17:36:55 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printcontent(const char *s, va_list args, int *i)
{
	int			count;

	count = 0;
	if (s[*i] == 'c')
		return (ft_puchar(va_arg(args, int)));
	else if (s[*i] == 's')
		return (ft_pustring(va_arg(args, char *)));
	else if (s[*i] == 'p')
		return (ft_pupointer(va_arg(args, unsigned long)));
	else if (s[*i] == 'd' || s[*i] == 'i')
		return (ft_puitoa(va_arg(args, int)));
	else if (s[*i] == 'u')
		return (ft_puunitoa(va_arg(args, unsigned int)));
	else if (s[*i] == 'x' || s[*i] == 'X')
		return (ft_puhexnbr(va_arg(args, unsigned int), s[*i]));
	else if (s[*i] == '%')
		return (ft_puchar('%'));
	else
		(*i)--;
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;

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
			ft_puchar(s[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
