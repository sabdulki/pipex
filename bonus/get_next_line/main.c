/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:46:42 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/26 15:25:56 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{ 
	int fd;

	fd = open("./text.txt", O_RDONLY);
	char *line = get_next_line(fd); //stdin
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	close(fd);
}
