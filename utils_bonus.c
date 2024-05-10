/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:53:54 by pleander          #+#    #+#             */
/*   Updated: 2024/05/10 15:03:21 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	move_sign_to_start(char *str)
{
	char *sign_pos;

	sign_pos = ft_strchr(str, '-');
	if (!sign_pos || sign_pos == str)
		return ;
	if (*(sign_pos - 1) == '0')
	{
		str[0] = '-';
		*sign_pos = '0';
	}
}
