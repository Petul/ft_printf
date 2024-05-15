/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:57:20 by pleander          #+#    #+#             */
/*   Updated: 2024/05/15 08:57:23 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include "ft_printf_bonus.h"
#include "libft/libft.h"

size_t	get_format_len(char *fstart, char *format)
{
	size_t	len;

	len = 0;
	if (fstart[len + 1] == '%')
	{
		*format = '%';
		return (1);
	}
	while (!ft_isalpha(fstart[len]))
		len++;
	*format = fstart[len];
	return (len);
}

BOOL	process_fspec(char *fstart, va_list *args, size_t *loc, size_t *written)
{
	char	format;
	size_t	flen;
	BOOL	t;

	t = TRUE;
	flen = get_format_len(fstart, &format);
	if (format == 'c')
		t = convert_char(fstart, flen, va_arg(*args, int), written);
	else if (format == 's')
		t = convert_string(fstart, flen, va_arg(*args, char *), written);
	else if (format == 'p')
	 	t = convert_pointer(fstart, flen, va_arg(*args, void *), written);
	else if (format == 'd' || format == 'i')
	 	t = convert_decimal(fstart, flen, va_arg(*args, int), written);
	else if (format == 'u')
	 	t = convert_unsigned(fstart, flen, va_arg(*args, unsigned int), written);
	else if (format == 'X')
		t = convert_hex_upper(fstart, flen, va_arg(*args, int), written);
	else if (format == 'x')
		t = convert_hex_lower(fstart, flen, va_arg(*args, int), written);
	else if (format == '%')
	 	t = print_char('%', written);
	*loc += flen + 1;
	return (t);
}

int	ft_printf(const char *fstring, ...)
{
	va_list	args;
	size_t	loc;
	size_t	written;
	BOOL	t;

	va_start(args, fstring);
	written = 0;
	loc = 0;
	while (loc < ft_strlen(fstring))
	{
		if (fstring[loc] == '%')
		{
			t = process_fspec((char *)fstring + loc, &args, &loc, &written);
			if (t == FALSE)
				return (-1);
			continue ;
		}
		if (print_char(fstring[loc++], &written) == FALSE)
			return (-1);
	}
	va_end(args);
	return (written);
}
