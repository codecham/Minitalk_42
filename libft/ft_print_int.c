/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:26:21 by dcorenti          #+#    #+#             */
/*   Updated: 2022/02/04 14:24:49 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_int(int nbr)
{
	char	*str;
	int		char_count;

	char_count = 0;
	str = ft_itoa(nbr);
	char_count = ft_putstr(str);
	if (str)
		free(str);
	return (char_count);
}
