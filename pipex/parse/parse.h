/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:57:18 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/05 22:00:57 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
// # include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

//check infile
int		check_infile(char *infile);

//parse path
char	**parse_path(char *path);
char	*find_path(char ** envp);

//parse cmd
char	*parse_cmd(char *cmd);
int		ft_cmd_len(char *cmd);

// libft utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *c);

#endif