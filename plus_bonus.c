/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:58:17 by pleander          #+#    #+#             */
/*   Updated: 2024/05/15 15:31:20 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf_bonus.h"

char	*apply_plus(t_fspec *s, char *num)
{
	char	*new_num;

	if ((!s->plus_before_pos) || ft_strchr(num, '-'))
		return (num);
	new_num = ft_strjoin("+", num);
	free(num);
	return(new_num);
}
