/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:19:24 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/30 13:28:22 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int main(void)
// {
//     void    *mlx_ptr;
//     void    *win_ptr;

//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, 500, 500, "oui");
//     mlx_loop(mlx_ptr);
//     return (0);
// }

int main(void)
{
	int fd;

	fd = open("../maps/map.ber", O_RDONLY);
	init_parsing(fd);
	close(fd);
}
