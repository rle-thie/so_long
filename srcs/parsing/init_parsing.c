/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:59:49 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/30 17:45:00 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_parsing(void)
{
	// int		fd;
	// char	*str;
	
	// ligne = 1;
	// fd = open("maps/map1.ber", O_RDONLY);
	// printf("%ld--", ft_strlen(str));
	// while (get_next_line(fd) != NULL)
	// {
	// 	if (ligne == 1)
	// 		colonne = ft_strlen()
	// 	ligne++;
	// }
	// // printf("ligne=%d colonne=%d", ligne, colonne);
	// close(fd);
}

void	init_data(t_data *data)
{
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->length = 1;
	data->width = 1;
}