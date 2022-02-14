/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:59:49  by rle-thie          #+#    #+#             */
/*   Updated: 2022/02/01 13:45:37 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	init_map(t_data *data, char *arg)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(arg, O_RDONLY);
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
	close(fd);
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
		// printf("%s", str);
		data->row++;
		free(str);
	}
	close(fd);
	return (1);
	//init_tab_data(data, arg);
}

void	init_data(t_data *data)
{
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->row = 0;
	data->col = 0;
}

int		img_is_ok()
{
	if (open("asset/exit.xpm", O_RDONLY) <= 0)
		return (ft_error("Error\nCan't open exit.xpm"));
	if (open("asset/perso.xpm", O_RDONLY) <= 0)
		return (ft_error("Error\nCan't open perso.xpm"));
	if (open("asset/void.xpm", O_RDONLY) <= 0)
		return (ft_error("Error\nCan't open void.xpm"));
	if (open("asset/wall.xpm", O_RDONLY) <= 0)
		return (ft_error("Error\nCan't open wall.xpm"));
	return (1);
}

int		check_input(char *file)
{
	int		i;

	if (ft_strlen(file) <= 4)
		return (ft_error("Error\nlength of file name are wrong"));
	i = ft_strlen(file);
	if (file[i-1] != 'r' || file[i-2] != 'e' || file[i-3] != 'b' || file[i-4] != '.')
		return (ft_error("Error\nFile have to be .ber ext"));
	if (open(file, O_RDONLY) <= 0)
		return (ft_error("Error\nCan't open the map"));
	return (1);
}

int		check_border(t_data *data)
{
	int	i;
	int max;

	i = 0;
	max = ft_strlen(data->tab[0]);
	while(i < data->col)
	{
		// printf("%c", data->tab[0][i]);
		if (data->tab[0][i] != '1')
			return (ft_error("Error\nMissing wall"));
		i++;
	}
	i = 1;
	while (data->tab[i])
	{
		// printf("%c %c\n", data->tab[i][0], data->tab[i][data->col-1]);
		if (data->tab[i][0] != '1' || data->tab[i][data->col-1] != '1')
			return (ft_error("Error\nMissing wall"));
		i++;
	}
	i = 0;
	while (i < data->col)
	{
		if (data->tab[data->row - 1][i] != '1')
			return (ft_error("Error\nMissing wall"));
		i++;
	}
	return (1);
}

int		check_line_length(t_data *data)
{
	int	i;
	int	max;

	i = 0;
	while (i < data->row)
	{
		max = ft_strlen(data->tab[i]);
		printf("%d, %d", max, data->col - 1);
		if (max != data->col - 1)
			return(ft_error("Error\nMap must be un carre"));
		i++;
	}
	return (1);
}

int		init_parsing(t_data *data, char *arg)
{
    if (!check_input(arg) || !count_lines(data, arg) || !img_is_ok())
        return (0);
//     if (!init_map(data, arg) || !check_line_length(data)
//         || !chars_is_ok(data) || !check_border(data))
//         return (0);
    return (1);
}