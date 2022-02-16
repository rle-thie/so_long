/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:19:24 by rle-thie          #+#    #+#             */
/*   Updated: 2022/02/16 15:59:54 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int main(void)
// {
//     void    *mlx_ptr;
//     void    *win_ptr;

//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, 64, 64, "so_long");
//     mlx_loop(mlx_ptr);
//     return (0);
// }

int main(int ac, char **av)
{
	t_data	data;
	// int i = 0;
	
	if (ac != 2)
		return (ft_error("Error\nNumber of argument not valid"));
	init_data(&data);
	// init_parsing(&data, av[1]);
	if (!init_parsing(&data, av[1]))
		return (0);
	game(&data);
	// init_map(&data, av[1]);
	// check_border(&data);
	// check_line_length(&data);
	// chars_is_ok(&data);
	// while (i < data.row)
	// 	printf("%s", data.tab[i++]);
	return(1);
}