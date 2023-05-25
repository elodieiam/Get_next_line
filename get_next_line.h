/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:55:36 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/25 18:02:14 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_file(int fd, char *stash);
char	*get_line(char *stash);
char	*clean_stash(char *stash);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int searched_char);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);

#endif
