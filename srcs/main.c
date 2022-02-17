/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:19:24 by rle-thie          #+#    #+#             */
/*   Updated: 2022/02/17 16:16:55 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (!env[0])
		return (ft_error("Error\narrete\n"));
	if (ac != 2)
		return (ft_error("Error\nNumber of argument not valid\n"));
	init_data(&data);
	if (!init_parsing(&data, av[1]))
		return (0);
	game(&data);
	return (1);
}
