/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:57:58 by pleander          #+#    #+#             */
/*   Updated: 2024/05/08 16:09:55 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

# define STDOUT 1
# define BASE_DEC "0123456789"
# define BASE_HEX_UPPER "0123456789ABCDEF"
# define BASE_HEX_LOWER "0123456789abcdef"
# define NULL_STR "(null)"
# define BOOL unsigned char 
# define TRUE 1
# define FALSE 0

typedef struct s_fspec
{
	BOOL alternate_form;
	BOOL zero_padding;
	BOOL negative_field_width;
	BOOL space_before_pos;
	BOOL space_before_signed;
	size_t min_field_width;
	size_t precision;
}	t_fspec;

int		ft_printf(const char *fstring, ...);
int		print_char(int data);
int		print_nchars(int c, size_t n);
int		print_string(char *data);
int		print_pointer(char *data);
int		print_decimal(int data);
int		print_uint(unsigned int data);
int		print_hex_lower(int data);
int		print_hex_upper(int data);
char	*ft_utoa_base(unsigned int n, char *base);
char	*ft_ultoa_base(unsigned long n, char *base);
t_fspec	*parse_conversion(char *conversion);
int		convert_char(char *fstr, size_t len, int data);

#endif
