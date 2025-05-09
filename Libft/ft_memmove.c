/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:17:05 by ksng              #+#    #+#             */
/*   Updated: 2025/05/09 15:06:57 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    void *temp;
    
    temp = dest;
    if (dest > src)
    {
        while (n > 0)
        {
            ((char *)dest)[n-1] = ((char *)src)[n-1];
            n--;
        }
    }
    else
    {
        while (n > 0)
        {
            *((char *)temp) = *((char *)src);
            temp++;
            src++;
            n--;
        }
    }
    return (dest);
}