/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:53:07 by ksng              #+#    #+#             */
/*   Updated: 2025/05/13 17:59:20 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

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

#endif