/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:36:04 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/22 16:23:02 by sabdulki         ###   ########.fr       */
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
# include <sys/wait.h>
# include "./parse/parse.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_cmd_info{
	char				**cmd;
	char				*cmd_path;
	char				*cmd_rel; // 'i' - связать stdin с fd первого файла
									// 'o' - connect fd to the last file's fd
									// 'c' - connect with cmd
	char				**envp;
	int					status;
	int					file_fd;
	char				inout;
	int					index;
	int					*connection;
	struct s_cmd_info	*next;
}	t_cmd_info;

t_cmd_info	*main_process(int ac, char **av, char **envp);

//find command
int			if_path_to_cmd(char *path_line);
char		*find_command_path(char *cmd, char **envp);
char		*check_if_cmd_exists(char **path_arr, char *cmd);
char		*add_cmd_to_line_in_path(char *line, char *cmd);

//init
t_cmd_info	*add_cmd_to_list(t_cmd_info *cmd, t_cmd_info *head);
t_cmd_info	*init_all_cmds(int ac, char **av, char **envp);
t_cmd_info	*init_cmd(int ac, int counter, char **av, char **envp);
t_cmd_info	*init_cmd_info(char **envp, char *cmd, int index);
int			ft_file_fd(t_cmd_info *cmd, char *file, int cmd_index, int ac);
int			free_list(t_cmd_info *cmd_list);
int			free_cmd(t_cmd_info *cmd);
int			list_size(t_cmd_info *cmd_list);

//pipes
int			*create_all_pipes(t_cmd_info *cmd_list);

//execution
int			execute_all_cmds(t_cmd_info *cmd_list);
int			execute_cmd(t_cmd_info *cmd);
int			wait_cmds(t_cmd_info *cmd_head);

#endif