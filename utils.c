/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:09:19 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/13 17:10:58 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if ((start + len) > ft_strlen(s))
		ptr = malloc(ft_strlen(s) + 1 * sizeof(char));
	else
		ptr = malloc (len * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[start] && i < len && start < ft_strlen(s))
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	size;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!s2)
		return (NULL);
	size = ft_strlen (s1) + ft_strlen (s2) + 1;
	ptr = malloc ((size * sizeof(char)));
	if (ptr == NULL)
		return (NULL);
	while (*s1)
	{
		ptr[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		ptr[i] = *s2++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	char	*s;
	char	*d;

	s = s1;
	d = s2;
	while (n != 0)
	{
		if (*s != *d)
			return (*s - *d);
		if (!*s)
			return (*s - *d);
		s++;
		d++;
		n--;
	}
	return (1);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
