/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:25:10 by rle-thie          #+#    #+#             */
/*   Updated: 2022/02/17 13:01:46 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->row)
	{
		free(data->tab[i]);
		i++;
	}
	free(data->tab);
	return (1);
}

int	player_position(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	while (i < data->row)
	{
		y = 0;
		while (y < data->col)
		{
			if (data->tab[i][y] == 'P')
			{
				data->position_y = i;
				data->position_x = y;
				return (1);
			}
			y++;
		}
		i++;
	}
	return (0);
}
