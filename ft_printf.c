#include <stdarg.h>
#include <stdio.h>

int	count_args(const char *fstring)
{
	int	count;

	count = 0;
	while (*fstring)
	{
		if (*fstring == '%')
		{
			count++;
			if (*(fstring + 1) == '%')
				fstring++;
		}
	fstring++;
	}
	return (count);
}

int ft_printf(const char *fstring, ...)
{
	va_list	args;

	printf("N_args: %d\n", count_args(fstring));
	va_start(args, fstring);

	va_end(args);

	return (0);
}
