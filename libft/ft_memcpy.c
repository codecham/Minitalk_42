/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:52:43 by dcorenti          #+#    #+#             */
/*   Updated: 2022/01/07 18:01:10 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	if (!dst && !src)
		return (0);
	i = 0;
	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	return (dst);
}
