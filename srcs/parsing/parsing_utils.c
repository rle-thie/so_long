/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:34:30 by rle-thie          #+#    #+#             */
/*   Updated: 2022/02/17 12:55:23 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_data(t_data *data)
{
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->row = 0;
	data->col = 0;
	data->img_size = 64;
	data->position_x = 0;
	data->position_y = 0;
	data->mv = 0;
}

int	img_is_ok(void)
{
	if (open("asset/exit.xpm", O_RDONLY) <= 0)
		return (ft_error("Error\nCan't open exit.xpm"));
	if (open("asset/perso.xpm", O_RDONLY) <= 0)
		return (ft_error("Error\nCan't open perso.xpm"));
	if (open("asset/void.xpm", O_RDONLY) <= 0)
		return (ft_error("Error\nCan't open void.xpm"));
	if (open("asset/wall.xpm", O_RDONLY) <= 0)
		return (ft_error("Error\nCan't open wall.xpm"));
	if (open("asset/consumable.xpm", O_RDONLY) <= 0)
		return (ft_error("Error\nCan't open consumable.xpm"));
	return (1);
}

int	check_input(char *file)
{
	int		i;

	if (ft_strlen(file) <= 4)
		return (ft_error("Error\nlength of file name are wrong"));
	i = ft_strlen(file);
	if (file[i - 1] != 'r' || file[i - 2] != 'e' || file[i - 3] != 'b'
		|| file[i - 4] != '.')
		return (ft_error("Error\nFile have to be .ber ext"));
	if (open(file, O_RDONLY) <= 0)
		return (ft_error("Error\nCan't open the map"));
	return (1);
}

int	chars_is_ok(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->tab[x])
	{
		y = 0;
		while (data->tab[x][y])
		{
			if (data->tab[x][y] == 'C')
				data->c++;
			else if (data->tab[x][y] == 'P')
				data->p++;
			else if (data->tab[x][y] == 'E')
				data->e++;
			else if (data->tab[x][y] != '1' && data->tab[x][y] != '0'
					&& data->tab[x][y] != '\n')
				return (ft_error("Error\nCaractere chelou"));
			y++;
		}
		x++;
	}
	if (data->c <= 0 || data->e != 1 || data->p != 1)
		return (ft_error("Error\nExit, player or consumable missing"));
	return (1);
}
