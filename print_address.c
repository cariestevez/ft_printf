/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:10:11 by cestevez          #+#    #+#             */
/*   Updated: 2023/01/25 01:00:46 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_address(size_t num)
{
	char	*str;
	char	*ptr;
	size_t	temp;
	int		i;

	str = "0123456789abcdef";
	i = 1;
	temp = num;
	while (temp != 0)
	{
		i++;
		temp /= 16;
	}
	ptr = (char *)malloc((sizeof(char)) * i + 1);
	if (ptr == 0)
		return (0);
	ptr[i + 1] = 0;
	while (i > 1)
	{
		ptr[i--] = str[num % 16];
		num /= 16;
	}
	ptr[1] = 'x';
	ptr[0] = '0';
	return (ptr);
}
