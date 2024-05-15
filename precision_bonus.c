/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:42:12 by pleander          #+#    #+#             */
/*   Updated: 2024/05/15 15:59:52 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf_bonus.h"

char	*apply_precision(t_fspec *s, char *num)
{
	size_t	base_num_len;
	char	*pre;
	char	*new_num;
	int		has_sign;

	has_sign = ft_strchr(num, '-') != NULL;
	base_num_len = ft_strlen(num) - has_sign;
	if (s->precision > base_num_len)
	{
		pre = ft_calloc(s->precision - base_num_len + 1, sizeof(char));
		if (!pre)
			return (NULL);
		ft_memset(pre, '0', s->precision - base_num_len);
		new_num = ft_strjoin(pre, num);
		free(pre);
		free(num);
		if (!new_num)
			return (NULL);
		num = new_num;
	}
	 if (ft_strncmp(num, "0", ft_strlen(num)) == 0 && s->has_dot && !s->precision)
		*num = 0;
	float_sign(num);
	return (num);
}
