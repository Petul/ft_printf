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

char	*apply_precision(t_fspec *s, char *num)
{
	size_t	precision;
	size_t	num_len;
	size_t	padding;
	int		missing_space;
	char	*extra;
	char	*new_num;

	padding = 0;
	precision = 0;
	while (!ft_strchr("123456789", *num) && *num)
	{
		padding++;
		if (*num == '0')
			precision++;
		num++;
	}
	num -= padding;
	if (precision >= s->precision)
		return (num);
	num_len = ft_strlen(num);
	missing_space = (s->precision - precision) - padding;
	if (missing_space > 0)
	{
		extra = ft_calloc(missing_space + 1, sizeof(char));
		if (!extra)
		{
			free(num);
			return (NULL);
		}
		ft_memset(extra, '0', missing_space);
		new_num = ft_strjoin(extra, num);
		free(num);
		if (!new_num)
			return (NULL);
		num = new_num;
	}
	ft_memset(num + padding - (s->precision - ft_strlen(num + padding)), '0', s->precision - ft_strlen(num + padding));
	return (num);
}
