/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:04:35 by ksng              #+#    #+#             */
/*   Updated: 2025/05/10 11:37:28 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t slen;
    char *str;
    int i;

    i = 0;
    slen = ft_strlen(s);
    str = malloc (sizeof(char) * (slen + 1));
    if (!str)
        return (NULL);
    str[slen] = '\0';
    while (s[i] != '\0')
    {
        str[i] = f(i,s[i]);
        i++;
    }
    return (str);
}
/* #include <ctype.h>

char	f_even_toupper(unsigned int idx, char c)
{
	if (idx % 2 == 1)
		return (toupper(c));
	return (c);
}

char	f_mask_char(unsigned int idx, char c)
{
	(void)idx;
	if (c == ' ')
		return (c);
	return ('*');
}

void	test(char const *s, char (*f)(unsigned int, char), const char *f_name, const char *expected)
{
	char	*result = ft_strmapi(s, f);
	printf("|----------| %*s | %*s |\n", 26, s, 16, f_name);
	printf("| actual   | %s\n", result);
	printf("| expected | %s\n", expected);
	if (result != 0)
		free(result);
}


int	main(void)
{
	printf("--- ft_strmapi\n| results  | %*s | %*s |\n", 26, "s", 16, "func");

	// case 1: f_even_toupper normal string
	test("hello!", f_even_toupper, "f_even_toupper", "hElLo!");
	// case 2: f_even_toupper empty string
	test("", f_even_toupper, "f_even_toupper", "");
	// case 3: different function
	test("very secret password", f_mask_char, "f_mask_char", "**** ****** ********");
} */