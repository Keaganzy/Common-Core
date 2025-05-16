/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:31:57 by ksng              #+#    #+#             */
/*   Updated: 2025/05/16 22:38:34 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char s[2];
	int c = 123;
	char *str;

	str = &s[0];

	s[0] = 'a';
	s[1] = '\0';
	ft_printf("fake|%-10s||%-10i||%-10.6c||%-10u||%-10x||%-10X||%-10p||%-10d||%%|\n",0,c,0,c,c,c,c,str,c);
	printf("real|%-10s||%-10i||%-10.6c||%-10u||%-10x||%-10X||%-10p||%-10d||%%|\n", 0, c,0,c,c,c,c,str,c);

	/*ft_printf("fake|%10s||%10i||%10c||%10u||%10x||%10X||%10p||%10d||%%|\n","happy",c,s[0],c,c,c,c,str,c);
	printf("real|%10s||%10i||%10c||%10u||%10x||%10X||%10p||%10d||%%|\n", "happy", c,s[0],c,c,c,c,str,c);

	ft_printf("fake|%10.3s||%10.3i||%10.3c||%10.3u||%10.3x||%10.3X||%10.3p||%10.3d||%%|\n","happy",c,s[0],c,c,c,c,str,c);
	printf("real|%10.3s||%10.3i||%10.3c||%10.3u||%10.3x||%10.3X||%10.3p||%10.3d||%%|\n", "happy", c,s[0],c,c,c,c,str,c);
	
	ft_printf("fake|%010.3s||%010.3i||%010.3c||%010.3u||%010.3x||%010.3X||%010.5p||%010.3d||%%|\n","happy",c,s[0],c,c,c,c,str,c);
	printf("real|%010.3s||%010.3i||%010.3c||%010.3u||%010.3x||%010.3X||%010.5p||%010.3d||%%|\n", "happy", c,s[0],c,c,c,c,str,c);
	
	ft_printf("fake|%0+- #10.3s||%0+- #10.3i||%0+- #10.3c||%0+- #10.3u||%0+- #10.3x||%0+- #10.3X||%0+- #10.3p||%0+- #10.3d||%%|\n","happy",c,s[0],c,c,c,0,str,c);
	printf("real|%0+- #10.3s||%0+- #10.3i||%0+- #10.3c||%0+- #10.3u||%0+- #10.3x||%0+- #10.3X||%0+- #10.3p||%0+- #10.3d||%%|\n", "happy", c,s[0],c,c,c,0,str,c); */
	/* int rt = printf("asdasd|%-10.1s|\n", 'asdasd');
	printf("\nrt: %d", rt); */
}

// c = -,width
// s = -,width,. Trucnt
// p = -,width, . expand 000, 0 = 0000 so precision overides 0 padding
// width 10, precision 4, zeroflag = 1. word = ff.
// |    0x00ff| but if no precision then |0x000000ff| then if add - then 
// |0xff      | have to deal with + and " " flags.
