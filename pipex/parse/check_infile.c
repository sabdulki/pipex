/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:18:13 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/22 19:16:02 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_infile(char *infile)
{
	if (!infile || (open(infile,  O_RDONLY)) == -1)
	{
		ft_printf("file doesn't exist\n");
		return (0);
	}
	if (access(infile, R_OK) == -1) // i have no permission to read
	{
		ft_printf("no acces to file\n");
		return (0);
	}
	return (1);
}
