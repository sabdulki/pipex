/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:44:43 by sabdulki          #+#    #+#             */
/*   Updated: 2023/08/04 17:57:04 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_uint(unsigned int num)
{
	int	i;

	i = 0;
	if (num > 9)
		i += ft_put_uint(num / 10);
	i += ft_putchar(num % 10 + '0');
	return (i);
}
