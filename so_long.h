/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:40:38 by rle-thie          #+#    #+#             */
/*   Updated: 2022/02/15 14:38:13 by rle-thie         ###   ########.fr       */
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
	int		row;
	int		col;
	void	*mlx_win;
	void	*mlx;
}t_data;

// parsing :
int		init_parsing(t_data *data, char *arg);
void	init_data(t_data *data);
int		check_border(t_data *data);
int		check_line_length(t_data *data);
int		chars_is_ok(t_data *data);
int		count_lines(t_data *data, char *arg);
int		init_map(t_data *data, char *arg);
int		check_input(char *file);
int		img_is_ok();

// game :
int		game(t_data *data);

// GNL :
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, char c);

int ft_error(char *str);
#endif
