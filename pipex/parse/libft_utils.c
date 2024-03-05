/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:36:27 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/05 22:09:26 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// @brief 
/// @param s1 first string
/// @param s2 
/// @param n 
/// @return 
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			res = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (res);
		}
		i++;
	}
	if (n != i)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}
