/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:43:27 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/07 19:59:38 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_cmd_info{
	char	*cmd;
	char	*cmd_path;
	char	*cmd_rel; // 'i' - связать stdin с fd первого файла
						// 'o' - connect fd to the last file's fd
						// 'c' - connect with cmd
	char	**envp;
}	t_cmd_info;

int		execute_cmd(char *cmd_path, char *cmd, char **envp);

#endif