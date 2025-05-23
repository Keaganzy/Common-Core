/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:11:27 by ksng              #+#    #+#             */
/*   Updated: 2025/05/23 20:07:54 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_en_strdup(const char *s, size_t start, size_t end)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
	{
		return (NULL);
	}
	str = malloc(end - start + 1);
	if (!str)
		return (NULL);
	while (start + i < end)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (!s2)
	{
		return (NULL);
	}
	if (!s1)
	{
		return (ft_en_strdup(s2, 0, ft_strlen(s2)));
	}
	ptr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (ptr)
	{
		ft_strlcpy(ptr, s1, (ft_strlen(s1) + 1));
		ft_strlcat(ptr, s2, ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	}
	else
	{
		free(ptr);
	}
	return (ptr);
}
