/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:40:38 by rle-thie          #+#    #+#             */
/*   Updated: 2022/03/15 15:59:02 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1

//	pour open
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx_int.h>
# include <mlx.h>

typedef struct s_data
{
	char	**tab;
	int		c;
	int		e;
	int		p;
	int		row;
	int		col;
	int		img_size;
	void	*mlx_win;
	void	*mlx;
	void	*img;
	int		position_x;
	int		position_y;
	int		mv;
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
int		img_is_ok(void);
int	free_map(t_data *data);

// game :
int		game(t_data *data);
int		player_position(t_data *data);
int		print_map(t_data *data);
int		select_img(t_data *data, char c);
int		key_event(int keycode, t_data *data);
int		m_up(t_data *data);
int		m_down(t_data *data);
int		m_left(t_data *data);
int		m_right(t_data *data);
int		ft_end(t_data *data);
void	ft_win(t_data *data);
int		ft_free_map(t_data *data);

// GNL :
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, char c);

int		ft_error(char *str);
#endif
