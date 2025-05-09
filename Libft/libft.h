
#ifndef LIBFT_H

#define LIBFT_H

#include <stddef.h>
#include <unistd.h>

size_t ft_strlcat(char *dst, const char *src, size_t size);
size_t ft_strlen(const char *s);
char *ft_strnstr(const char *big, const char *little, size_t len);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
void ft_bzero(void *s, size_t n);

#endif

