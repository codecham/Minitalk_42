/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:55:36 by dcorenti          #+#    #+#             */
/*   Updated: 2022/01/07 18:22:29 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	tmp;

	tmp = c;
	i = 0;
	while (s[i])
		i++;
	if (!c)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == tmp)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
