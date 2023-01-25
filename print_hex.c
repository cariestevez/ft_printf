/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:10:50 by cestevez          #+#    #+#             */
/*   Updated: 2023/01/25 20:11:00 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_hex(unsigned int num, const char c)
{
	int				i;
	int				j;
	char			*ptr;
	unsigned int	temp;

	i = 0;
	j = 0;
	temp = num;
	while (temp != 0)
	{
		i++;
		temp /= 16;
	}
	if (temp == 0)
		j = 1;
	ptr = (char *)malloc(sizeof(char) * (i + j) + 1);
	if (ptr == 0)
		return (0);
	ptr = hex_ptr(ptr, i, j, num);
	if (c == 'X')
		ptr = toupper_printf(ptr);
	return (ptr);
}
