/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:48:45 by pleander          #+#    #+#             */
/*   Updated: 2024/05/15 13:31:49 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf_bonus.h"

BOOL	print_char(int data, size_t *written)
{
	if (write(STDOUT, &data, 1) < 0)
		return (FALSE);
	*written += 1;
	return (TRUE);
}

BOOL print_nchars(int c, size_t n, size_t *written)
{
	size_t i;
	i = 0;

	while(i < n)
	{
		if (print_char(c, written) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

BOOL	print_string(char *data, size_t n, size_t *written)
{
	size_t	i;

	// if (data == NULL)
	// 	return (print_string(NULL_STR, ft_strlen(NULL_STR), written));
	i = 0;
	while (data[i] && i < n)
	{
		if (print_char(data[i], written) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

BOOL	print_pointer(char *addr, size_t *written)
{
	char	*str;

	if (!addr)
		return (FALSE);
	str = ft_strjoin("0x", addr);
	if (!str)
		return (FALSE);
	if (print_string(str, ft_strlen(str), written) == FALSE)
	{
		free(str);
		return (FALSE);
	}
	free(str);
	return (TRUE);
}

char	*add_padding(t_fspec *s, char *data)
{
	char	spacing_char;
	char	*padding;
	char	*new_data;
	int		padding_amount;
	size_t	data_len;

	data_len = ft_strlen(data);
	padding_amount =  s->min_field_width - data_len;
	if (padding_amount < 1)
		return (data);
	spacing_char = ' ';
	if (s->zero_padding)
		spacing_char = '0';
	padding = ft_calloc(padding_amount + 1, sizeof(char));
	ft_memset(padding, spacing_char, padding_amount);
	if (s->negative_field_width)
		new_data = ft_strjoin(data, padding);
	else
		new_data = ft_strjoin(padding, data);
	free(padding);
	free(data);
	if (!new_data)
		return (NULL);
	float_sign(new_data);
	return (new_data);
}	

BOOL	print_padding(t_fspec *s, size_t *written, size_t word_len)
{
	char	spacing_char;
	int		padding_amount;

	padding_amount =  s->min_field_width - word_len;
	if (padding_amount < 1)
		return (TRUE);
	spacing_char = ' ';
	if (s->zero_padding)
		spacing_char = '0';
	if (print_nchars(spacing_char, padding_amount, written) == FALSE)
		return (FALSE);
	return (TRUE);
}
