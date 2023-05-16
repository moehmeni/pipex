/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:16:51 by mmomeni           #+#    #+#             */
/*   Updated: 2023/05/16 20:12:52 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	read_lines(int fd[2], char **argv)
{
	char	*line;
	char	*end;

	end = ft_strjoin(argv[2], "\n");
	while (1)
	{
		line = get_next_line(0);
		if (!line || !ft_strncmp(line, end, ft_strlen(end)))
		{
			free(line);
			free(end);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
		free(end);
		line = NULL;
		end = NULL;
	}
}

int	here_doc(int fd[2], int argc, char **argv,
void (*run_pipes)(int[2], char **, int))
{
	int	output;

	pipe(fd);
	if (fork() == 0)
	{
		close(fd[0]);
		read_lines(fd, argv);
		exit(0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		output = open(argv[argc - 1], O_WRONLY | O_CREAT, 0666);
		if (output == -1)
			terminate("open output");
		dup2(output, 1);
		(*run_pipes)(fd, argv + 3, argc - 4);
	}
	close(output);
	close(fd[0]);
	close(fd[1]);
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd[2];
	int	input;
	int	output;

	if (argc < 4)
	{
		ft_putendl_fd("Invalid number of arguments", STDERR_FILENO);
		return (-1);
	}
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
		return (here_doc(fd, argc, argv, run_pipes));
	input = open(argv[1], O_RDONLY);
	if (input == -1)
		terminate("open input");
	dup2(input, 0);
	output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (output == -1)
		terminate("open output");
	dup2(output, 1);
	run_pipes(fd, argv + 2, argc - 3);
	close(input);
	close(output);
	return (0);
}
