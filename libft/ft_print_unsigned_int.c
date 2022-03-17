/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:57:54 by dcorenti          #+#    #+#             */
/*   Updated: 2022/02/04 14:25:05 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_unsigned_int(unsigned int nbr)
{
	char	*str;
	int		char_count;

	char_count = 0;
	str = ft_itoa_unsigned(nbr);
	char_count = ft_putstr(str);
	if (str)
		free (str);
	return (char_count);
}
