/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:07:53 by ksng              #+#    #+#             */
/*   Updated: 2025/05/17 17:45:26 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puchar(int c, t_content *fwp)
{
    char padding;
    int len;
    int i;
    
    padding = ' ';
    len = 1;
    if (fwp->w_width > 1)
    {
        if (fwp->f_minus)
        {
            write(1, &c, 1);
            i = 1;
            while (i < fwp->w_width)
            {
                write(1, &padding, 1);
                i++;
            }
        }
        else
        {
            i = 1;
            while (i < fwp->w_width)
            {
                write(1, &padding, 1);
                i++;
            }
            write(1, &c, 1);
        }
        return (fwp->w_width);
    }
    else
    {
        write(1, &c, 1);
        return (1);
    }
}
