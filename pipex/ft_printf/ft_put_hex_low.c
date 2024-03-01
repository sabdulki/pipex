/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:04:17 by sabdulki          #+#    #+#             */
/*   Updated: 2023/08/04 17:56:22 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_low(unsigned int num)
{
	char	*str; 
	int		res;

	str = "0123456789abcdef";
	res = 0;
	if (num / 16 != 0)
		res += ft_put_hex_low(num / 16);
	return (res + ft_putchar(str[num % 16]));
}
