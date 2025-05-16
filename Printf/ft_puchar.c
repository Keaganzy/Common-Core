/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:07:53 by ksng              #+#    #+#             */
/*   Updated: 2025/05/16 22:35:44 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* int ft_puchar(int c, t_content *fwp)
{
	char s;
	char str[2];
	char *formatted;
	int len;

	s = (char)c;
	str[0] = s;
	str[1] = '\0';
	formatted = ft_strdup(str);
	if (fwp->w_width > 1)
	{
		if (fwp->f_minus)
			formatted = ft_left_jus(formatted, fwp->w_width);
		else
			formatted = ft_right_jus_spc_zero(formatted, fwp->w_width, 1);
	}
	len = ft_strlen(formatted);
	write(1, formatted, len);
	free(formatted);
	return (len);
} */

int ft_puchar(int c, t_content *fwp)
{
    char padding;
    int len;
    int i;
    
    padding = ' ';
    if (fwp->f_zero_pad)
        padding = '0';
        
    len = 1;  // Character always has length 1
    
    // Handle width if greater than 1
    if (fwp->w_width > 1)
    {
        if (fwp->f_minus)  // Left-justified
        {
            write(1, &c, 1);  // Write character first
            i = 1;
            while (i < fwp->w_width)  // Then padding
            {
                write(1, &padding, 1);
                i++;
            }
        }
        else  // Right-justified
        {
            i = 1;
            while (i < fwp->w_width)  // Padding first
            {
                write(1, &padding, 1);
                i++;
            }
            write(1, &c, 1);  // Then character
        }
        return (fwp->w_width);  // Return total width
    }
    else
    {
        // No width specified, just write the character
        write(1, &c, 1);
        return (1);
    }
}
