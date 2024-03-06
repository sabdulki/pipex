/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:36:04 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/06 16:24:25 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
#include <errno.h>
# include "./parse/parse.h"
// # include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

//find command
char	*find_command(char *cmd, char **envp);
char	*check_if_cmd_exists(char **path_arr, char *cmd);
int		if_path_to_cmd(char *path_line);
char	*add_cmd_to_line_in_path(char *line, char *cmd);

#endif