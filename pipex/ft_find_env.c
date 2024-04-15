/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:26:45 by apancar           #+#    #+#             */
/*   Updated: 2023/12/12 12:38:55 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	str_len;
	size_t	i;
	size_t	j;

	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str)
		msg("Malloc error.\n");
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*find_path(char *adrr, char *cmd)
{
	int		i;
	char	*temp;
	char	*full_path;
	char	**arg;

	arg = ft_split(adrr, ':');
	i = -1;
	while (arg[++i] != NULL)
	{
		temp = ft_strjoin(arg[i], "/");
		free(arg[i]);
		arg[i] = temp;
	}
	i = -1;
	while (arg[++i] != NULL)
	{
		full_path = ft_strjoin(arg[i], cmd);
		if (access(full_path, X_OK) == 0)
			return (free(arg[i]), full_path);
		else
			free(full_path);
	}
	free(arg);
	return (0);
}

char	*find_env(char **env, char *cmd)
{
	char	*adrr;
	int		i;

	i = 0;
	adrr = NULL;
	while (env[i] != NULL)
	{
		if (ft_strstr(env[i], "PATH=") != NULL)
		{
			adrr = ft_strdup(env[i] + 5);
			break ;
		}
		i++;
	}
	if (adrr == NULL)
	{
		perror("Environment doesn't exist.");
		free(adrr);
		exit(127);
	}
	return (find_path(adrr, cmd));
}
