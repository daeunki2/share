/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:22:55 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/28 15:44:40 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_free_strs(t_map *data)
{
	int		i;

	i = 0;
	while (data->map_lines[i] != NULL)
	{
		free(data->map_lines[i]);
		i++;
	}
	free(data->map_lines);
	data->map_lines = NULL;
	if (data->map_total != NULL)
	{
		free(data->map_total);
		data->map_total = NULL;
	}
	return (0);
}

int	map_red_exit(t_map *p)
{
	ft_printf("Exit : Red Button\n");
	ft_free_map(p);
	exit(0);
	return (1);
}

int	map_esc(t_map *map)
{
	ft_printf("Exit : ESC\n");
	ft_free_map(map);
	exit(0);
	return (0);
}

int	ft_exit(t_map *map)
{
	map->total_move++;
	ft_printf("Exit : GAME SUCCESS,total move = %d\n", map->total_move);
	ft_free_map(map);
	exit(0);
	return (0);
}

void	ft_free_map(t_map *map)
{
	if (map->map_total != NULL)
	{
		if (map->map_lines != NULL)
		{
			free_strs(map->map_lines);
		}
		free(map->map_total);
		close(map->fd);
		mlx_destroy_image(map->mlx, map->img_player);
		mlx_destroy_image(map->mlx, map->img_map);
		mlx_destroy_image(map->mlx, map->img_wall);
		mlx_destroy_image(map->mlx, map->img_exit);
		mlx_destroy_image(map->mlx, map->img_apple);
	}
	if (map->win != NULL)
		mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
}	
