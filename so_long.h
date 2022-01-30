/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:40:38 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/30 15:01:19 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//	pour open
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


# include <mlx.h>
# include "srcs/utils/GNL/get_next_line.h"

// parsing :
int	init_parsing(int fd);

// game :

// GNL :
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, char c);

typedef struct s_data
{
	char **tab;
	char	c;
	char	e;
	char	p;
}t_data;


#endif
