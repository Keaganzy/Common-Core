/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pupointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:12:10 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 12:55:15 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
}


static void ft_puhexanum(char *str, unsigned long addr, int count)
{
    int     i;
    char    *hex;

    hex = "0123456789abcdef";
    i = 0;
    if (addr == 0)
        str[i++] = '0';
    else
    {
        while (count > 0)
        {
            str[i++] = hex[addr % 16];
            addr /= 16;
            count--;
        }
    }
    str[i] = '\0';
}

static void ft_reversestr(char *str)
{
    int     start;
    int     end;
    char    temp;

    if (!str)
        return;
    start = 0;
    end = ft_strlen(str) - 1;
    while (start < end)
    {
        temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
}

static void ft_putnil(char *str)
{
    ft_strlcpy(str, "(nil)", 6);
}

static char *ft_format_pointer_string(unsigned long addr, int precision)
{
    char    *hex_str;
    int     hex_len;
    int     total_len;
    int     padding_len;

    if (addr == 0)
    {
        hex_str = malloc(6);
        if (!hex_str)
            return (NULL);
        ft_putnil(hex_str);
        return (hex_str);
    }
    
    hex_len = ft_counthex(addr);
    padding_len = (precision > hex_len) ? precision - hex_len : 0;
    total_len = 2 + ((precision > hex_len) ? precision : hex_len);
    
    hex_str = malloc(total_len + 1);
    if (!hex_str)
        return (NULL);
    ft_memset(hex_str, 0, total_len + 1);
    hex_str[0] = '0';
    hex_str[1] = 'x';
    
    ft_memset(hex_str + 2, '0', padding_len);
    ft_puhexanum(hex_str + 2 + padding_len, addr, hex_len);
    ft_reversestr(hex_str + 2 + padding_len);
    
    return (hex_str);
}

int ft_pupointer(unsigned long addr, t_content *fwp)
{
    char    *formatted;
    char    *ptr_str;
    int     len;
    int     precision;
    
    precision = (fwp->p_precision == -1) ? 0 : fwp->p_precision;
    
    ptr_str = ft_format_pointer_string(addr, precision);
    if (!ptr_str)
        return (0);
    
    formatted = ft_app_plus_and_space(ptr_str, 0, fwp);
    if (!formatted)
    {
        free(ptr_str);
        return (0);
    }
    
    len = ft_strlen(formatted);
    if (fwp->w_width > len)
    {
        char *padded;
        
        if (fwp->f_minus)
            padded = ft_left_jus(formatted, fwp->w_width);
        else if (fwp->f_zero_pad)
            padded = ft_right_justify(formatted, fwp->w_width, 0);
        else
            padded = ft_right_justify(formatted, fwp->w_width, 0);
            
        if (!padded)
        {
            free(formatted);
            return (0);
        }
        
        formatted = padded;
        len = ft_strlen(formatted);
    }
    
    write(1, formatted, len);
    free(formatted);
    return (len);
}
