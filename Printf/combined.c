/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:43:28 by ksng              #+#    #+#             */
/*   Updated: 2025/05/16 10:45:43 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:43:01 by ksng              #+#    #+#             */
/*   Updated: 2025/05/16 10:41:17 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (slen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
	{
		return (NULL);
	}
	if (len > ft_strlen(s) - start)
	{
		len = ft_strlen(s) - start;
	}
	if (start > ft_strlen(s))
	{
		len = 0;
		start = ft_strlen(s);
	}
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr)
	{
		ft_strlcpy(ptr, s + start, len + 1);
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}


int ft_findp(const char *s, t_content *fwp)
{
	if (*s == '.')
	{
		fwp->p_precision = 0;
		return (1);
	}
	if ('0' <= *s && *s <= '9')
	{
		fwp->p_precision *= 10;
		fwp->p_precision += *s - '0';
		return (1);
	}
	return (0);
}

int ft_findwidth(const char *s, t_content *fwp)
{
	if ('0' <= *s && *s <= '9')
	{
		fwp->w_width *= 10;
		fwp->w_width += *s - '0';
		return (1);
	}
	return (0);
}

int ft_findflag(const char *s, t_content *fwp)
{
	if (*s == '-')
		fwp->f_minus = 1;
	else if (*s == '0')
		fwp->f_zero_pad = 1;
	else if (*s == ' ')
		fwp->f_space = 1;
	else if (*s == '#')
		fwp->f_hash = 1;
	else if (*s == '+')
		fwp->f_plus = 1;
	else
		return 0;
	return 1;
}

void ft_findfwp(const char *s, t_content *fwp, int *i)
{
	while (ft_findflag(s[*i], &fwp))
		(*i)++;
	while (ft_findwidth(s[*i], &fwp))
		(*i)++;
	while (ft_findp(s[*i], &fwp))
		(*i)++;
}

ft_initcontent(t_content *fwp)
{
	fwp->f_hash = 0;
	fwp->f_minus = 0;
	fwp->f_plus = 0;
	fwp->f_zero_pad = 0;
	fwp->f_space = 0;
	fwp->w_width = 0;
	fwp->p_precision = -1;

}

int ft_printcontent(const char *s, va_list args, int *i)
{
	int count;
	t_content fwp;

	ft_initcontent(&fwp);
	count = 0;
	ft_findfwp(s[*i], &fwp, i);
	if (s[*i] == 'c')
		return (ft_puchar(va_arg(args, int), &fwp));
	else if (s[*i] == 's')
		return (ft_pustring(va_arg(args, char *), &fwp));
	else if (s[*i] == 'p')
		return (ft_pupointer(va_arg(args, unsigned long), &fwp));
	else if (s[*i] == 'd' || s[*i] == 'i')
		return (ft_puitoa(va_arg(args, int), &fwp));
	else if (s[*i] == 'u')
		return (ft_puunitoa(va_arg(args, unsigned int), &fwp));
	else if (s[*i] == 'x' || s[*i] == 'X')
		return (ft_puhexnbr(va_arg(args, unsigned int), s[*i], &fwp)); 
	else if (s[*i] == '%')
		return (ft_pupercent('%', &fwp));
	else
		(*i)--;
	return (0);
}

int ft_printf(const char *s, ...)
{
	va_list args;
	char *temp;
	int count;
	int i;
	
	count = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_printcontent(s[i], args, &i);
		}
		else
		{
			ft_putchar(s[i]);
			count++;
		}
		i++;
	}
	return (count);
}

int ft_puchar(int c, t_content *fwp)
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
}

static char	*ft_uitoa_base(unsigned int n, int uppercase)
{
	unsigned int	num;
	int		len;
	char	*str;
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	num = n;
	len = 0;
	if (n == 0)
		len = 1;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	num = n;
	if (n == 0)
		str[0] = '0';
	while (len > 0)
	{
		str[len - 1] = base[num % 16];
		num /= 16;
		len--;
	}
	return (str);
}

// Helper function to apply precision to a numeric string
static char	*ft_app_preci_num(char *str, int precision)
{
	int		len;
	char	*prec_str;
	int		i;

	if (precision == -1)
		return (str);
	len = ft_strlen(str);
	if (precision <= len)
		return (str);
	prec_str = malloc(precision + 1);
	if (!prec_str)
		return (NULL);
	i = 0;
	// No sign for unsigned
	while (i < precision - len)
		prec_str[i++] = '0';
	while (*str != '\0')
		prec_str[i++] = *str++;
	prec_str[i] = '\0';
	free(str);
	return (prec_str);
}

// Helper to apply the '#' flag
static char	*apply_hash(char *str, int uppercase, t_content *fwp)
{
	char	*prefix;
	char	*result;

	if (fwp->f_hash && str[0] != '0')
	{
		if (uppercase)
			prefix = "0X";
		else
			prefix = "0x";
		result = ft_strjoin(prefix, str);
		free(str);
		return (result);
	}
	return (str);
}

// Function to prepare the hexadecimal string
static char	*ft_prep_hex_str(unsigned int n, int uppercase, t_content *fwp)
{
	char	*str;
	char	*prec_str;
	char	*hash_str;

	str = ft_uitoa_base(n, uppercase);
	if (!str)
		return (NULL);
	prec_str = ft_app_preci_num(ft_strdup(str), fwp->p_precision);
	if (!prec_str)
	{
		free(str);
		return (NULL);
	}
	hash_str = apply_hash(prec_str, uppercase, fwp);
	if (!hash_str)
	{
		free(str);
		free(prec_str);
		return (NULL);
	}
	free(str);
	free(prec_str);
	return (hash_str);
}

// Function to output hexadecimal string with formatting options
static void	ft_puthex_body(char *padded_str, int len)
{
	write(1, padded_str, len);
	free(padded_str);
}

int	ft_puthex(unsigned int n, int uppercase, t_content *fwp)
{
	char	*padded_str;
	int		len;

	padded_str = ft_prep_hex_str(n, uppercase, fwp);
	if (!padded_str)
		return (0);
	len = ft_strlen(padded_str);
	if (fwp->w_width > len)
	{
		if (fwp->f_minus)
			padded_str = ft_left_jus(padded_str, fwp->w_width);
		else if (fwp->f_zero_pad && fwp->p_precision == -1)
			padded_str = ft_right_justify(padded_str, fwp->w_width, 1);
		else
			padded_str = ft_right_justify(padded_str, fwp->w_width, 0);
		len = ft_strlen(padded_str);
	}
	ft_puthex_body(padded_str, len);
	return (len);
}

// Function to handle %x and %X
int	ft_puhexnbr(va_list args, char c, t_content *fwp)
{
	unsigned int	n;
	int		uppercase;

	n = va_arg(args, unsigned int);
	if (c == 'X')
		uppercase = 1;
	else
		uppercase = 0;
	return (ft_puthex(n, uppercase, fwp));
}

// Helper function to apply precision to a numeric string
char	*ft_app_preci_num(char *str, int precision)
{
	int		len;
	char	*prec_str;
	int		i;

	if (precision == -1)
		return (str);
	len = ft_strlen(str);
	if (precision <= len)
		return (str);
	prec_str = malloc(precision + 1);
	if (!prec_str)
		return (NULL);
	i = 0;
	if (str[0] == '-')
	{
		prec_str[i++] = '-';
		len--;
	}
	while (i < precision - len)
		prec_str[i++] = '0';
	while (*str != '\0' && (*str == '-' || (*str >= '0' && *str <= '9')))
		prec_str[i++] = *str++;
	prec_str[i] = '\0';
	free(str);
	return (prec_str);
}

// Helper to apply +, and space flags.
static char	*ft_app_plus_and_space(char *str, int neg, t_content *fwp)
{
	char	*result;

	if (neg)
		return (str);
	if (fwp->f_plus)
	{
		result = ft_strjoin("+", str);
		free(str);
		return (result);
	}
	else if (fwp->f_space)
	{
		result = ft_strjoin(" ", str);
		free(str);
		return (result);
	}
	return (str);
}

char *ft_prep_int_str(int nbr, int neg, t_content *fwp)
{
	char *str;
	char *prec_str;
	char *sign_space_str;

	str = ft_itoa(nbr);
	prec_str = ft_app_preci_num(ft_strdup(str), fwp);
	if (!prec_str)
        free(str);
	sign_space_str = ft_app_plus_and_space(prec_str, neg, fwp);
	if (!sign_space_str)
    {
        free(str);
        free(prec_str);
    }
	if (!prec_str || !sign_space_str)
		return (NULL);
	free(str);
	free(prec_str);
	return (sign_space_str);
}

int ft_puitoa(int nbr, t_content *fwp)
{
	int neg;
	char *padded_str;
	int len;

	if (nbr < 0)
		neg = 1;
	padded_str = ft_prep_int_str(nbr, neg, fwp);
	if (!padded_str)
        return 0;
	len = ft_strlen(padded_str);
	if (fwp->f_zero_pad && fwp->p_precision == -1 && !fwp->f_minus)
		padded_str = ft_right_jus_spc_zero(padded_str, fwp->w_width, 0);
	else if (fwp->f_minus)
		padded_str = ft_left_jus(padded_str, fwp->w_width);
	else
		padded_str = ft_right_jus_spc_zero(padded_str, fwp->w_width, 1);
	len = ft_strlen(padded_str);
	write(1, padded_str, len);
    free(padded_str);
    return len;
}
int	ft_putpercent(t_content *fwp)
{
	char	*padded_str;
	int		len;

	padded_str = ft_strdup("%");
	if (!padded_str)
		return (0);
	len = ft_strlen(padded_str);
	if (fwp->w_width > len)
	{
		if (fwp->f_minus)
			padded_str = ft_left_jus(padded_str, fwp->w_width);
		else if (fwp->f_zero_pad)
			padded_str = ft_right_justify(padded_str, fwp->w_width, 1);
		else
			padded_str = ft_right_justify(padded_str, fwp->w_width, 0);
		len = ft_strlen(padded_str);
	}
	write(1, padded_str, len);
	free(padded_str);
	return (len);
}

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

static int	ft_counthex(unsigned long addr)
{
	int	count;

	count = 0;
	if (addr == 0)
		return (1);
	while (addr > 0)
	{
		addr /= 16; 
		count++;
	}
	return (count);
}

static void	ft_puhexanum(char *str, unsigned long addr)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;
	if (addr == 0)
		str[i++] = '0';
	while (addr > 0)
	{
		str[i++] = hex[addr % 16];
		addr /= 16;
	}
	str[i] = '\0';
}

static void	ft_reversestr(char *str)
{
	int		start;
	int		end;
	char	temp;

	if (!str)
		return;
	start = 0;
	end = strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
}

static void	ft_putnil(char *str)
{
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'i';
	str[3] = 'l';
	str[4] = ')';
	str[5] = '\0';
}


static int	calculate_total_length(int precision, int hex_len)
{
	if (precision > hex_len)
		return (2 + precision);
	return (2 + hex_len);
}

static char	*format_pointer_string(unsigned long addr, int precision)
{
	char	*hex_str;
	int		hex_len;
	int		total_len;

	hex_len = ft_counthex(addr);
	total_len = calculate_total_length(precision, hex_len);
	if (addr == 0)
	{
		hex_str = malloc(6);
		if (!hex_str)
			return (NULL);
		ft_putnil(hex_str);
		return (hex_str);
	}
	hex_str = malloc(total_len + 1);
	if (!hex_str)
		return (NULL);
	ft_puhexanum(hex_str + 2, addr);
	ft_reversestr(hex_str + 2);
	hex_str[0] = '0';
	hex_str[1] = 'x';
	if (precision > hex_len)
		ft_memset(hex_str + 2, '0', precision - hex_len);
	hex_str[total_len] = '\0';
	return (hex_str);
}

int	ft_pupointer(unsigned long addr, t_content *fwp)
{
	char	*formatted;
	int		len;

	formatted = format_pointer_string(addr, fwp->p_precision);
	if (!formatted)
		return (0);
	len = strlen(formatted);
	if (fwp->w_width > len)
	{
		if (fwp->f_minus)
			formatted = ft_left_jus(formatted, fwp->w_width);
		else if (fwp->f_zero_pad)
			formatted = ft_right_justify(formatted, fwp->w_width, 1);
		else
			formatted = ft_right_justify(formatted, fwp->w_width, 0);
		len = strlen(formatted);
	}
	write(1, formatted, len);
	free(formatted);
	return (len);
}

int ft_pustring(char *str, t_content *fwp)
{
	char *trunc;
	char *formatted;
	int len;
	
	if (!str)
		str = "(null)";
	trunc = ft_app_preci_str(ft_strdup(str), fwp->p_precision);
	formatted = trunc;
	if (fwp->w_width > ft_strlen(formatted))
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
}

static int	ft_uintlen(unsigned int n)
{
	unsigned int	num;
	int		len;

	num = n;
	len = 0;
	if (n == 0)
		len = 1;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

//  Helper to convert unsigned int to string
static char	*ft_uitoa(unsigned int n)
{
	unsigned int	num;
	int		len;
	char	*str;

	len = ft_uintlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	num = n;
	if (n == 0)
		str[0] = '0';
	while (len > 0)
	{
		str[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (str);
}

static char	*ft_prep_uint_str(unsigned int n, t_content *fwp)
{
	char	*str;
	char	*prec_str;

	str = ft_uitoa(n);
	if (!str)
		return (NULL);
	prec_str = ft_app_preci_num(ft_strdup(str), fwp->p_precision);
	if (!prec_str)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (prec_str);
}

int ft_puunitoa(unsigned int n, t_content *fwp)
{
	char *padded_str;
	int len;

	padded_str = ft_prep_uint_str(n, fwp);
	if (!padded_str)
		return (NULL);
	len = ft_strlen(padded_str);
	if (fwp->w_width > len)
	{
		if (fwp->f_minus)
			padded_str = ft_left_jus(padded_str, fwp->w_width);
		else if (fwp->f_zero_pad && fwp->p_precision == -1)
			padded_str = ft_right_justify(padded_str, fwp->w_width, 1);
		else
			padded_str = ft_right_justify(padded_str, fwp->w_width, 0);
		len = ft_strlen(padded_str);
	}
	write(1, padded_str, len);
	free(padded_str);
	return (len);
}
