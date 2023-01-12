/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:24:01 by cestevez          #+#    #+#             */
/*   Updated: 2023/01/12 23:32:24 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

/*	1st % -- 1st additional arg
	2nd % -- 2nd add arg
	etc
	% followed by a letter that specifies the format
*/

int	format_check(const char *c, const char *to_print)
{
	if (c == c)
	{
		ft_putchar(to_print);
		return (ft_putchar);
	}
/*	if (format == s)
	{
		
	}
//d takes as much space as needed
	if (format == d)
	{

	}
	if (format == i)
	{

	}
	if (format == %)
	{

	}
	if (format == p)
	{

	}
	if (format == u)
	{

	}
	if (format == x)
	{

	}
	if (format == X)
	{

	}
*/	
}

int	ft_printf(const char *format, ...)
{
	va_list		arg_list;
	const char	*argument;
	size_t		i;
	size_t		j;
	size_t		format_len;

	i = 0;
	j = 0;
//get the length of the ppal str
	format_len = ft_strlen(format);
//initialize the arg list
	va_start(arg_list, format);
//while ?? ,get the next arg. va_arg dereferences the ptr-->to get access
//to the value inside of the variable it points to, and advances the pointer
//to skip past that argument
	while(*format != 0)
	{
		if (*format == "%" && *(format + 1) == "%")
			ft_putchar(*(format + 1));
		while (*format != "%")
			ft_putstr(*format);
//does the va_list recognize from itself where the argument begins 
//or do I have to give a return with the position?
		if (*format == "%")
		{
			argument = va_arg(arg_list, format);
			format_check(*(format + 1), argument);
		}
		
		
		
	}
	va_end(args);

}

int	main()
{
	ft_printf("Something like this %d, %s", 10, "string");
	printf("Something like this %d, %s", 10, "string");
	return (0);
}