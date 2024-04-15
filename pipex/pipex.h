/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:31:11 by apancar           #+#    #+#             */
/*   Updated: 2023/12/21 12:51:10 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>

# define ERR_FILE "No such file or directory\n"
# define ERR_ARG "Invalid number of arguments\n"
# define ERR_PIPE "Error creating pipe.\n"
# define ERR_CMD "Command not found\n"
# define ERR_PATH "Path error.\n"
# define ERR_FORK "Error in fork.\n"
# define ERR_ENV "Envirement does not exist.\n"
# define ERR_EXEC "Exec format error.\n"
# define ERR_ALLO "Memory allocation failed\n"

char	**ft_split(char	const *s, char c);
size_t	ft_strlen(const char *s);
char	*find_env(char **env, char *cmd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strdup(const char *s);
void	child_process(int *fd, char *av[], char **env);
void	main_process(int *fd, char *av[], char **env);
char	*find_path(char *adrr, char *cmd);
int		msg(char *err);
void	msg_error(char *err);

#endif