/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:21:51 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/13 17:06:24 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		if (path[i] != NULL)
		{
			free(path[i]);
			path[i] = NULL;
		}
		i++;
	}
}

void	ft_access_denied(char **cmd_args, char **path)
{
	write(errno, "command not found: ", 19);
	write(errno, cmd_args[0], ft_strlen(cmd_args[0]));
	write(errno, "\n", 1);
	ft_free_path(path);
	exit(127);
}

char	*ft_get_cmd(char **envp, char **cmd_args)
{
	char	**path;
	int		i;
	char	*cmd;

	i = 0;
	path = ft_find_path(envp);
	while (path[i] != NULL)
	{
		cmd = ft_strjoin(path[i], cmd_args[0]);
		if (access(cmd, F_OK) == -1)
		{
			free(cmd);
			cmd = NULL;
			if (path[i + 1] == NULL)
				ft_access_denied(cmd_args, path);
			i++;
		}
		else
			break ;
	}
	ft_free_path(path);
	return (cmd);
}

void	ft_execute(char **envp, char **cmd_args)
{
	int		i;
	char	*cmd;

	cmd = ft_get_cmd(envp, cmd_args);
	if (execve(cmd, cmd_args, envp) == -1)
	{
		perror("error execve");
		if (cmd != NULL)
			free(cmd);
		i = 0;
		exit(EXIT_FAILURE);
	}
	if (cmd != NULL)
		free(cmd);
	i = 0;
	exit(EXIT_SUCCESS);
}

void	ft_child_process(char *envp[], int *end, int f1, char *cmd1)
{
	char	**cmd_args;

	dup2(f1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(f1);
	cmd_args = ft_split(cmd1, ' ');
	ft_execute(envp, cmd_args);
}
