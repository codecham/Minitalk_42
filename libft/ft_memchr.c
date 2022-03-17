/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:52:18 by dcorenti          #+#    #+#             */
/*   Updated: 2022/01/06 18:42:00 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;
	char		tmp;

	str = (const char *)s;
	i = 0;
	tmp = c;
	while (i < n)
	{
		if (str[i] == tmp)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
