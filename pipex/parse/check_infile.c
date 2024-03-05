/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:18:13 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/05 22:07:56 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_infile(char *infile)
{
	if (!infile)
		return (1);
	if (access(infile, R_OK) != -1) // i have permission to read
		return (0);
	return (1);
}
