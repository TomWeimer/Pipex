/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:08:24 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/13 17:08:56 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_parent_process(char *envp[], int *end, int f2, char *cmd2)
{
	int		status;
	char	**cmd_args;

	waitpid(-1, &status, 0);
	dup2(f2, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	close(f2);
	cmd_args = ft_split(cmd2, ' ');
	ft_execute(envp, cmd_args);
}
