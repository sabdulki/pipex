/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:36:04 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/15 18:42:47 by sabdulki         ###   ########.fr       */
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
	// int					*pipe_in;
	// int					*pipe_out;
	int					*connection;
	struct s_cmd_info	*next;
}	t_cmd_info;

//find command
int			if_path_to_cmd(char *path_line);
int			ft_file_fd(t_cmd_info *cmd, char *file, int cmd_index, int ac);
char		*find_command(char *cmd, char **envp);
char		*check_if_cmd_exists(char **path_arr, char *cmd);
char		*add_cmd_to_line_in_path(char *line, char *cmd);
t_cmd_info	*init_cmd_info(char **envp, char *cmd);
void		free_cmd(t_cmd_info *cmd);
char		**cmd_to_execute(char *cmd);
int			free_list(t_cmd_info *cmd_list);
t_cmd_info	*main_process(int ac, char **av, char **envp);
t_cmd_info	*add_cmd_to_list(t_cmd_info *cmd, t_cmd_info *head);
char		*find_command(char *cmd, char **envp);

//execution
int		execute_cmd(t_cmd_info *cmd);
int		wait_cmds(t_cmd_info *cmd_head);
int		*redirect_fd(int *pfd, t_cmd_info *cmd);

#endif