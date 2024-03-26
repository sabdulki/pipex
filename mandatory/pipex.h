/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:36:04 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/26 20:33:18 by sabdulki         ###   ########.fr       */
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
# include <sys/stat.h>
# include "../src/libft/libft.h"
# include "../src/ft_printf/ft_printf.h"
# include "../src/src.h"

t_cmd_info	*main_process(int ac, char **av, char **envp);

//init
t_cmd_info	*init_all_cmds(int ac, char **av, char **envp);
t_cmd_info	*init_cmd_info(char **envp, char *cmd, int index);
t_cmd_info	*init_cmd(int ac, int counter, char **av, char **envp);
int			init(t_cmd_info *cmd_info, char *cmd, char**envp);
int			ft_file_fd(t_cmd_info *cmd, char *file, int cmd_index, int ac);

//pipes
int			*create_all_pipes(t_cmd_info *cmd_list);
int			close_free_pfd(int *pfd);

#endif