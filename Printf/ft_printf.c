/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:43:01 by ksng              #+#    #+#             */
/*   Updated: 2025/05/13 22:28:26 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (slen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
	{
		return (NULL);
	}
	if (len > ft_strlen(s) - start)
	{
		len = ft_strlen(s) - start;
	}
	if (start > ft_strlen(s))
	{
		len = 0;
		start = ft_strlen(s);
	}
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr)
	{
		ft_strlcpy(ptr, s + start, len + 1);
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

int ft_pustring(char *str, t_content *fwp)
{
	if (fwp->p_precision < ft_strlen(str))
	{
		str = ft_substr(str, 0, fwp->p_precision);
	}
	if (fwp->f_minus && (fwp->w_width > fwp->p_precision))
	{
		
	}
	if (fwp->w_width >)
}


int ft_puchar(int c, t_content *fwp)
{
	int i;

	i = 0;

	if (fwp->f_minus && fwp->w_width)
	{
		i = fwp->w_width;
		write(1, &c, 1);
		while (i > 0)
		{
			write(1, ' ', 1);
			i++;
		}
		return (fwp->w_width);
	}
	write(1, &c, 1);
	return (1);
}

int ft_findp(const char *s, t_content *fwp)
{
	if (*s == '.')
	{
		return (1);
	}
	if ('0' <= *s && *s <= '9')
	{
		fwp->p_precision *= 10;
		fwp->p_precision += *s - '0';
		return (1);
	}
	return (0);
}

int ft_findwidth(const char *s, t_content *fwp)
{
	if ('0' <= *s && *s <= '9')
	{
		fwp->w_width *= 10;
		fwp->w_width += *s - '0';
		return (1);
	}
	return (0);
}

int ft_findflag(const char *s, t_content *fwp)
{
	if (*s == '-')
		fwp->f_minus = 1;
	else if (*s == '0')
		fwp->f_zero_pad = 1;
	else if (*s == ' ')
		fwp->f_space = 1;
	else if (*s == '#')
		fwp->f_hash = 1;
	else if (*s == '+')
		fwp->f_plus = 1;
	else
		return 0;
	return 1;
}

void ft_findfwp(const char *s, t_content *fwp, int *i)
{
	while (ft_findflag(s[*i], &fwp))
		(*i)++;
	while (ft_findwidth(s[*i], &fwp))
		(*i)++;
	while (ft_findp(s[*i], &fwp))
		(*i)++;
}

int ft_printcontent(const char *s, va_list args, int *i)
{
	int count;
	t_content fwp;

	count = 0;
	ft_findfwp(s[*i], &fwp, i);
	if (s[*i] == 'c')
		return (ft_puchar(va_arg(args, int), &fwp));
	else if (s[*i] == 's')
		return (ft_pustring(va_arg(args, char *), &fwp));
	else if (s[*i] == 'p')
		return (ft_pupointer(va_arg(args, unsigned long), &fwp));
	else if (s[*i] == 'd' || s[*i] == 'i')
		return (ft_itoa(va_arg(args, int), &fwp));
	else if (s[*i] == 'u')
		return (ft_unitoa(va_arg(args, unsigned int), &fwp));
	else if (s[*i] == 'x' || s[*i] == 'X')
		return (ft_puhexnbr(va_arg(args, unsigned int), s[*i], &fwp)); 
	else if (s[*i] == '%')
		return (ft_puchar('%', &fwp));
	else
		(*i)--;
	return (0);
}

int ft_printf(const char *s, ...)
{
	va_list args;
	char *temp;
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
			count += ft_printcontent(s[i], args, &i);
		}
		else
		{
			ft_puchar(s[i]);
			count++;
		}
		i++;
	}
	return (count);
}
