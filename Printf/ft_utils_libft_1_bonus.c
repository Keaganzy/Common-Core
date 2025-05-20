/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_libft_1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:05:52 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 16:57:04 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (!s1 || !s2)
	{
		return (NULL);
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

char	*ft_strdup(const char *s)
{
	char	*str;

	if (!s)
	{
		return (NULL);
	}
	str = malloc(ft_strlen(s) + 1);
	if (str)
	{
		ft_strlcpy(str, s, ft_strlen(s) + 1);
		return (str);
	}
	else
	{
		return (NULL);
	}
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

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
