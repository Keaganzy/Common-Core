/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:08:17 by ksng              #+#    #+#             */
/*   Updated: 2025/05/09 17:44:17 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    if (!s)
    {
        return (NULL);
    }
    char *ptr;
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

/* int	main()
{
	printf("### Function: ft_substr ###");
	char *s = "hello world";
	
	printf("\nft: %s", ft_substr(s, 0, 0));
	printf("\nft: %s", ft_substr(s, 4, 8));
	printf("\nft: %s", ft_substr(s, 3, -5));
	printf("\nft: %s\n", ft_substr(s, -5, 1));
} */