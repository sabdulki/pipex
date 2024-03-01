/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:00:35 by sabdulki          #+#    #+#             */
/*   Updated: 2023/08/04 18:36:19 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_long_hex_low(unsigned long long num)
{
	char	*str; 
	int		res;

	str = "0123456789abcdef";
	res = 0;
	if (num / 16 != 0)
		res += ft_put_long_hex_low(num / 16);
	return (res + ft_putchar(str[num % 16]));
}

int	ft_put_pointer(unsigned long long num)
{
	int	res;

	res = 0;
	res += ft_putstr("0x");
	res += ft_put_long_hex_low(num);
	return (res);
}
