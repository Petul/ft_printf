/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:50:20 by pleander          #+#    #+#             */
/*   Updated: 2024/05/16 16:18:29 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf_bonus.h"
#include "libft/libft.h"
#include "ft_printf.h"

t_fspec	*parse_fspec(char *fstr, size_t len)
{
	char	*conversion;
	t_fspec *s;

	conversion = ft_substr(fstr, 0, len);
	if (!conversion)
		return (NULL);
	s = parse_conversion(conversion);
	free(conversion);
	return (s);
}

static int	free_and_return_false(t_fspec *s, char *num)
{
	if (s != NULL)
		free(s);
	if (num != NULL)
		free(num);
	return (FALSE);
}

t_bool	convert_char(char *fstr, size_t len, int data, size_t *written)
{
	t_fspec *s;
	char	*str;

	s = parse_fspec(fstr, len);
	if (!s)
		return (FALSE);
	str = ft_calloc(2, sizeof(char));
	if (!str)
		return(free_and_return_false(s, NULL));
	str[0] = data;
	if (data == 0)
		if (s->min_field_width > 0)
		 	s->min_field_width -= 1;
	str = apply_field_width(s, str);
	if (!str)
		return(free_and_return_false(s, NULL));
	if (data == 0 && s->negative_field_width)
		if (print_char(data, written) == FALSE)
			return (free_and_return_false(s, str));
	if (print_string(str, ft_strlen(str), written) == FALSE)
		return (free_and_return_false(s, str));
	if (data == 0 && !s->negative_field_width)
		if (print_char(data, written) == FALSE)
			return (free_and_return_false(s, str));
	free(str);
	free(s);
	return (TRUE);
}

t_bool	convert_string(char *fstr, size_t len, char *data, size_t *written)
{
	t_fspec	*s;
	char	*str;
	
	if (data == NULL)
		data = NULL_STR;
	s = parse_fspec(fstr, len);
	if (!s)
		return (FALSE);
	str = calloc(ft_strlen(data) + 1, sizeof(char));
	if (!str)
		return (free_and_return_false(s, NULL));
	ft_memcpy(str, data, ft_strlen(data));
	str = apply_string_precision(s, str);
	if (!str)
		return (free_and_return_false(s, str));
	str = apply_field_width(s, str);
	if (!str)
		return (free_and_return_false(s, str));
	if (print_string(str, ft_strlen(str), written) == FALSE)
		return (free_and_return_false(s, str));
	free(str);
	free(s);
	return (TRUE);
}

t_bool	convert_pointer(char *fstr, size_t len, char *data, size_t *written)
{
	t_fspec *s;
	char	*num;

	s = parse_fspec(fstr, len);
	if (!s)
		return (FALSE);
	num = ft_ultoa_base((size_t)data, BASE_HEX_LOWER);
	if (!num)
		return (free_and_return_false(s, NULL));
	s->alternate_form = TRUE;
	num = apply_alternate_hex_form(s, num, "0x");
	if (!num)
		return (free_and_return_false(s, NULL));
	num = apply_field_width(s, num);
	if (!num)
		return (free_and_return_false(s, NULL));
	if (print_string(num, ft_strlen(num), written) == FALSE)
		return (free_and_return_false(s, num));
	free(s);
	free(num);
	return (TRUE);
}

t_bool	convert_decimal(char *fstr, size_t len, int data, size_t *written)
{
	t_fspec *s;
	char	*num;

	s = parse_fspec(fstr, len);
	if (!s)
		return (FALSE);
	num = ft_itoa(data);
	if (!num)
		return (free_and_return_false(s, NULL));
	num = apply_precision(s, num);
	if (!num)
		return (free_and_return_false(s, NULL));
	num = apply_plus(s, num);
	if (!num)
		return (free_and_return_false(s, NULL));
	num = apply_space_before_pos(s, num);
	if (!num)
		return (free_and_return_false(s, NULL));
	num = apply_field_width(s, num);
	if (!num)
		return (free_and_return_false(s, NULL));
	if (print_string(num, ft_strlen(num), written) == FALSE)
		return (free_and_return_false(s, num));
	free(num);
	free(s);
	return (TRUE);
}

t_bool	convert_unsigned(char *fstr, size_t len, unsigned int data, size_t *written)
{
	t_fspec *s;
	char	*num;

	s = parse_fspec(fstr, len);
	if (!s)
		return (FALSE);
	num = ft_utoa_base(data, BASE_DEC);
	if (!num)
		return (free_and_return_false(s, NULL));
	num = apply_precision(s, num);
	if (!num)
		return (free_and_return_false(s, NULL));
	num = apply_field_width(s, num);
	if (!num)
		return (free_and_return_false(s, NULL));
	if (print_string(num, ft_strlen(num), written) == FALSE)
		return (free_and_return_false(s, num));
	free(num);
	free(s);
	return (TRUE);
}

static char	*convert_hex(t_fspec *s, int data, char *base)
{
	char	*num;

	num = ft_utoa_base(data, base);
	if (!num)
		return (NULL);
	if (s->alternate_form && (!only_zero_or_space(num)))
	{
		if (s->min_field_width < 2)
			s->min_field_width = 0;
		else
			s->min_field_width -= 2;
	}
	num = apply_precision(s, num);
	if (!num)
		return (NULL);
	num = apply_field_width(s, num);
	if (!num)
		return (NULL);
	return (num);
}

t_bool	convert_hex_upper(char *fstr, size_t len, int data, size_t *written)
{
	t_fspec *s;
	char	*num;

	s = parse_fspec(fstr, len);
	if (!s)
		return (FALSE);
	num = convert_hex(s, data, BASE_HEX_UPPER);
	if (!num)
		return (free_and_return_false(s, NULL));
	if (!only_zero_or_space(num))
	{
		num = apply_alternate_hex_form(s, num, "0X");
		if (!num)
			return (free_and_return_false(s, NULL));
	}
	if (print_string(num, ft_strlen(num), written) == FALSE)
		return (free_and_return_false(s, num));
	free(num);
	free(s);
	return (TRUE);
}

t_bool	convert_hex_lower(char *fstr, size_t len, int data, size_t *written)
{
	t_fspec *s;
	char	*num;

	s = parse_fspec(fstr, len);
	if (!s)
		return (FALSE);
	num = convert_hex(s, data, BASE_HEX_LOWER);
	if (!num)
		return (free_and_return_false(s, NULL));
	if (!only_zero_or_space(num))
	{
		num = apply_alternate_hex_form(s, num, "0x");
		if (!num)
			return (free_and_return_false(s, NULL));
	}
	if (print_string(num, ft_strlen(num), written) == FALSE)
		return (free_and_return_false(s, num));
	free(num);
	free(s);
	return (TRUE);
}
