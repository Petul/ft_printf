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

void	float_sign(char *num)
{
	char	*sign;
	char	*zero;

	sign = ft_strchr(num, '-');
	zero = ft_strchr(num, '0');
	if (!sign || !zero)
		return ;
	*zero = '-';
	*sign = '0';
}
