/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:37:06 by ksng              #+#    #+#             */
/*   Updated: 2025/05/10 19:08:14 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t slen;
    size_t dlen;

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
/* #include <stdio.h>
#include <bsd/string.h>

int main (void)
{
	char src[] = "123";
	char dest[] = "abcde";
	printf("ft len: %ld \n", ft_strlcat(dest, src, 4));
	printf("ft dest: %s \n", dest);

	char src2[] = "123";
	char dest2[] = "abcde";
	printf("og len: %ld \n", strlcat(dest2, src2, 4));
	printf("og dest: %s \n", dest2);
} */