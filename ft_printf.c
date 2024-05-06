/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:57:20 by pleander          #+#    #+#             */
/*   Updated: 2024/05/06 16:54:39 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include "ft_printf.h"
#include "libft/libft.h"

size_t	get_format(char *fstart, char *format)
{
	size_t len;

	len = 0;
	while (!ft_isalpha(fstart[len]))
		len++;
	*format = fstart[len];
	return (len);
}

 size_t	process_fspec(char *fstart, va_list *args)
 {
	char format;
	size_t flen;

	flen = get_format(fstart, &format);
 	if (format == 'c')
		c_handler(ft_substr(fstart, 0, flen), va_arg(*args, int));
	return (flen + 1);
}

int ft_printf(const char *fstring, ...)
{
	va_list	args;
	size_t	loc;

	va_start(args, fstring);
	loc = 0;
	while (fstring[loc])
	{
		if (fstring[loc] == '%')
			loc += process_fspec((char *)fstring + loc, &args);
		ft_putchar_fd(fstring[loc], 1);
		loc++;
	}
	va_end(args);

	return (0);
}
