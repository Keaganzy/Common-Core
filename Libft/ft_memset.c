/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:25:34 by ksng              #+#    #+#             */
/*   Updated: 2025/05/09 16:42:29 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *str, int a, size_t n)
{
    while (n > 0)
    {
        ((unsigned char *)str)[n - 1] = (unsigned char)a;
        n--;
    }
    return (str);
}

/* int	main()
{
	char s[] = "123456";
	char t[] = "123456";
	memset(s, 'a', 3);
	ft_memset(t, 'a', 3);
	printf("OG string: %s", s);
	printf("\nft string: %s", t);
} */