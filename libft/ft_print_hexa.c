/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:43:09 by dcorenti          #+#    #+#             */
/*   Updated: 2022/02/04 14:24:46 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_hexa(unsigned int nbr, int type)
{
	char	*str;
	int		char_count;

	char_count = 0;
	str = ft_itoa_hexa(nbr, type);
	char_count = ft_putstr(str);
	if (str)
		free(str);
	return (char_count);
}
