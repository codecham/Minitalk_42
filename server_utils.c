/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:45:54 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/04 04:27:46 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

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
