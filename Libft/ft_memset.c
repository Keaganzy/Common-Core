

#include "libft.h"
#include <stdio.h>
#include <stddef.h>


void *ft_memset(void *str, int a, size_t n)
{
    while (n > 0)
    {
        ((unsigned char *)str)[n - 1] = (unsigned char)a;
        n--;
    }
    return (str);
}

int	main()
{
	char s[] = "123456";
	char t[] = "123456";
	memset(s, 'a', 3);
	ft_memset(t, 'a', 3);
	printf("OG string: %s", s);
	printf("\nft string: %s", t);
}