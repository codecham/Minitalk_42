/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 04:28:32 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/04 04:29:57 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk_bonus.h"

int	pow_tow(int pow)
{
	int	result;

	result = 1;
	while (pow > 0)
	{
		result = result * 2;
		pow--;
	}
	return (result);
}
