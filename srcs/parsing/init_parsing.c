/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:59:49 by  rle-thie         #+#    #+#             */
/*   Updated: 2022/03/15 15:58:26 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	init_map(t_data *data, char *arg)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(arg, O_RDONLY);
	if (!fd)
		return (ft_error("Error\nCan't read map"));
	data->tab = malloc(sizeof(char *) * (data->row + 1));
	if (!data->tab || fd < 0)
		return (ft_error("Error\nCan't open file."));
	while (1)
	{
		data->tab[i] = get_next_line(fd);
		if (data->tab[i] == NULL)
			break ;
		i++;
	}
	if (close(fd) == -1)
		return (ft_error("Error\nCan't close input file"));
	return (1);
}

int	check_border(t_data *data)
{
	int	i;
	int	max;

	i = 0;
	max = ft_strlen(data->tab[0]);
	while (i < data->col)
	{
		if (data->tab[0][i] != '1')
			return (ft_error("Error\nMissing wall"));
		i++;
	}
	i = 1;
	while (data->tab[i])
	{
		if (data->tab[i][0] != '1' || data->tab[i][data->col - 1] != '1')
			return (ft_error("Error\nMissing wall"));
		i++;
	}
	i = -1;
	while (++i < data->col)
	{
		if (data->tab[data->row - 1][i] != '1')
			return (ft_error("Error\nMissing wall"));
	}
	return (1);
}

int	count_lines(t_data *data, char *arg)
{
	int		fd;
	char	*str;

	fd = open(arg, O_RDONLY);
	if (!fd)
		return (ft_error("Error\nCant open file"));
	while (1)
	{
		str = get_next_line(fd);
		if (data->col == 0)
			data->col = ft_strlen(str) - 1;
		if (str == NULL)
			break ;
		data->row++;
		free(str);
	}
	close(fd);
	return (1);
}

int	check_line_length(t_data *data)
{
	int	i;
	int	max;

	i = 0;
	while (i < data->row)
	{
		max = ft_strlen(data->tab[i]) - 1;
		if (data->row == i + 1)
			max = ft_strlen(data->tab[i]);
		if (max != data->col)
			return (ft_error("Error\nMap must be un carre"));
		i++;
	}
	return (1);
}

int	init_parsing(t_data *data, char *arg)
{
	if (!check_input(arg) || !count_lines(data, arg) || !img_is_ok())
		return (0);
	if (!init_map(data, arg) || !check_line_length(data)
		|| !chars_is_ok(data) || !check_border(data))
		return (free_map(data));
	return (1);
}
