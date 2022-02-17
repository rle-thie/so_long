/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:03:18 by rle-thie          #+#    #+#             */
/*   Updated: 2022/02/17 13:01:07 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	select_img(t_data *data, char c)
{
	if (c == 'E')
		data->img = mlx_xpm_file_to_image(data->mlx,
				"asset/exit.xpm", &data->img_size, &data->img_size);
	else if (c == 'P')
		data->img = mlx_xpm_file_to_image(data->mlx,
				"asset/perso.xpm", &data->img_size, &data->img_size);
	else if (c == 'C')
		data->img = mlx_xpm_file_to_image(data->mlx,
				"asset/consumable.xpm", &data->img_size, &data->img_size);
	else if (c == '1')
		data->img = mlx_xpm_file_to_image(data->mlx,
				"asset/wall.xpm", &data->img_size, &data->img_size);
	else if (c == '0')
		data->img = mlx_xpm_file_to_image(data->mlx,
				"asset/void.xpm", &data->img_size, &data->img_size);
	return (1);
}

int	print_map(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	while (i < data->row)
	{
		y = 0;
		while (y < data->col)
		{
			select_img(data, data->tab[i][y]);
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->img, y * 64, i * 64);
			mlx_destroy_image(data->mlx, data->img);
			y++;
		}
		i++;
	}
	return (1);
}

int	ft_end(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_map(data);
	exit (0);
	return (1);
}

int	key_event(int keycode, t_data *data)
{
	player_position(data);
	if (keycode == 'w')
		m_up(data);
	else if (keycode == 's')
		m_down(data);
	else if (keycode == 'a')
		m_left(data);
	else if (keycode == 'd')
		m_right(data);
	else if (keycode == 112)
		ft_end(data);
	return (1);
}

int	game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_end(data);
	data->mlx_win = mlx_new_window(data->mlx,
			data->col * 64, data->row * 64, "So_long");
	print_map(data);
	mlx_key_hook(data->mlx_win, &key_event, data);
	mlx_loop(data->mlx);
	return (1);
}

/*
	up = 119;
	down = 115;
	left = 97;
	right = 100;
	echap = XK_Escape;
	clearwindoz
	destroywindow
	destroye display
	
*/