/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:10:11 by cestevez          #+#    #+#             */
/*   Updated: 2023/01/31 00:51:50 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_places(size_t temp);

char	*print_address(size_t num)
{
	char	*str;
	char	*ptr;
	int		i;

	str = "0123456789abcdef";
	i = 2 + count_places(num);
	if (num == 0)
		return (0);
	ptr = (char *)malloc((sizeof(char)) * i + 1);
	if (ptr == 0)
		return (0);
	ptr[i] = 0;
	while (--i > 1)
	{
		ptr[i] = str[num % 16];
		num /= 16;
	}
	ptr[1] = 'x';
	ptr[0] = '0';
	return (ptr);
}

int	count_places(size_t temp)
{
	int	i;

	i = 0;
	while (temp != 0)
	{
		i++;
		temp /= 16;
	}
	return (i);
}
