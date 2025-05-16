/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:12:09 by ksng              #+#    #+#             */
/*   Updated: 2025/05/16 20:08:39 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
    return write(1, &c, 1);
}

char *ft_left_jus(char *str, int width)
{
    int len = ft_strlen(str);
    char *new_str = malloc(width + 1);
    int i = 0;

    if (!new_str)
        return NULL;

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
    return new_str;
}

char *ft_right_jus_spc_zero(char *str, int width, int space)
{
    int len;
    char *new_str;
    int i;
    char pad;

	len = ft_strlen(str);
	new_str = malloc(width + 1);
	i = -1;
    if (!new_str)
        return NULL;
    if (space)
        pad = ' ';
    else
        pad = '0';
    while (i++ < width - 1 - len)
        new_str[i] = pad;
    int j = 0;
    while (j < len)
    {
        new_str[i + j] = str[j];
        j++;
    }
    new_str[i + j] = '\0';
    free(str);
    return new_str;
}

char *ft_right_justify(char *str, int width, int pad_zero)
{
    if (pad_zero == 1)
        return ft_right_jus_spc_zero(str, width, 0);
    return ft_right_jus_spc_zero(str, width, 1);
}

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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	i = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (src[i] != '\0' && i < size - dlen - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
