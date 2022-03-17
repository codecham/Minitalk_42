/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:29:43 by dcorenti          #+#    #+#             */
/*   Updated: 2022/02/04 14:24:39 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_size(long nb)
{
	int	i;

	i = 1;
	while (nb / 10)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

static void	ft_fill_tab(char *tab, long div, long nb, int i)
{
	while (div)
	{
		tab[i] = (nb / div) + '0';
		nb = nb % div;
		div = div / 10;
		i++;
	}
	tab[i] = '\0';
}

char	*ft_itoa_unsigned(unsigned long long nb)
{
	int		size;
	int		i;
	long	div;
	char	*tab;

	size = ft_size(nb);
	i = 0;
	div = 1;
	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (NULL);
	while (nb / div > 9)
		div = div * 10;
	ft_fill_tab(tab, div, nb, i);
	return (tab);
}
