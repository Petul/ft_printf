/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:57:58 by pleander          #+#    #+#             */
/*   Updated: 2024/05/15 16:12:42 by pleander         ###   ########.fr       */
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
//Change to typedef 
# define BOOL unsigned char
# define TRUE 1
# define FALSE 0

typedef struct s_fspec
{
	BOOL alternate_form;
	BOOL zero_padding;
	BOOL negative_field_width;
	BOOL space_before_pos;
	BOOL plus_before_pos;
	BOOL has_dot;
	size_t min_field_width;
	size_t precision;
}	t_fspec;

int		ft_printf(const char *fstring, ...);
BOOL	print_char(int data, size_t *written);
BOOL	print_nchars(int c, size_t n, size_t *written);
BOOL	print_string(char *data, size_t n, size_t *written);
BOOL	print_pointer(char *data, size_t *written);
int		print_decimal(int data);
int		print_uint(unsigned int data);
int		print_hex_lower(int data);
int		print_hex_upper(int data);
char	*ft_utoa_base(unsigned int n, char *base);
char	*ft_ultoa_base(unsigned long n, char *base);
t_fspec	*parse_conversion(char *conversion);
BOOL	convert_char(char *fstr, size_t len, int data, size_t *written);
BOOL	convert_string(char *fstr, size_t len, char *data, size_t *written);
BOOL	convert_pointer(char *fstr, size_t len, char *data, size_t *written);
BOOL	convert_decimal(char *fstr, size_t len, int data, size_t *written);
BOOL	print_padding(t_fspec *s, size_t *written, size_t word_len);
BOOL	convert_unsigned(char *fstr, size_t len, unsigned int data, size_t *written);
char	*add_padding(t_fspec *s, char *data);
char	*apply_precision(t_fspec *s, char *num);
void	float_sign(char *num);
char	*apply_plus(t_fspec *s, char *num);
BOOL	convert_hex_upper(char *fstr, size_t len, int data, size_t *written);
BOOL	convert_hex_lower(char *fstr, size_t len, int data, size_t *written);
char	*apply_alternate_hex_form(t_fspec *s, char *num, char *pre_str);
char	*apply_field_width(t_fspec *s, char *data);
int		only_zero_or_space(char *num);
char	*apply_space_before_pos(t_fspec *s, char *num);
void	float_space(char *num);
char	*apply_string_precision(t_fspec *s, char *str);

#endif
