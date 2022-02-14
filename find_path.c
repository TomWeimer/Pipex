/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:12:52 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/13 15:29:26 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_find_path2(char *envp[])
{
	int		i;
	char	*rtn;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 1)
			break ;
		i++;
	}
	rtn = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	return (rtn);
}

char	**ft_find_path(char *envp[])
{
	char	*args;
	char	**args2;
	int		i;
	char	*tmp;

	i = 0;
	args = ft_find_path2(envp);
	args2 = ft_split(args, ':');
	free(args);
	args = NULL;
	i = 0;
	while (args2[i] != NULL)
	{
		tmp = ft_strdup(args2[i]);
		free(args2[i]);
		args2[i] = NULL;
		args2[i] = ft_strjoin(tmp, "/");
		free(tmp);
		i++;
	}
	return (args2);
}
