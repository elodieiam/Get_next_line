/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:44:40 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/25 19:31:18 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 42

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