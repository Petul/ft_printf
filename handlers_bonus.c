/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:56:06 by pleander          #+#    #+#             */
/*   Updated: 2024/05/08 16:22:48 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf_bonus.h"
#include "libft/libft.h"
#include "ft_printf.h"

static int	free_and_return(t_fspec *s)
{
	free(s);
	return (-1);
}
#include <stdio.h>
int	convert_char(char *fstr, size_t len, int data)
{
	t_fspec *s;
	char *conversion;
	ssize_t t;
	ssize_t written;

	conversion = ft_substr(fstr, 0, len);
	if (!conversion)
		return (-1);
	written = 0;
	s = parse_conversion(conversion);
	if (s->negative_field_width == FALSE)
	{
		if (s->min_field_width > 1)
		{
			t = print_nchars(' ', s->min_field_width - 1);
			if (t < 0)
				free_and_return(s);
			written += t;
		}
	}
	t = print_char(data);
	if (t < 0)
		free_and_return(s);
	free(s);
	written += t;
	return (written);
}

int	print_pointer(char *data)
{
	char	*num;
	char	*str;
	int		i;

	num = ft_ultoa_base((size_t)data, BASE_HEX_LOWER);
	if (!num)
		return (-1);
	str = ft_strjoin("0x", num);
	free(num);
	if (!str)
		return (-1);
	i = print_string(str);
	free(str);
	if (i < 0)
		return (-1);
	return (i);
}

int	print_decimal(int data)
{
	char	*num;
	int		i;

	num = ft_itoa(data);
	if (!num)
		return (-1);
	i = print_string(num);
	free(num);
	return (i);
}

int	print_uint(unsigned int data)
{
	char	*num;
	int		i;

	num = ft_utoa_base(data, BASE_DEC);
	if (!num)
		return (-1);
	i = print_string(num);
	free(num);
	return (i);
}
