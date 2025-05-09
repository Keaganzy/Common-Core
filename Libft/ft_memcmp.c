/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:02:52 by ksng              #+#    #+#             */
/*   Updated: 2025/05/09 15:06:46 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    while (n > 0)
    {
        if (*((unsigned char *)s1) != *((unsigned char *)s2))
        {
            break;
        }
        s1++;
        s2++;
        n--;
    }

    if (n == 0)
    {
        return (0);
    }
    else 
    {
        return (*((unsigned char *)s1) - *((unsigned char *)s2));
    }
}