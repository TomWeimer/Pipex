/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:12:52 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/13 17:14:30 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include  <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>

void	ft_child_process(char *envp[], int *end, int f1, char *cmd1);
char	**ft_find_path(char *envp[]);
int		ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_parent_process(char *envp[], int *end, int f2, char *cmd2);
void	ft_execute(char **envp, char **cmd_args);
char	*ft_strdup(const char *s1);
#endif