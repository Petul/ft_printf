/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:56:06 by pleander          #+#    #+#             */
/*   Updated: 2024/05/07 09:53:10 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	print_char(int data)
{
	if (write(STDOUT, &data, 1) < 0)
		return (-1);
	return (1);
}

int	print_string(char *data)
{
	int	i;

	if (data == NULL)
		return (print_string(NULL_STR));
	i = 0;
	while (data[i])
	{
		if (print_char(data[i]) < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	print_pointer(char *data)
{
	char	*num;
	char	*str;
	int		i;

	num = ft_ultoa_base((size_t)data, BASE_HEX_LOWER);
	if (!num)
		return (-1);
	str = ft_strjoin("0x", num);
	free(num);
	if (!str)
		return (-1);
	i = print_string(str);
	free(str);
	if (i < 0)
		return (-1);
	return (i);
}

int	print_decimal(int data)
{
	char	*num;
	int		i;

	num = ft_itoa(data);
	if (!num)
		return (-1);
	i = print_string(num);
	free(num);
	return (i);
}

int	print_uint(unsigned int data)
{
	char	*num;
	int		i;

	num = ft_utoa_base(data, BASE_DEC);
	if (!num)
		return (-1);
	i = print_string(num);
	free(num);
	return (i);
}
