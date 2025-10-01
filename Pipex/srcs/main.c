/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:35:19 by ksng              #+#    #+#             */
/*   Updated: 2025/10/01 13:24:53 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//1 always write end
//0 always read end


int	**create_fd_pipes(int argc)
{
	int	**fd;
	int	i;

	i = 0;
	fd = malloc(sizeof(int *) * (argc - 4 + 1));
	if (!fd)
		return (NULL);
	while (i < (argc - 4))
	{
		fd[i] = malloc(sizeof(int) * 2);
		if (!fd[i])
			return (NULL);
		if (pipe(fd[i]) == -1)
		{
			perror("PIPE");
			return (NULL);
		}
		i++;
	}
	fd[i] = NULL;
	return (fd);
}

int	pipex(int argc, char **argv, char *envp[])
{
	int	**fd;
	int	ret_value;
	int	i;

	i = 0;
	fd = create_fd_pipes(argc);
	enter_pipe(argv, envp, fd);
	while (i < (argc - 5) && argc > 5)
	{
		middle_pipe(argv[i + 3], envp, fd, i);
		// close(fd[i][1]);
		// close(fd[i][0]);
		i++;
	}
	ret_value = exit_pipe(argc, argv, envp, fd[i]);
	free_pipe_fd(fd);
	return (ret_value);
}






int	main(int argc, char **argv, char *envp[])
{
	if (argc < 5)
	{
		write(2, "Too little arguements\n", 21);
		return (1);
	}
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
		// return (pipex_bonus(argc, argv, envp));
		return (0);
	else
		return (pipex(argc, argv, envp));
}

