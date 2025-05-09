/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:01:10 by ksng              #+#    #+#             */
/*   Updated: 2025/05/09 16:48:40 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    char *last;
    int flag;
    
    flag = 0;
    while (*s != '\0')
    {
        if(*s == c)
        {
            last = s;
            flag = 1;
        }
        s++;
    }
    if (c == '\0')
    {
        return s;
    }
    if (flag == 1)
    {
        return last;
    }
    return (NULL);
}
