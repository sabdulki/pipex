/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:17:21 by sabdulki          #+#    #+#             */
/*   Updated: 2023/07/22 22:44:04 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = (size_t)ft_strlen(src);
	if (dstsize == 0)
		return (res);
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}

// int	main(void)
// {
// 	char dst[] = "12345";
// 	char src[] = "";

// 	printf("%lu\n", ft_strlcpy(dst, src, 2));
// 	printf("%s\n", dst);
// }