/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:24:01 by cestevez          #+#    #+#             */
/*   Updated: 2023/01/14 02:27:09 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
//#include "libft.h"

int		unsigned_printf(unsigned int n);
char	*ft_strchr(const char *s, int c);
int		putnbr_printf(int n);
int		putstr_printf(char *s);
int		putchar_printf(char c);
int		type_print(const char *c, va_list arg);

int	ft_printf(const char *format, ...)
{
	va_list		arg_list;
	char		*type_ptr;
	int			i;
	int			len;

	i = 0;
	len = 0;
	if (format == 0)
		return (0);
//initialize the arg list
	va_start(arg_list, format);
//no need to get the next arg for now, just iterate the 1st str
//to print it + the other args (if there)
	while (format[i] != 0)
	{
		type_ptr = ft_strchr("cspdiuxX%", format[i + 1]);
		if (format[i] == '%' && type_ptr != 0)
		{
			len += type_print(type_ptr, arg_list);
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(arg_list);
	return (len);
}
//Man says: If arg_list is passed to a function that uses va_arg(arg_list,type),
//then the value of arg_list is undefined after the return of that function!!!
//use va_copy to avoid undefined values??!

int	type_print(const char *c, va_list arg_list)
{
	int	len;
//va_arg dereferences the ptr-->to get access to the value inside
//of the variable it points to, and advances the pointer automatically
//each time we call it to skip past that argument. How? no idea
//as arg we give the list of args in which to iterate and the type we
//want it to return??
	len = 0;
	if (*c == '%')
		len += write(1, "%", 1);
	if (*c == 'c')
		len = putchar_printf(va_arg(arg_list, int));
	if (*c == 's')
		len = putstr_printf(va_arg(arg_list, char *));
//d takes as much space as needed
//with printf both can be printed the same way, but with scanf they
//have to be treated different
	if (*c == 'd' || *c == 'i')
		len = putnbr_printf(va_arg(arg_list, int));
	if (*c == 'u')
		len = unsigned_printf(va_arg(arg_list, unsigned int));
/*	if (c == 'x')
	{

	}
	if (c == 'X')
	{

	}
	if (c == 'p')
	{

	}*/
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
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
	while (s[i] != 0)
	{
		len += write (1, &s[i], 1);
		i++;
	}
	return (len);
}

int	putnbr_printf(int n)
{
	int	putme;
	int	len;

	len = 0;
	if (n == -2147483648)
		len = write (1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= -1;
			len += write (1, "-", 1);
		}
		if (n > 9)
			putnbr_printf(n / 10);
		putme = n % 10 + '0';
		len += write(1, &putme, 1);
	}
	return (len);
}

int	unsigned_printf(unsigned int n)
{
	int	putme;
	int	len;

	len = 0;
	if (n > 9)
		putnbr_printf(n / 10);
	putme = n % 10 + '0';
	len += write(1, &putme, 1);
	return (len);
}

int	main()
{
	ft_printf("Something like %u", -10);
	printf("\n");
	printf("Something like %u", -10);
	return (0);
}
