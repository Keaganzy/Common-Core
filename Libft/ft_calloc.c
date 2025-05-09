/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:47:07 by ksng              #+#    #+#             */
/*   Updated: 2025/05/09 16:32:26 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;

    if (nmemb * size > (1LL << 32) - 1)
        return (NULL);
    ptr = malloc(nmemb * size);
    if(ptr)
    {
        ft_bzero(ptr, nmemb * size);
    }
    return (ptr);
}
/* #include <stdio.h>

int	main()
{
	printf("### Function: calloc ###");
	char *s = "hello";
	printf("\nft: %s\n",s);
	
	s = ft_calloc(sizeof(char), 2);
	printf("\nft: %c\n",s[0]);
} */