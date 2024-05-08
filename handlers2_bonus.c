/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:08:38 by pleander          #+#    #+#             */
/*   Updated: 2024/05/07 14:17:14 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	print_hex_lower(int data)
{
	char	*num;
	int		i;

	num = ft_utoa_base(data, BASE_HEX_LOWER);
	if (!num)
		return (-1);
	i = print_string(num);
	free(num);
	return (i);
}

int	print_hex_upper(int data)
{
	char	*num;
	int		i;

	num = ft_utoa_base(data, BASE_HEX_UPPER);
	if (!num)
		return (-1);
	i = print_string(num);
	free(num);
	return (i);
}
