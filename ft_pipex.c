/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:07:30 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/13 15:12:19 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(int infile, int outfile, char *envp[], char *argv[])
{
	int	*end;
	int	ret;
	int	pid;

	end = malloc(sizeof(int) * 2);
	end[0] = infile;
	end[1] = outfile;
	ret = pipe(end);
	if (ret == -1)
	{
		perror("Tube error: ");
		exit(1);
	}
	pid = fork();
	if (pid == 0)
		ft_child_process(envp, end, infile, argv[2]);
	else
		ft_parent_process(envp, end, outfile, argv[3]);
	free(end);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	infile;
	int	outfile;

	if (argc != 5 || envp == NULL || access(argv[1], F_OK) == -1)
	{
		if (argc != 5 || envp == NULL)
			write(errno, "Error\n", 7);
		else
			perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	infile = open(argv[1], O_RDONLY, 0777);
	outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (!infile || !outfile)
	{
		write(errno, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	ft_pipex(infile, outfile, envp, argv);
	close(infile);
	close(outfile);
}
