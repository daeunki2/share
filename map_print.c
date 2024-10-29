/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:33:08 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/26 12:46:16 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	drawmap(struct t_map *map2)
{
	char		**map_data;
	char		*str;
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	i = 0;
	mlx_clear_window(map2->mlx, map2->win);
	map_data = map2->map_lines;
	while (map_data[i] != NULL)
	{
		str = map_data[i];
		while (*str != '\0')
		{
			draw_img(*str, map2, x, y);
			str++;
			x = x + 64;
		}
		i++;
		x = 0;
		y = y + 64;
	}
	return (0);
}

void	draw_img(char a, struct t_map *par, int x, int y)
{
	if (a == '0')
		mlx_put_image_to_window(\
		par->mlx, par->win, par->img_map, x, y);
	else if (a == '1')
	{
		mlx_put_image_to_window(\
		par->mlx, par->win, par->img_map, x, y);
		mlx_put_image_to_window(\
		par->mlx, par->win, par->img_wall, x, y);
	}
	else if (a == 'P' || a == 'C' || a == 'E')
	{
		mlx_put_image_to_window(par->mlx, par->win, par->img_map, x, y);
		if (a == 'P')
			mlx_put_image_to_window(par->mlx, par->win, par->img_player, x, y);
		else if (a == 'C')
			mlx_put_image_to_window(par->mlx, par->win, par->img_apple, x, y);
		else if (a == 'E')
			mlx_put_image_to_window(par->mlx, par->win, par->img_exit, x, y);
	}
}
