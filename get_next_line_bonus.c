/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:44:01 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/25 16:17:31 by elrichar         ###   ########.fr       */
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
	if (!stash[i])// si on a atteint la fin du fichier et donc rien à stocker (== stash[i] == '\0')
	{
		free (stash);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!s)
		return (NULL);
	i++; //pour passer sur \n
	while (stash[i])
		s[j++] = stash[i++];
	s[j] = '\0';
	free (stash); //on free la précédente adresse
	return (s); //on renvoie la nouvelle
}

/* Pour extraire la ligne de end_line.
*/
char	*get_line(char *stash)
{
	char	*s;
	int		i;

	i = 0;
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
	if (stash[i] == '\n') //car ça peut être la fin de la ligne sans \n
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return (s);
} //on ne free rien car s est la ligne qu'on renvoie et on a encore besoin de stash

/* read_file : on lit dans le fichier jusqu'à ce qu'on tombe sur \n 
ou sur la fin du fichier txt. A chaque passage de read on strjoin buff et end_line
pour conserver ce qui avait déjà été stocké dedans.
*/
char	*read_file(int fd, char *stash)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while ((!ft_strchr(stash, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == (-1))
		{
			free (buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		if (!stash) //si 1e utilisation et donc stash est initialisé à NULL
		stash = ft_strdup("");//alors chaîne vide
		stash = ft_strjoin(stash, buffer);
	}
	free (buffer);
	return (stash);
}

/* GNL : on stocke tout ce qui est lu par read dans stash,
on extrait line de end_line puis on nettoie stash
*/
char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, stash[fd], 0) == -1)
		return (NULL);
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = get_line (stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
