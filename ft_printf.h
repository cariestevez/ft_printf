/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_PRINTF.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:56:27 by cestevez          #+#    #+#             */
/*   Updated: 2023/01/25 00:05:12 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
int		print_char(char c);
int		print_string(char *s);
int		print_nbr(int n);
int		print_unsigned(unsigned int n);
char	*print_hex(unsigned int num, const char c);
char	*hex_ptr(char *ptr, int i, int j, unsigned int num);
char	*toupper_printf(char *s);
char	*print_address(size_t num);

#endif