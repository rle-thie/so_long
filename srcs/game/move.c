/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:01:10 by rle-thie          #+#    #+#             */
/*   Updated: 2022/02/16 18:51:59 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	win(t_data *data)
{
	if (data->c == 0)
	{
		printf("\nBravo !\nScore : %d\nFin du jeu.", data->mv);
		ft_end(data);
	}
}

int		m_up(t_data *data)
{
	if (data->tab[data->position_y - 1][data->position_x] == '0' || 
	data->tab[data->position_y - 1][data->position_x] == 'C' ||
	 (data->tab[data->position_y - 1][data->position_x] == 'E' && data->c == 0))
	{
		if (data->tab[data->position_y - 1][data->position_x] == 'C')
			data->c--;
		else if (data->tab[data->position_y - 1][data->position_x] == 'E')
			ft_end(data);
		data->img = mlx_xpm_file_to_image(data->mlx, "asset/void.xpm", 
		&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 
		data->position_x * 64, data->position_y * 64);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_xpm_file_to_image(data->mlx, "asset/perso.xpm", 
		&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 
		data->position_x * 64, (data->position_y - 1) * 64);
		mlx_destroy_image(data->mlx, data->img);
		data->tab[data->position_y][data->position_x] = '0';
		data->tab[data->position_y - 1][data->position_x] = 'P';
		data->mv++;
		printf("nbr de coups : %d\n", data->mv);
	}
	// printf("pos_x : %d, pos_y : %d, stars : %d\n", data->position_x, data->position_y, data->c);
	return (1);
}

int		m_down(t_data *data)
{
	if (data->tab[data->position_y + 1][data->position_x] == '0' || 
	data->tab[data->position_y + 1][data->position_x] == 'C' ||
	 (data->tab[data->position_y + 1][data->position_x] == 'E' && data->c == 0))
	{
		if (data->tab[data->position_y + 1][data->position_x] == 'C')
			data->c--;
		else if (data->tab[data->position_y + 1][data->position_x] == 'E')
			ft_end(data);
		data->img = mlx_xpm_file_to_image(data->mlx, "asset/void.xpm", 
		&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 
		data->position_x * 64, data->position_y * 64);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_xpm_file_to_image(data->mlx, "asset/perso.xpm", 
		&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 
		data->position_x * 64, (data->position_y + 1) * 64);
		mlx_destroy_image(data->mlx, data->img);
		data->tab[data->position_y][data->position_x] = '0';
		data->tab[data->position_y + 1][data->position_x] = 'P';
		data->mv++;
		printf("nbr de coups : %d\n", data->mv);
	}
	// printf("pos_x : %d, pos_y : %d, stars : %d\n", data->position_x, data->position_y, data->c);
	return (1);
}

int		m_left(t_data *data)
{
	if (data->tab[data->position_y][data->position_x - 1] == '0' || 
	data->tab[data->position_y][data->position_x - 1] == 'C' ||
	 (data->tab[data->position_y][data->position_x - 1] == 'E' && data->c == 0))
	{
		if (data->tab[data->position_y][data->position_x - 1] == 'C')
			data->c--;
		else if (data->tab[data->position_y][data->position_x - 1] == 'E')
			ft_end(data);
		data->img = mlx_xpm_file_to_image(data->mlx, "asset/void.xpm", 
		&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 
		data->position_x * 64, data->position_y * 64);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_xpm_file_to_image(data->mlx, "asset/perso.xpm", 
		&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 
		(data->position_x - 1) * 64, data->position_y * 64);
		mlx_destroy_image(data->mlx, data->img);
		data->tab[data->position_y][data->position_x] = '0';
		data->tab[data->position_y][data->position_x - 1] = 'P';
		data->mv++;
		printf("nbr de coups : %d\n", data->mv);
	}
	// printf("pos_x : %d, pos_y : %d, stars : %d\n", data->position_x, data->position_y, data->c);
	return (1);
}

int		m_right(t_data *data)
{
	if (data->tab[data->position_y][data->position_x + 1] == '0' || 
	data->tab[data->position_y][data->position_x + 1] == 'C' ||
	 (data->tab[data->position_y][data->position_x + 1] == 'E' && data->c == 0))
	{
		if (data->tab[data->position_y][data->position_x + 1] == 'E')
			ft_end(data);
		else if (data->tab[data->position_y][data->position_x + 1] == 'C')
			data->c--;
		data->img = mlx_xpm_file_to_image(data->mlx, "asset/void.xpm", 
		&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 
		data->position_x * 64, data->position_y * 64);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_xpm_file_to_image(data->mlx, "asset/perso.xpm", 
		&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 
		(data->position_x + 1) * 64, data->position_y * 64);
		mlx_destroy_image(data->mlx, data->img);
		data->tab[data->position_y][data->position_x] = '0';
		data->tab[data->position_y][data->position_x + 1] = 'P';
		data->mv++;
		printf("nbr de coups : %d\n", data->mv);
	}
	// printf("pos_x : %d, pos_y : %d, stars : %d\n", data->position_x, data->position_y, data->c);
	return (1);
}