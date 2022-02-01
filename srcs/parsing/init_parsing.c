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

int	init_tab_data(t_data *data, char *arg)
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

void	count_lines(t_data *data, char *arg)
{
	int		fd;
	char	*str;

	// is_map_ok(data, arg);
	fd = open(arg, O_RDONLY);
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

	init_tab_data(data, arg);
}

void	init_data(t_data *data)
{
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->row = 0;
	data->col = 0;
}

int		check_input(char *file)
{
	char *wanted;

	wanted = "reb.";
	if (ft_strlen(file) < 4)
		return (0);
	// verifier si le dernier char est 'r' avant dernier 'e' etc..
	return (1);
}

int		init_parsing(t_data data, char *arg)
{
    if (!check_input(arg) || !count_map_line(data, arg) || !img_is_ok())
        return (0);
    if (!init_map(data, arg) || !check_line_length(data)
        || !chars_is_ok(data) || !check_border(data))
        return (0);
    return (1);
}