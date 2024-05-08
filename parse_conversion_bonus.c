/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:04:25 by pleander          #+#    #+#             */
/*   Updated: 2024/05/08 16:25:14 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include "ft_printf_bonus.h"
#include "libft/libft.h"

static ssize_t get_field_width(char *conversion);
static ssize_t get_precision(char *conversion);
static BOOL get_zero_padding(char *conversion);
static void *free_and_return_null(t_fspec *s);

t_fspec	*parse_conversion(char *conversion)
{
	t_fspec *s;
	ssize_t field_width;
	ssize_t precision;

	s = malloc(sizeof(t_fspec));
	ft_bzero(s, sizeof(t_fspec));
	if (ft_strchr(conversion, '#'))
		s->alternate_form = TRUE;
	if (ft_strchr(conversion, '0'))
		s->zero_padding = get_zero_padding(conversion);
	if (ft_strchr(conversion, '-'))
		s->negative_field_width = TRUE;
	if (ft_strchr(conversion, ' '))
		s->space_before_pos = TRUE;
	if (ft_strchr(conversion, '+'))
		s->space_before_signed = TRUE;
	field_width = get_field_width(conversion);
	if (field_width < 0)
		free_and_return_null(s);
	s->min_field_width = field_width;
	precision = get_precision(conversion);
	if (precision < 0)
		free_and_return_null(s);
	s->precision = precision;
	return (s);
}

static void *free_and_return_null(t_fspec *s)
{
	free(s);
	return (NULL);
}

static ssize_t get_field_width(char *conversion)
{
	size_t i;
	size_t j;
	ssize_t num;
	char	*numstr;

	i = 0;
	j = 0;
	while (conversion[i] && conversion[i] != '.')
	{
		if (ft_strchr("123456789", conversion[i]))
		{
			while (i + j < ft_strlen(conversion) && ft_strchr("0123456789", conversion[i + j]))
				j++;
			numstr = ft_substr(conversion, i, j);
			if (!numstr)
				return (-1);
			num = ft_atoi(numstr);
			free(numstr);
			return (num);
		}
		i++;
	}
	return (0);
}

static ssize_t get_precision(char *conversion)
{
	char *dot;
	char *numstr;
	size_t i;
	size_t num;

	dot = ft_strchr(conversion, '.');
	if (!dot)
		return (0);
	i = 0;
	while (ft_isdigit(dot[i]))
		i++;	
	if (!i)
		return (0);
	numstr = ft_substr(dot, 0, i);
	if (!numstr)
		return (-1);
	num = ft_atoi(numstr);
	free(numstr);
	return (num);
}

static BOOL get_zero_padding(char *conversion)
{
	while (*conversion)
	{
		if (ft_isdigit(*conversion))
		{
			if (*conversion == 0)
				return (TRUE);
			return (FALSE);
		}
		conversion++;
	}
	return (FALSE);
}
