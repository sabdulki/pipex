/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:35:34 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/05 20:34:35 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac != 5)
		return (0);
	if (!check_infile(av[1]))
		return (0);
	if (!find_command(av[2], envp))
		return (0);
}