/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:36:04 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/12 14:35:47 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include "./parse/parse.h"
# include "./execution/execution.h"
// # include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

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

typedef struct s_cmd_list {
	t_cmd_info	*cmd; //data
	int			cmd_index;
}	t_cmd_list;

//find command
int			if_path_to_cmd(char *path_line);
int			ft_file_fd(char *file, int counter, int ac);
char		*find_command(char *cmd, char **envp);
char		*check_if_cmd_exists(char **path_arr, char *cmd);
char		*add_cmd_to_line_in_path(char *line, char *cmd);
t_cmd_info	*init_cmd_info(char **envp, char *cmd, char inout);
#endif