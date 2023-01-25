/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:24:01 by cestevez          #+#    #+#             */
/*   Updated: 2023/01/25 21:52:26 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include "libft.h"

int	type_print(const char c, va_list arg_list);

int	ft_printf(const char *format, ...)
{
	va_list	arg_list;
	int		len;
	int		i;

	len = 0;
	i = 0;

	va_start(arg_list, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			len += type_print(format[i + 1], arg_list);
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(arg_list);
	return (len);
}

int	type_print(const char c, va_list arg_list)
{
	char	*converted;

	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (print_char(va_arg(arg_list, int)));
	if (c == 's')
		return (print_string(va_arg(arg_list, char *)));
	if (c == 'd' || c == 'i')
		return (print_nbr(va_arg(arg_list, int)));
	if (c == 'u')
		return (print_unsigned(va_arg(arg_list, unsigned int)));
	if (c == 'x' || c == 'X')
		converted = print_hex(va_arg(arg_list, unsigned int), c);
	if (c == 'p')
		converted = print_address(va_arg(arg_list, size_t));
	if (c == 'x' || c == 'X' || c == 'p')
		return (print_string(converted));
	else
		return (-1);
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