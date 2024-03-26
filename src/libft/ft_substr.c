/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:02:34 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/24 17:55:46 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *arr, unsigned int start, size_t len)
{
	char	*s_arr;
	size_t	arr_len;

	s_arr = "";
	if (arr == NULL)
		return (NULL);
	arr_len = ft_strlen(arr);
	if (start >= arr_len)
		len = 0;
	if (arr_len - start >= len)
		s_arr = malloc(sizeof(char) * len + 1);
	else if (len > arr_len - start)
		s_arr = malloc(sizeof(char) * (arr_len - start));
	if (s_arr == 0)
		return (0);
	if (len > 0)
		ft_strlcpy(s_arr, &arr[start], len + 1);
	else
		*s_arr = '\0';
	return (s_arr);
}

// int main(void)
// {
// 	char const *arr = "gryffindor";
// 	unsigned int start = 1;
// 	size_t len = 5;
// }