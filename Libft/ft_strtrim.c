/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:55 by ksng              #+#    #+#             */
/*   Updated: 2025/05/09 20:20:54 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_charinset(char c, char const *set)
{
    while (*set != '\0')
    {
        if (c == *set)
        {
            return (1);
        }
        set++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *ptr;
    size_t start;
    size_t end;
    size_t i;

    i = 0;
    start = 0;
    if (!s1)
        return (NULL);
    if (!set)
        return (ft_strdup(s1));
    while (s1[start] && ft_charinset(s1[start], set))
        start++;
    end = ft_strlen(s1);
    while (end > start && ft_charinset(s1[end - 1], set))
        end--;
    ptr = malloc(sizeof(char) * (end - start + 1));
    if (!ptr)
        return (NULL);
    while (start < end)
        ptr[i++] = s1[start++];
    ptr[i] = '\0';
    return (ptr);
}

/* int	main(void)
{
	printf("1: %s\n", ft_strtrim(" oijsaodj ioasjd     daoijdo ", " "));
	printf("2: %s\n", ft_strtrim("hello world", ""));
    printf("3: %s\n", ft_strtrim("0213h3l0w00934", "0123456789"));
} */

