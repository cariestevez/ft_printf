/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:24:01 by cestevez          #+#    #+#             */
/*   Updated: 2023/01/20 20:55:54 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include "libft.h"

char	*toupper_printf(char *s);
char	*printf_hex(unsigned num, int base, const char *c);
char	*hex_ptr(char *ptr, int i, int j, unsigned num, int base);
char	*printf_address(size_t num, int base);
char	*ft_strchr(const char *s, int c);
int		putnbr_printf(int n, int len);
int		putunsigned_printf(unsigned n, const char *c, int len);
int		putstr_printf(char *s);
int		putchar_printf(char c);
int		type_print(const char *c, va_list arg);

int	ft_printf(const char *format, ...)
{
	va_list		arg_list;
	char		*type_ptr;
	int			len;
	int         i;

	len = 0;
	i = -1;
	if (format == 0)
		return (0);
	va_start(arg_list, format);
	while (format[++i] != 0)
	{
		if (format[i] == '%')
		{
			if (!(type_ptr = ft_strchr("cspdiuxX%", format[i++ + 1])))
				return (0);
			len += type_print(type_ptr, arg_list);
		}
		else
			len += write(1, &format[i], 1);
	}
	va_end(arg_list);
	return (len);
}

int	type_print(const char *c, va_list arg_list)
{
	int		len;
	char	*converted;

	len = 0;
	if (arg_list == 0)
		return (0);
	if (*c == '%')
		len += write(1, "%", 1);
	if (*c == 'c' || *c == '%')
		len = putchar_printf(va_arg(arg_list, int));
	if (*c == 's')
		len = putstr_printf(va_arg(arg_list, char *));
	if (*c == 'd' || *c == 'i')
		len = putnbr_printf(va_arg(arg_list, int), len);
	if (*c == 'u')
		len = putunsigned_printf(va_arg(arg_list, unsigned int), c, len);
	if (*c == 'x' || *c == 'X')
		converted = printf_hex(va_arg(arg_list, unsigned int), 16, c);
	if (*c == 'p')
		converted = printf_address(va_arg(arg_list, size_t), 16);
	if (*c == 'x' || *c == 'X' || *c == 'p')
		len = putstr_printf(converted);
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

int	putchar_printf(char c)
{
	int	len;

	len = write (1, &c, 1);
	return (len);
}

int	putstr_printf(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s[i] == 0)
		len += write (1, &s[i], 1);
	while (s[i] != 0)
	{
		len += write (1, &s[i], 1);
		i++;
	}
	return (len);
}

int	putnbr_printf(int n, int len)
{
	char	num;

	if (n > -10 && n < 0)
		len += write(1, "-", 1);
	if (n >= 10 || n <= -10)
		putnbr_printf(n / 10, len);
	if (n < 0)
	{
		n %= 10;
		n *= -1;
	}
	num = (n % 10) + 48;
	len += write(1, &num, 1);
	return (len);
}

int	putunsigned_printf(unsigned n, const char *c, int len)
{
	char	num;

	if (n >= 10)
		putunsigned_printf(n / 10, c, len);
	num = (n % 10) + 48;
	len = write(1, &num, 1);
	return (len);
}

char	*printf_hex(unsigned num, int base, const char *c)
{
	char		*ptr;
	unsigned	temp;
	int			i;
	int			j;

	j = 0;
	i = 0;
	temp = num;
	while (temp != 0)
	{
		i++;
		temp /= base;
	}
	if (temp == 0)
		j = 1;
	if (!(ptr = (char *)malloc(sizeof(char) * (i + j) + 1)))
		return (0);
	ptr = hex_ptr(ptr, i, j, num, base);
	if (*c == 'X')
		ptr = toupper_printf(ptr);
	return (ptr);
}

char	*hex_ptr(char *ptr, int i, int j, unsigned num, int base)
{
	char	str[] = "0123456789abcdef";

	if (num == 0)
	{
		ptr[j] = 0;
		ptr[j-1] = num + 48;
	}
	if (num != 0)
	{
		ptr[i] = 0;
		while (i >= 0)
		{
			ptr[i - 1]= str[num % base];
			num /= base;
			i--;
		}
	}
	return (ptr);
}

char	*printf_address(size_t num, int base)
{
	char	str[] = "0123456789abcdef";
	char	*ptr;
	size_t	temp;
	int		i;

	i = 1;
	temp = num;
	while (temp != 0)
	{
		i++;
		temp /= base;
	}
	if (!(ptr = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	ptr[i + 1] = 0;
	while (i > 1)
	{
		ptr[i--]= str[num % base];
		num /= base;
	}
	ptr[1] = 'x';
	ptr[0] = '0';
	return (ptr);
}

char	*toupper_printf(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] > 96 && s[i] < 123)
			s[i] += 32;
		i++;
	}
	return (s);
}
/*int	main()
{
	int	a = 2;
	int *p = &a;

	ft_printf("Something like %%\n");
	printf("to be:Something like %%\n");
	ft_printf("Something like %p\n", &a);
	printf("Something like %p\n", &a);
	ft_printf("Something like %p\n", p);
	printf("Something like %p\n", p);
	ft_printf("Something like %x\n", 230837698);
	printf("to be: Something like %x\n", 230837698);
	printf(0);
	ft_printf(0);
	ft_printf("Something like %u\n", -4294967294);
	printf("to be: Something like %u\n", -4294967294);
	ft_printf("Something like %i\n", 2147483648);
	printf("to be: Something like %i\n", 2147483648);
	return (0);
}*/

