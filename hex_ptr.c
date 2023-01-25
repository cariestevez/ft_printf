/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:09:53 by cestevez          #+#    #+#             */
/*   Updated: 2023/01/25 00:34:53 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_ptr(char *ptr, int i, int j, unsigned int num)
{
	char	*str;

	str = "0123456789abcdef";
	if (num == 0)
	{
		ptr[j] = 0;
		ptr[j - 1] = num + 48;
	}
	if (num != 0)
	{
		ptr[i] = 0;
		while (i >= 0)
		{
			ptr[i - 1] = str[num % 16];
			num /= 16;
			i--;
		}
	}
	return (ptr);
}
