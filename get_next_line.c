/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:57:05 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/23 19:32:22 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




char	*get_next_line(int fd)
{
    static char	*save; // pour stocker ce qui vient après \n
	char		*line; //ce qu'on renvoie : la première ligne lue
	char		*buffer; //ce qui est utilisé par read à chaque appel
	
	//Les vérifications sur fd (penser à préciser =! fd stdout et erreur)
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
		return (NULL);
	//On alloue la taille du buffer qui sera utilisé par read
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	save = ft_get_line(fd, line, buffer);
}