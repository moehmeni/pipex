/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:04:08 by mmomeni           #+#    #+#             */
/*   Updated: 2023/05/14 21:06:03 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int	fd[2];
	int	input;
	int	output;

	if (argc != 5)
	{
		ft_putendl_fd("Invalid number of arguments", STDERR_FILENO);
		return (-1);
	}
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
	close(fd[0]);
	close(fd[1]);
	return (0);
}
