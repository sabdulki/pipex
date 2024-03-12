/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:43:27 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/12 14:37:32 by sabdulki         ###   ########.fr       */
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
	int		status;
	int		file_fd;
	char	inout;
	t_cmd_info	*next;
}	t_cmd_info;

int		execute_cmd(t_cmd_info *cmd);

#endif