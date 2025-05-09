/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:43:08 by ksng              #+#    #+#             */
/*   Updated: 2025/05/09 12:23:23 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    int flag;

    flag = 0;
    
    while (*src != '\0' && size > 0)
    {
        *dst = *src;
        dst++;
        src++;
        size--;
        flag = 1;
    }
    if (flag)
    {
        *dst = '\0';
    }
    return (ft_strlen(src));
}