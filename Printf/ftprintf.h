/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:53:07 by ksng              #+#    #+#             */
/*   Updated: 2025/05/16 18:22:29 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H

# define FTPRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
//remove
#include <stdio.h>

typedef struct s_content
{
	int f_minus;
	int f_zero_pad;
	int f_hash;
	int f_plus;
	int f_space;
	int w_width;
	int p_precision;
}	t_content;

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char *ft_right_justify(char *str, int width, int pad_zero);
char *ft_right_jus_spc_zero(char *str, int width, int space);
char *ft_left_jus(char *str, int width);
int ft_putchar(char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
//unitoa %u
int ft_puunitoa(unsigned int n, t_content *fwp);
//%s
int ft_pustring(char *str, t_content *fwp);
char *ft_app_preci_str(char *str, int precision);
//%p
int	ft_pupointer(unsigned long addr, t_content *fwp);
void	ft_memset(void *s, int c, size_t n);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
//%%
int	ft_pupercent(t_content *fwp);
//%id
int ft_puitoa(int nbr, t_content *fwp);
char *ft_prep_int_str(int nbr, int neg, t_content *fwp);
char	*ft_app_plus_and_space(char *str, int neg, t_content *fwp);
char	*ft_app_preci_num(char *str, int precision);
//%xX
int	ft_puhexnbr(unsigned int n, char c, t_content *fwp);
int	ft_puthex(unsigned int n, int uppercase, t_content *fwp);
char	*ft_uitoa_base(unsigned int n, int uppercase);
//%c
int ft_puchar(int c, t_content *fwp);
//main
int ft_printf(const char *s, ...);
int ft_printcontent(const char *s, va_list args, int *i);
void ft_initcontent(t_content *fwp);
void ft_findfwp(const char *s, t_content *fwp, int *i);
int ft_findflag(char s, t_content *fwp);
int ft_findwidth(char s, t_content *fwp);
int ft_findp(char s, t_content *fwp);


#endif