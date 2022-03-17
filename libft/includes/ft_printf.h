/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:09:09 by dcorenti          #+#    #+#             */
/*   Updated: 2022/02/04 14:23:32 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *input, ...);
int		ft_type_list(char c);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_print_var(char type, va_list args);
int		ft_print_int(int nbr);
int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_hexa(unsigned int nbr, int type);
int		ft_print_pointer(unsigned long long p);
int		ft_print_unsigned_int(unsigned int nbr);
int		ft_print_pourcent(void);
char	*ft_itoa_hexa(unsigned long long nbr, int type);
char	*ft_itoa_unsigned(unsigned long long nb);

#endif