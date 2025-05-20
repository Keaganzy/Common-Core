/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:53:53 by ksng              #+#    #+#             */
/*   Updated: 2025/05/17 18:54:13 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_counthex(unsigned long addr)
{
    int count;
    
    count = 0;
    if (addr == 0)
        return (1);
    while (addr > 0)
    {
        addr /= 16; 
        count++;
    }
    return (count);
}
