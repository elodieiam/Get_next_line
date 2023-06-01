/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:44:01 by elrichar          #+#    #+#             */
/*   Updated: 2023/06/01 13:52:28 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*clean_stash(char *stash)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free (stash);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(stash) - i));
	if (!s)
	{
		free(stash);
		return (NULL);
	}
	i++;
	while (stash[i])
		s[j++] = stash[i++];
	s[j] = '\0';
	free (stash);
	return (s);
}

char	*get_line(char *stash)
{
	char	*s;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		s[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

char	*read_file(int fd, char *stash)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while ((!ft_strchr(stash, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == (-1))
		{
			free (buffer);
			free (stash);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free (buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc (sizeof(char));
		if (!stash[fd])
			return (NULL);
		stash[fd][0] = '\0';
	}
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = get_line (stash[fd]);
	if (!line)
	{
		free (stash[fd]);
		return (NULL);
	}
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
