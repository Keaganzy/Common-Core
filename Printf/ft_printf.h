/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:53:07 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 17:36:38 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_puchar(int c);
int		ft_puhexnbr(unsigned int n, char c);
int		ft_puitoa(int nbr);
int		ft_pupointer(unsigned long addr);
int		ft_pustring(char *str);
int		ft_puunitoa(unsigned int n);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *s, ...);

#endif
