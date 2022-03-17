/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:54:40 by dcorenti          #+#    #+#             */
/*   Updated: 2022/01/06 22:40:50 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	unsigned int	i;
// 	unsigned int	j;
// 	unsigned int	cpt;

// 	i = 0;
// 	j = 0;
// 	cpt = 0;
// 	while (dst[i] && i < size)
// 		i++;
// 	while (src[j])
// 		j++;
// 	cpt = i + j;
// 	if (i == size)
// 		return (cpt);
// 	j = 0;
// 	while (src[j] && (i + j) < (size - 1))
// 	{
// 		dst[i + j] = src[j];
// 		j++;
// 	}
// 	dst[i + j] = '\0';
// 	return (cpt);
// }

static size_t	len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	size_t	rslt;
	size_t	y;

	len_dst = len(dst);
	len_src = len(src);
	rslt = 0;
	i = 0;
	if (dstsize > len_dst)
		rslt = len_src + len_dst;
	else
		rslt = len_src + dstsize;
	y = len_dst;
	while (src[i] && (y + 1) < dstsize)
	{
		dst[y] = src[i];
		i++;
		y++;
	}
	dst[y] = '\0';
	return (rslt);
}
