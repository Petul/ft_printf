/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poundsign_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:17:43 by pleander          #+#    #+#             */
/*   Updated: 2024/05/15 11:47:18 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf_bonus.h"

char	*apply_alternate_hex_form(t_fspec *s, char *num, char *pre_str)
{
	size_t	i;
	char	*sub1;
	char	*sub2;
	char	*new_num;

	if (s->alternate_form == FALSE)
		return (num);
	i = 0;
	while(num[i] && !(ft_strchr(BASE_HEX_LOWER, num[i]) || ft_strchr(BASE_HEX_UPPER, num[i])))
		i++;
	sub1 = ft_substr(num, 0, i);
	if (!sub1)
		return (NULL);
	sub2 = ft_substr(num, i, ft_strlen(num) - i);
	if (!sub2)
	{
		free(sub1);
		return (NULL);
	}
	new_num = ft_strjoin(sub1, pre_str);
	free(sub1);
	if (!new_num)
	{
		free(sub1);
		free(sub2);
		return (NULL);
	}
	free(num);
	num = ft_strjoin(new_num, sub2);
	free(new_num);
	free(sub2);
	if (!num)
		return (NULL);
	return (num);
}


