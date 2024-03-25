/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:44:19 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/25 21:58:16 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_here_doc(char **av, int ac)
{
	int	fd;

	fd = -1;
	if (ft_strncmp(av[1], "here_doc", 9))
		fd = ft_here_doc(av[2], av[ac - 1]);
	return (fd);
}

int	ft_here_doc(char *limiter, char *file_name)
{
	char	input[100];
	int		fd;
	mode_t	mode;
	// char	dummy;

	// input = NULL;
	mode = S_IRUSR | S_IWUSR;
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, mode);
	while (1)
	{
		// ft_printf("input: %s", input);
		// ft_printf("pipe heredoc> ");
		// while ((getchar()) != '\n') //&& dummy != EOF)
		// 	scanf("%99[^\n]", input);
		// ft_putstr_fd(input, fd);
		printf("pipe heredoc> ");
        fflush(stdout); // Сбрасываем буфер вывода, чтобы увидеть приглашение на ввод

        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Очищаем буфер ввода

        if (fgets(input, sizeof(input), stdin) == NULL) { // Считываем строку с помощью fgets
            perror("fgets");
            return -1;
        }

        input[strcspn(input, "\n")] = '\0';
		write(fd, input, strlen(input));
		if (ft_strncmp(limiter, input, ft_strlen(limiter)))
			break;
		write(fd, "\n", 1);
	}
	return (fd);
}

