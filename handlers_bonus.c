/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:56:06 by pleander          #+#    #+#             */
/*   Updated: 2024/05/15 16:20:51 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf_bonus.h"
#include "libft/libft.h"
#include "ft_printf.h"

static int	free_and_return_false(t_fspec *s, char *num)
{
	if (s != NULL)
		free(s);
	if (num != NULL)
		free(num);
	return (FALSE);
}

BOOL	convert_char(char *fstr, size_t len, int data, size_t *written)
{
	t_fspec *s;
	char *conversion;

	conversion = ft_substr(fstr, 0, len);
	if (!conversion)
		return (FALSE);
	s = parse_conversion(conversion);
	free(conversion);
	if (s->negative_field_width == FALSE)
		if (print_padding(s, written, 1) == FALSE)
			free_and_return_false(s, NULL);
	if (print_char(data, written) == FALSE)
		free_and_return_false(s, NULL);
	if (s->negative_field_width == TRUE)
		if (print_padding(s, written, 1) == FALSE)
			free_and_return_false(s, NULL);
	free(s);
	return (TRUE);
}

BOOL	convert_string(char *fstr, size_t len, char *data, size_t *written)
{
	t_fspec	*s;
	char	*conversion;
	size_t	data_len;
	
	if (data == NULL)
		data = NULL_STR;
	conversion = ft_substr(fstr, 0, len);
	if (!conversion)
		return (FALSE);
	s = parse_conversion(conversion);
	free(conversion);
	data_len = ft_strlen(data);
	if (s->has_dot && s->precision < ft_strlen(data))
		data_len = s->precision;
	if (s->negative_field_width == FALSE)
		if (print_padding(s, written, data_len) == FALSE)
			free_and_return_false(s, NULL);
	if (print_string(data, data_len, written) == FALSE)
		free_and_return_false(s, NULL);
	if (s->negative_field_width == TRUE)
		if (print_padding(s, written, data_len) == FALSE)
			free_and_return_false(s, NULL);
	free(s);
	return (TRUE);
}

BOOL	convert_pointer(char *fstr, size_t len, char *data, size_t *written)
{
	t_fspec *s;
	char	*conversion;
	char	*num;

	conversion = ft_substr(fstr, 0, len);
	if (!conversion)
		return (FALSE);
	s = parse_conversion(conversion);
	free(conversion);
	conversion = NULL;
	num = ft_ultoa_base((size_t)data, BASE_HEX_LOWER);
	if (!num)
		free_and_return_false(s, NULL);
	if (s->negative_field_width == FALSE)
		if (print_padding(s, written, ft_strlen(num) + 2) == FALSE) //Add 2 for len of "0x"
			free_and_return_false(s, num);
	if (print_pointer(num, written) == FALSE)
		free_and_return_false(s, num);
	if (s->negative_field_width == TRUE)
		if (print_padding(s, written, ft_strlen(num) + 2) == FALSE)
			free_and_return_false(s, num);
	free(s);
	free(num);
	return (TRUE);
}

BOOL	convert_decimal(char *fstr, size_t len, int data, size_t *written)
{
	t_fspec *s;
	char	*conversion;
	char	*num;

	conversion = ft_substr(fstr, 0, len);
	if (!conversion)
		return (FALSE);
	s = parse_conversion(conversion);
	free(conversion);
	num = ft_itoa(data);
	num = apply_precision(s, num);
	num = apply_plus(s, num);
	num = apply_space_before_pos(s, num);
	num = apply_field_width(s, num);
	if (print_string(num, ft_strlen(num), written) == FALSE)
		free_and_return_false(s, num);
	free(num);
	free(s);
	return (TRUE);
}

BOOL	convert_unsigned(char *fstr, size_t len, unsigned int data, size_t *written)
{
	t_fspec *s;
	char	*conversion;
	char	*num;

	conversion = ft_substr(fstr, 0, len);
	if (!conversion)
		return (FALSE);
	s = parse_conversion(conversion);
	free(conversion);
	num = ft_utoa_base(data, BASE_DEC);
	num = apply_precision(s, num);
	num = apply_field_width(s, num);
	if (print_string(num, ft_strlen(num), written) == FALSE)
		free_and_return_false(s, num);
	free(num);
	free(s);
	return (TRUE);
}

static char	*convert_hex(t_fspec *s, int data, char *base)
{
	char	*num;

	num = ft_utoa_base(data, base);
	if (s->alternate_form && (!only_zero_or_space(num)))
	{
		if (s->min_field_width < 2)
			s->min_field_width = 0;
		else
			s->min_field_width -= 2;
	}
	num = apply_precision(s, num);
	num = apply_field_width(s, num);
	if (!num)
		return (NULL);
	return (num);
}

BOOL	convert_hex_upper(char *fstr, size_t len, int data, size_t *written)
{
	t_fspec *s;
	char	*conversion;
	char	*num;

	conversion = ft_substr(fstr, 0, len);
	if (!conversion)
		return (FALSE);
	s = parse_conversion(conversion);
	free(conversion);
	num = convert_hex(s, data, BASE_HEX_UPPER);
	if (!num)
		return (FALSE);
	if (!only_zero_or_space(num))
		num = apply_alternate_hex_form(s, num, "0X");
	if (print_string(num, ft_strlen(num), written) == FALSE)
		free_and_return_false(s, num);
	free(num);
	free(s);
	return (TRUE);
}

BOOL	convert_hex_lower(char *fstr, size_t len, int data, size_t *written)
{
	t_fspec *s;
	char	*conversion;
	char	*num;

	conversion = ft_substr(fstr, 0, len);
	if (!conversion)
		return (FALSE);
	s = parse_conversion(conversion);
	free(conversion);
	num = convert_hex(s, data, BASE_HEX_LOWER);
	if (!num)
		return (FALSE);
	if (!only_zero_or_space(num))
		num = apply_alternate_hex_form(s, num, "0x");
	if (print_string(num, ft_strlen(num), written) == FALSE)
		free_and_return_false(s, num);
	free(num);
	free(s);
	return (TRUE);
}
