/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:00:35 by sabdulki          #+#    #+#             */
/*   Updated: 2023/08/06 16:10:33 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(const char *format, va_list arg)
{
	if (*(format) == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (*(format) == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (*(format) == 'p')
		return (ft_put_pointer(va_arg(arg, unsigned long long)));
	if (*(format) == 'd' || *(format) == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (*(format) == 'u')
		return (ft_put_uint(va_arg(arg, unsigned int)));
	if (*(format) == 'x')
		return (ft_put_hex_low(va_arg(arg, unsigned int)));
	if (*(format) == 'X')
		return (ft_put_hex_up(va_arg(arg, unsigned int)));
	if (*(format) == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		chars;

	va_start(arg, format);
	chars = 0;
	i = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			chars += ft_type(&format[i + 1], arg);
			i++;
		}
		else
			chars += ft_putchar(format[i]);
		i++;
	}
	va_end (arg);
	return (chars);
}

// int main(void)
// {
// 	// const char *arr = "hello";
// 	int num = 10;
// 	// char ch = 'a';
// 	// unsigned int ui = -429;
// 	// unsigned int hex_low = 0x213FBA;
// 	// int* ptr = &num;
// 	int res = ft_printf("%i\n", num);
// 	printf("Mine res: %d\n", res);
// 	int orig_res = printf("%i\n", num);
// 	printf("syst res: %d\n", orig_res);
// 	// (Строка - %s, char - %c, число - %d\n", arr, ch, num);
// }