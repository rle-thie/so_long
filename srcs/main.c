/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:19:24 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/30 18:39:26 by rle-thie         ###   ########.fr       */
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

int main(void)
{
	t_data	data;
	
	init_data(&data);
	count_lines(&data);
	printf("row=%d col=%d", data.row, data.col);
	return(0);
}
