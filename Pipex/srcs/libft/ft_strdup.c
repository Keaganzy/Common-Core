/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:08:27 by ksng              #+#    #+#             */
/*   Updated: 2025/05/12 18:04:52 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	if (!s)
	{
		return (NULL);
	}
	str = malloc(ft_strlen(s) + 1);
	if (str)
	{
		ft_strlcpy(str, s, ft_strlen(s) + 1);
		return (str);
	}
	else
	{
		return (NULL);
	}
}
/* #include <string.h>
#include <stdio.h>

int	main()
{
	char *s = "helloasdasd";
	printf("### Function: stdup ###");
	printf("\nOG: %s:", strdup(s));
	printf("\nft: %s:\n", ft_strdup(s));
} */