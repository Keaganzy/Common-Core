/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:45:58 by ksng              #+#    #+#             */
/*   Updated: 2025/05/13 22:39:29 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	ptr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (ptr)
	{
		ft_strlcpy(ptr, s1, (ft_strlen(s1) + 1));
		ft_strlcat(ptr, s2, ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	}
	else
	{
		free(ptr);
	}
	return (ptr);
}
/* int	main()
{
	printf("### Function: ft_strjoin ###");
	printf("\nft_strjoin: %s\n",ft_strjoin("hello","world"));
} */