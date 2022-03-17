/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:21:06 by dcorenti          #+#    #+#             */
/*   Updated: 2022/02/04 14:25:08 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_var(char type, va_list args)
{
	int	char_count;

	char_count = 0;
	if (type == 'd' || type == 'i')
		char_count = ft_print_int(va_arg(args, int));
	if (type == 'c')
		char_count = ft_print_char(va_arg(args, int));
	if (type == 's')
		char_count = ft_print_string(va_arg(args, char *));
	if (type == 'x')
		char_count = ft_print_hexa(va_arg(args, unsigned int), 0);
	if (type == 'X')
		char_count = ft_print_hexa(va_arg(args, unsigned int), 1);
	if (type == 'p')
		char_count = ft_print_pointer(va_arg(args, unsigned long long));
	if (type == 'u')
		char_count = ft_print_unsigned_int(va_arg(args, unsigned int));
	if (type == '%')
		char_count = ft_print_pourcent();
	return (char_count);
}
