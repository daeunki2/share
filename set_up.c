/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:45:52 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/28 15:43:56 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_images(struct t_map *map2)
{
	actual_checking(map2);
	map2->img_player = mlx_xpm_file_to_image(map2->mlx, "img/player.xpm",
			&map2->win_w, &map2->win_h);
	map2->img_map = mlx_xpm_file_to_image(map2->mlx, "img/grass.xpm",
			&map2->win_w, &map2->win_h);
	map2->img_wall = mlx_xpm_file_to_image(map2->mlx, "img/wall.xpm",
			&map2->win_w, &map2->win_h);
	map2->img_exit = mlx_xpm_file_to_image(map2->mlx, "img/exit.xpm",
			&map2->win_w, &map2->win_h);
	map2->img_apple = mlx_xpm_file_to_image(map2->mlx, "img/apple.xpm",
			&map2->win_w, &map2->win_h);
}

void	initialize_map(struct t_map *map2)
{
	map2->map_lines = NULL;
	map2->map_total = NULL;
	map2->count_e = 0;
	map2->count_p = 0;
	map2->count_c = 0;
	map2->map_h = 0;
	map2->map_w = 0;
	map2->win_h = 0;
	map2->win_w = 0;
	map2->total_move = 0;
}

void	initialize_window(struct t_map *map2)
{
	map2->win = NULL;
}

void	set_struct(struct t_map *map2, char *av)
{
	map2->fd = open(av, O_RDONLY);
	if (map2->fd < 0)
	{
		ft_printf("Error\nI can not open file. Try again :(\n");
		exit(-1);
	}
	initialize_map(map2);
	initialize_window(map2);
	map2->mlx = mlx_init();
	initialize_images(map2);
}
