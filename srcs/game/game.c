/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:03:18 by rle-thie          #+#    #+#             */
/*   Updated: 2022/02/15 16:59:39 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int		print_map(t_data *data)
{
	int i;
	int	y;

	i = 0;
	data->img = mlx_xpm_file_to_image(data->mlx, "asset/exit.xpm", &data->img_size, &data->img_size);
	while (i < data->row)
	{
		y = 0;
		while (y < data->col)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, y*64, i*64);
			y++;
		}
		i++;
	}
	return (1);
}

int		game(t_data *data)
{
	// printf("%d", data->col);
    data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->col*64, data->row*64, "So_long");
	// data->img = mlx_xpm_file_to_image(data->mlx, "asset/exit.xpm", &data->img_size, &data->img_size);
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	print_map(data);
	mlx_destroy_image(data->mlx, data->img);
	
	mlx_loop(data->mlx);
	
	return (1);
}