/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:56:53 by ksng              #+#    #+#             */
/*   Updated: 2025/05/10 09:50:43 by ksng             ###   ########.fr       */
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
        if (s[i] != c)
            flagc = 1;
        else
        {
            if (flagc == 1)
            {
                count++;
                flagc = 0;
            }
        }
        i++;
    }
    if (flagc)
        count++;
    return (count);
}
static char *ft_wordinsert(char const *s, int start, int end)
{
    char *str;
    size_t i;

    i = 0;
    str = malloc(sizeof(char) * (end - start + 1));
    if (!str)
    {
        return (NULL);
    }
    while (start < end)
    {
        str[i] = s[start];
        i++;
        start++;
    }
    str[i] = '\0';
    return (str);
}

static int ft_wordsplit(char const *s, char c, char **str)
{
    size_t i;
    size_t j;
    int index;

    i = -1;
    j = 0;
    index = -1;
    while (++i <= ft_strlen(s))
    {
        if (s[i] != c && index < 0)
            index = i;
        else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
        {
            str[j] = ft_wordinsert(s, index, i);
            if (!str[j])
            {
                while (j-- >= 0)
                    free(str[j]);
                return (0);
            }
            j++;
            index = -1;
        }
    }
    return (1);
}

char **ft_split(char const *s, char c)
{
    char **str;
    size_t wordcount;

    wordcount = ft_countsplit(s, c);
    str = malloc(sizeof(char *) * (wordcount + 1));
    if (!str || !s)
        return (NULL);
    str[wordcount] = 0;
    if (!(ft_wordsplit(s, c, str)))
    {
        return (NULL);
    }
    return (str);
}

/* int main()
{
    char *s = ",,,,,,";
    char c;
    char **str;
    int i = 0;

    c = ',';

    str = ft_split(s,c);
    while (str[i] != 0)
    {
        printf("--->%s\n",str[i]);
        i++;
    }
    
} */