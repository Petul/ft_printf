/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:57:58 by pleander          #+#    #+#             */
/*   Updated: 2024/05/18 17:39:14 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define STDOUT 1
# define BASE_DEC "0123456789"
# define BASE_HEX_UPPER "0123456789ABCDEF"
# define BASE_HEX_LOWER "0123456789abcdef"
# define NULL_STR "(null)"

int		ft_printf(const char *fstring, ...);
int		print_char(int data);
int		print_string(char *data);
int		print_pointer(char *data);
int		print_decimal(int data);
int		print_uint(unsigned int data);
int		print_hex_lower(int data);
int		print_hex_upper(int data);
char	*ft_utoa_base(unsigned int n, char *base);
char	*ft_ultoa_base(unsigned long n, char *base);

#endif
