/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeyirme <rdeyirme@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 07:17:29 by rdeyirme          #+#    #+#             */
/*   Updated: 2022/01/27 11:32:01 by rdeyirme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

static void	*ft_clear_backup(char **backup)
{
	free(*backup);
	*backup = NULL;
	return (*backup);
}

static char	*ft_init_string(char **backup)
{
	char	*last_char;
	char	*result;
	size_t	backup_leng;

	if (!*backup)
		return (*backup);
	backup_leng = ft_strlen(*backup);
	if (!backup_leng)
		return (ft_clear_backup(backup));
	last_char = ft_strchr(*backup, '\n');
	if (!last_char)
	{
		result = ft_substr(*backup, 0, backup_leng);
		**backup = 0;
		return (result);
	}
	result = ft_substr(*backup, 0, last_char - *backup + 1);
	ft_strncpy(*backup, last_char + 1, backup_leng);
	return (result);
}

static char	*ft_update(char **backup, char *str)
{
	char	*old_line;

	old_line = *backup;
	*backup = ft_strjoin(*backup, str);
	if (old_line)
		free(old_line);
	return (*backup);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*backup[64];
	char		line[BUFFER_SIZE + 1];
	int			reededs;

	reededs = 1;
	result = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (result);
	while (reededs && !ft_strchr(backup[fd], '\n'))
	{
		reededs = read(fd, line, BUFFER_SIZE);
		line[reededs] = '\0';
		if (reededs < 0 || !ft_update(&backup[fd], line))
			return (ft_clear_backup(&backup[fd]));
	}
	result = ft_init_string(&backup[fd]);
	return (result);
}
