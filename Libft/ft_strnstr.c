/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:07:57 by ksng              #+#    #+#             */
/*   Updated: 2025/05/09 14:00:49 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    int llen;
    int i;

    llen = ft_strlen(little);
    if (llen == 0)
        return ((char *)big);
    while (*big != '\0' && len > 0)
    {
        i = 0;
        while(big[i] == little[i])
        {
            if (little[i + 1] == '\0')
            {
                if(len < llen)
                    return (NULL);
                return ((char *)big);
            }
            i++;
        }
        big++;
        len--;
    }
    return (NULL);
}
/* #include <bsd/string.h>
#include <stdio.h>

int main ()
{
	char haystack[99] ="123456";
	char needle[99] = "234";

	printf("ft: %s\n", ft_strnstr(haystack, needle, 4));	
	printf("og: %s\n", strnstr(haystack, needle, 4));
	
	printf("\nnew: %s",ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 30));
} */