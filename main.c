/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:13:11 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/28 15:51:24 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	struct t_map	map2;

	if (ac != 2 || file_name(av[1]) != 0)
	{
		ft_printf("Error\nUsage :./so_long filename.ber\n");
		return (-1);
	}
	set_struct(&map2, av[1]);
	if (map_main(&map2) != 0)
	{
		ft_free_map(&map2);
		return (-1);
	}
	find_player(&map2);
	if (has_valid_path(&map2) != 0)
	{
		ft_free_map(&map2);
		return (-1);
	}
	map2.win = mlx_new_window(map2.mlx, map2.win_w, map2.win_h, "so long");
	drawmap(&map2);
	mlx_key_hook(map2.win, &key_press, &map2);
	mlx_hook(map2.win, PRESS_RED_BUTTON, 0, &map_red_exit, &map2);
	mlx_loop(map2.mlx);
	return (0);
}
