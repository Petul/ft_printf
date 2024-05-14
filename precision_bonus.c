/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:42:12 by pleander          #+#    #+#             */
/*   Updated: 2024/05/10 16:12:40 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf_bonus.h"

static char	*increase_num_len(size_t precision, size_t padding, size_t base_num_len, char *num)
{
	char	*new_num;
	char	*zeros;

	zeros = ft_calloc(precision - base_num_len - padding, sizeof(char));
	if (!zeros)
	{
		free(num);
		return (NULL);
	}
	ft_memset(zeros, '0', precision - base_num_len - padding);
	new_num = ft_strjoin(zeros, num);
	if (!new_num)
	{
		free(num);
		free(zeros);
		return (NULL);
	}
	free(num);
	free(zeros);
	num = new_num;
	return (num);
}


char	*apply_precision(t_fspec *s, char *num)
{
	size_t	padding;
	size_t	base_num_len;
	BOOL	sign;

	sign = ft_strchr(num, '-') != 0;
	padding = 0;
 	while (!ft_strchr("-123456789", num[padding]) && num[padding])
 	 	padding++;
	base_num_len = ft_strlen(num + padding) - sign;
	if ((int)(s->precision - base_num_len) > (int)padding)
	{
		num = increase_num_len(s->precision, padding, base_num_len, num);
		if (!num)
			return (NULL);
	}
	if ((int)(s->precision -  base_num_len) > 0)
	{
		ft_memset(num + ft_strlen(num) - sign - s->precision, '0', s->precision - base_num_len);
		float_sign(num);
	}
	return (num);
}

