/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:59:49 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/30 13:35:58 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int init_parsing(int fd)
{
	int ligne;

	ligne = 0;
	if (!fd)
		return (0);
	while (get_next_line(fd) != NULL)
		ligne++;
	
	return (ligne);
}