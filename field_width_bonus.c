/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:09:39 by pleander          #+#    #+#             */
/*   Updated: 2024/05/15 16:17:35 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf_bonus.h"

static char	get_padding_char(t_fspec *s)
{
	if (s->zero_padding && !s->has_dot && !s->negative_field_width)
		return ('0');
	else
		return (' ');
}

char	*apply_field_width(t_fspec *s, char *data)
{
	size_t	data_len;
	char	*padding;
	char	*padded_data;

	data_len = ft_strlen(data);
	if (data_len > s->min_field_width)
		return (data);
	padding = ft_calloc(s->min_field_width - data_len + 1, sizeof(char));

	ft_memset(padding, (int)get_padding_char(s), s->min_field_width - data_len);
	if (s->negative_field_width)
		padded_data = ft_strjoin(data, padding);
	else
		padded_data = ft_strjoin(padding, data);
	free(padding);
	free(data);
	if (!padded_data)
		return (NULL);
	float_sign(padded_data);
	if (get_padding_char(s) == '0')
		float_space(padded_data);
	return (padded_data);

}

