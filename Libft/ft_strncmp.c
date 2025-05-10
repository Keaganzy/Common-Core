/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:19:09 by ksng              #+#    #+#             */
/*   Updated: 2025/05/10 18:18:17 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t size;

    size = 0;
    while (*s1 != '\0' && *s2 != '\0' && size < n)
    {
        if (*s1 != *s2)
        {
            break;
        }
        s1++;
        s2++;
        size++;
    }
    if (size == n)
        return (0);
    return (unsigned char) *s1 - (unsigned char) *s2;
}
