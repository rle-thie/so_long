/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:40:38 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/30 17:46:26 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1

//	pour open
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_data
{
	char **tab;
	int		c;
	int		e;
	int		p;
	int		length;
	int		width;
}t_data;

// parsing :
void	init_data(t_data *data);

// game :

// GNL :
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, char c);

#endif
