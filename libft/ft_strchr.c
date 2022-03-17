/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:54:09 by dcorenti          #+#    #+#             */
/*   Updated: 2022/01/07 18:22:22 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tmp;

	i = 0;
	tmp = c;
	while (s[i] != '\0')
	{
		if (s[i] == tmp)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (!c)
		return ((char *)&s[i]);
	return (0);
}
