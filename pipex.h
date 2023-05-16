/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:34:30 by mmomeni           #+#    #+#             */
/*   Updated: 2023/05/14 21:09:24 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

/* System */

int		run(char *s);
void	terminate(char *reason);
void	run_pipes(int fd[2], char **commands, int n);

/* File System */

char	*get_env(char *key);
char	*join_path(char *s1, char *s2);
char	*get_path(char *program);

#endif