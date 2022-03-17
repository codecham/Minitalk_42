/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:47:30 by dcorenti          #+#    #+#             */
/*   Updated: 2022/02/04 14:24:54 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_pointer(unsigned long long p)
{
	char	*str;
	int		char_count;

	char_count = 0;
	char_count = ft_putstr("0x");
	str = ft_itoa_hexa(p, 0);
	char_count += ft_putstr(str);
	if (str)
		free(str);
	return (char_count);
}
