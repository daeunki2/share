/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:43:02 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/26 14:15:57 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(struct t_map *map2)
{
	map2 -> p_x = 0;
	map2 -> p_y = 0;
	while (map2 -> map_lines[map2 -> p_y] != NULL)
	{
		while (map2 -> map_lines[map2 -> p_y][map2 -> p_x] != '\0')
		{
			if (map2 -> map_lines[map2 -> p_y][map2 -> p_x] == 'P')
				return ;
			map2 -> p_x++;
		}
		map2 -> p_y++;
		map2 -> p_x = 0;
	}
}

void	player_move_left(struct t_map *map2)
{
	if (map2->map_lines[map2->p_y][map2->p_x - 1] == '1')
		return ;
	else if (map2->map_lines[map2->p_y][map2->p_x - 1] == '0')
	{
		map2->map_lines[map2->p_y][map2->p_x] = '0';
		map2->map_lines[map2-> p_y][map2->p_x - 1] = 'P';
		map2->total_move++;
	}
	else if (map2 -> map_lines[map2->p_y][map2->p_x - 1] == 'C')
	{
		map2->map_lines[map2->p_y][map2->p_x] = '0';
		map2->map_lines[map2->p_y][map2->p_x - 1] = 'P';
		map2->count_c--;
		map2->total_move++;
	}
	else if (map2->map_lines[map2->p_y][map2->p_x - 1] == 'E')
	{
		if (map2->count_c == 0)
		{
			ft_exit(map2);
		}
		return ;
	}
	ft_printf("step: %d\n", map2->total_move);
	find_player(map2);
}

void	player_move_right(struct t_map *map2)
{
	if (map2 -> map_lines[map2 -> p_y][map2 -> p_x + 1] == '1')
		return ;
	else if (map2 -> map_lines[map2 -> p_y][map2 -> p_x + 1] == '0')
	{
		map2->map_lines[map2->p_y][map2 -> p_x] = '0';
		map2 -> map_lines[map2-> p_y][map2 -> p_x + 1] = 'P';
		map2 -> total_move++;
	}
	else if (map2 -> map_lines[map2 -> p_y][map2 -> p_x + 1] == 'C')
	{
		map2 -> map_lines[map2 -> p_y][map2 -> p_x] = '0';
		map2 -> map_lines[map2 -> p_y][map2 -> p_x + 1] = 'P';
		map2 -> count_c--;
		map2 -> total_move++;
	}
	else if (map2 -> map_lines[map2 -> p_y][map2 -> p_x + 1] == 'E')
	{
		if (map2->count_c == 0)
		{
			ft_exit(map2);
		}
		return ;
	}
	ft_printf("step: %d\n", map2->total_move);
	find_player(map2);
}

void	player_move_down(struct t_map *map2)
{
	if (map2 -> map_lines[map2 -> p_y + 1][map2 -> p_x] == '1')
		return ;
	else if (map2 -> map_lines[map2 -> p_y + 1][map2 -> p_x] == '0')
	{
		map2->map_lines[map2->p_y][map2 -> p_x] = '0';
		map2 -> map_lines[map2-> p_y + 1][map2 -> p_x] = 'P';
		map2 -> total_move++;
	}
	else if (map2 -> map_lines[map2 -> p_y + 1][map2 -> p_x] == 'C')
	{
		map2 -> map_lines[map2 -> p_y][map2 -> p_x] = '0';
		map2 -> map_lines[map2 -> p_y + 1][map2 -> p_x] = 'P';
		map2 -> count_c--;
		map2 -> total_move++;
	}
	else if (map2 -> map_lines[map2 -> p_y + 1][map2 -> p_x] == 'E')
	{
		if (map2->count_c == 0)
		{
			ft_exit(map2);
		}
		return ;
	}
	ft_printf("step: %d\n", map2->total_move);
	find_player(map2);
}

void	player_move_up(struct t_map *map2)
{
	if (map2 -> map_lines[map2 -> p_y - 1][map2 -> p_x] == '1')
		return ;
	else if (map2 -> map_lines[map2 -> p_y - 1][map2 -> p_x] == '0')
	{
		map2->map_lines[map2->p_y][map2 -> p_x] = '0';
		map2 -> map_lines[map2-> p_y - 1][map2 -> p_x] = 'P';
		map2 -> total_move++;
	}
	else if (map2 -> map_lines[map2 -> p_y - 1][map2 -> p_x] == 'C')
	{
		map2 -> map_lines[map2 -> p_y][map2 -> p_x] = '0';
		map2 -> map_lines[map2 -> p_y - 1][map2 -> p_x] = 'P';
		map2 -> count_c--;
		map2 -> total_move++;
	}
	else if (map2 -> map_lines[map2 -> p_y - 1][map2 -> p_x] == 'E')
	{
		if (map2->count_c == 0)
		{
			ft_exit(map2);
		}
		return ;
	}
	ft_printf("step: %d\n", map2->total_move);
	find_player(map2);
}
