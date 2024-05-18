/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:15:27 by pleander          #+#    #+#             */
/*   Updated: 2024/05/18 15:49:30 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_bonus.h"
#include "libft/libft.h"

char	*apply_space_before_pos(t_fspec *s, char *num)
{
	char	*padded_num;

	if (!s->space_before_pos || s->plus_before_pos)
		return (num);
	if (ft_strchr(num, '-'))
		return (num);
	padded_num = ft_strjoin(" ", num);
	free(num);
	if (!padded_num)
		return (NULL);
	return (padded_num);
}
