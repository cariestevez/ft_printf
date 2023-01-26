/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:11:33 by cestevez          #+#    #+#             */
/*   Updated: 2023/01/26 19:48:00 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int n)
{
	char	num;
	int		len;

	len = 0;
	if (n >= 10)
		len += print_unsigned(n / 10);
	num = (n % 10) + 48;
	len += write(1, &num, 1);
	return (len);
}
