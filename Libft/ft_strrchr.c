/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:01:10 by ksng              #+#    #+#             */
/*   Updated: 2025/05/09 12:24:03 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(char *s, int a)
{
    char *last;
    int flag;
    
    flag = 0;
    while (*s != '\0')
    {
        if(*s == a)
        {
            last = s;
            flag = 1;
        }
        s++;
    }
    if (a == '\0')
    {
        return s;
    }
    if (flag == 1)
    {
        return last;
    }
    return (NULL);
}
