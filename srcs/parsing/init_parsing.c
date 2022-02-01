/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:59:49 by rle-thie          #+#    #+#             */
/*   Updated: 2022/02/01 13:45:37 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_tab_data(t_data *data)
{
	int	i;

	i = 0;
	data->tab = malloc(sizeof(char *) * data->col);
	while (i < data->row)
	{
		data->tab[i] = malloc(sizeof(char *) * data->row);
		i++;
	}
}

void	count_lines(t_data *data)
{
	int		fd;
	char	*str;

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
	init_data(data);
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