/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:56:53 by ksng              #+#    #+#             */
/*   Updated: 2025/05/09 22:26:16 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_countsplit(char const *s, char c)
{
    int i;
    int flagc;
    int count;

    i = 0;
    count = 0;
    flagc = 0;
    while (s[i] != '\0')
    {
        while (s[i] == c)
        {
            if(flagc == 1)
                count++;
            flagc = 0;
            i++;
        }
        flagc = 1;
        i++;
    }
    if (flagc)
        count++;
    return (count);
}
static void ft_mallocsplit(char **str, char const *s, char c)
{
    int i;
    int flagc;
    size_t start;
    size_t end;

    i = 0;
    flagc = 0;
    end = 0;
    while (s[end] != '\0')
    {
        while (s[end] == c)
        {
            if(flagc == 1)
            {
                str[i] = malloc(sizeof(char *) * (end - start + 1));
                if (!str[i])
                {
                    while (i-- >= 0)
                        free(str[i]);
                }
                i++;
            }
            flagc = 0;
            end++;
        }
        flagc = 1;
        start = end;
    }
}

char **ft_split(char const *s, char c)
{
    size_t start;
    size_t end;
    char **str;
    size_t i;

    i = 0;
    end = 0;
    str = malloc(sizeof(char **) * (ft_countsplit(s, c) + 1));
    str[ft_countsplit(s, c)] = '\0';
    
}