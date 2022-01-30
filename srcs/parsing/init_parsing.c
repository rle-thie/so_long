/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:59:49 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/30 18:38:36 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	count_lines(t_data *data)
{
	int		fd;
	char	*str;
	int		row;
	int		col;
	
	row = 0;
	col = 0;
	fd = open("maps/map1.ber", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (data->col == 0)
			data->col = ft_strlen(str) - 1;
		if (str == NULL)
			break ;
		// printf("%s", str);
		data->row++;
		free(str);
	}
	close(fd);
}

void	init_data(t_data *data)
{
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->row = 0;
	data->col = 0;
}