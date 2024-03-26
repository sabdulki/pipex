/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:08:23 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/26 20:33:15 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_cmd_info
{
	char				**cmd;
	char				*cmd_path;
	char				**envp;
	int					status;
	int					file_fd;
	char				inout;
	int					index;
	int					*connection;
	struct s_cmd_info	*next;
}	t_cmd_info;

//init
t_cmd_info	*add_cmd_to_list(t_cmd_info *cmd, t_cmd_info *head);
int	free_cmd(t_cmd_info *cmd);
int	free_list(t_cmd_info *cmd_list);

//execution
int	execute_all_cmds(t_cmd_info *cmd_list);
int	execute_cmd(t_cmd_info *cmd);
int	wait_cmds(t_cmd_info *cmd_head);
int	list_size(t_cmd_info *cmd_list);

//find command
char	*find_command_path(char *cmd, char **envp);
char	*check_if_cmd_exists(char **path_arr, char *cmd);
int	if_path_to_cmd(char *path_line);
char	*add_cmd_to_line_in_path(char *line, char *cmd);

//parsing
int	check_infile(char *infile);
char	*find_path(char **envp);

#endif