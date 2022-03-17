/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:07:02 by dcorenti          #+#    #+#             */
/*   Updated: 2022/02/04 14:25:12 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_treat_save(const char *input, va_list args)
{
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	while (1)
	{
		if (!input[i])
			break ;
		else if (input[i] == '%' && input[i + 1])
		{
			i++;
			if (ft_type_list(input[i]))
				char_count += ft_print_var(input[i], args);
			else if (input[i])
				char_count += ft_putchar(input[i]);
		}
		else if (input[i] != '%')
			char_count += ft_putchar(input[i]);
		i++;
	}
	return (char_count);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	int				char_count;

	char_count = 0;
	va_start(args, input);
	char_count = char_count + ft_treat_save(input, args);
	va_end(args);
	return (char_count);
}
