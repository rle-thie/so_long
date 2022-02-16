/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:01:10 by rle-thie          #+#    #+#             */
/*   Updated: 2022/02/16 16:57:46 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		m_up(t_data *data)
{
	printf("w\n");
	data->c=data->c;
	return (1);
}

int		m_down(t_data *data)
{
	data->c=data->c;
	printf("s\n");
	return (1);
}

int		m_left(t_data *data)
{
	data->c=data->c;
	printf("a\n");
	return (1);
}

int		m_right(t_data *data)
{
	data->c=data->c;
	printf("d\n");
	return (1);
}