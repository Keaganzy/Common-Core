/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:40:23 by ksng              #+#    #+#             */
/*   Updated: 2025/05/17 18:40:44 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_app_plus_and_space(char *str, int neg, t_content *fwp)
{
    char *result;

    if (!str)
        return (NULL);

    if (neg || (ft_strncmp(str, "(nil)", 5) == 0))
        return (str);
    
    if (fwp->f_plus)
    {
        result = ft_strjoin("+", str);
        free(str);
        return (result);
    }
    else if (fwp->f_space)
    {
        result = ft_strjoin(" ", str);
        free(str);
        return (result);
    }
    return (str);
}