/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:48:45 by pleander          #+#    #+#             */
/*   Updated: 2024/05/08 16:22:52 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_bonus.h"

int	print_char(int data)
{
	if (write(STDOUT, &data, 1) < 0)
		return (-1);
	return (1);
}
int	print_nchars(int c, size_t n)
{
	size_t i;
	i = 0;

	while(i < n)
	{
		if (write(STDOUT, &c, 1) < 0)
			return (-1);
		i++;
	}
	return (n);
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
