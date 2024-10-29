/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:15:38 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/26 18:38:12 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(struct t_map *map2)
{
	char	*line;
	char	*temp;

	map2->map_total = ft_strdup("");
	if (!map2->map_total)
		return ;
	while (1)
	{
		line = get_next_line(map2->fd);
		if (!line)
			break ;
		temp = ft_strjoin(map2->map_total, line);
		if (!temp)
		{
			free(line);
			break ;
		}
		free(map2->map_total);
		map2->map_total = temp;
		free(line);
	}
}

int	map_line_len(struct t_map *map2)
{
	int		len2;
	int		idx;

	map2 -> map_w = ft_strlen(map2->map_lines[0]);
	map2 -> win_w = map2 -> map_w * 64;
	if (map2->win_w > 1080)
	{
		ft_printf("Error\nMap is tooo long.\n");
		ft_free_map(map2);
		exit(EXIT_FAILURE);
	}
	idx = 1;
	while (map2->map_lines[idx] != NULL)
	{
		len2 = ft_strlen(map2->map_lines[idx]);
		if (len2 != map2 -> map_w)
		{
			ft_printf("Error\nAll line should have same lenth.\n");
			return (-1);
		}
		idx++;
	}
	return (0);
}

int	lines_number(struct t_map *map2)
{
	map2->map_h = 0;
	while (map2->map_lines[map2->map_h] != NULL)
	{
		map2->map_h++;
	}
	map2 -> win_h = map2 -> map_h * 64;
	if (map2->win_h > 1920)
	{
		ft_printf("Error\nMap is tooo high.\n");
		ft_free_map(map2);
		exit(EXIT_FAILURE);
	}
	if (map2 -> map_h < 3)
	{
		ft_printf("Error\nMinimum 3line.\n");
		return (-1);
	}
	return (map2->map_h);
}

int	map_invalid(struct t_map *map2)
{
	int		idx;
	char	*sample;

	sample = "01CEP\n";
	idx = 0;
	if (map2->map_total[0] == '\n')
	{
		ft_printf("Error\nNo empty line in map!\n");
		return (-1);
	}
	while (map2->map_total[idx] != '\0')
	{
		if (map2->map_total[idx] == '\n' && map2->map_total[idx + 1] == '\n')
		{
			ft_printf("Error\nNo empty line in map!\n");
			return (-1);
		}
		if (ft_strchr(sample, map2->map_total[idx]) == NULL)
		{
			ft_printf("Error\nNot good component.\n");
			return (-1);
		}
		idx++;
	}
	return (0);
}

int	map_component(struct t_map *map2)
{
	int	idx;

	idx = 0;
	while (map2->map_total[idx] != '\0')
	{
		if (map2->map_total[idx] == 'C')
			map2->count_c++;
		if (map2->map_total[idx] == 'E')
			map2->count_e++;
		if (map2->map_total[idx] == 'P')
			map2->count_p++;
		idx++;
	}
	if (map2->count_c >= 1 && map2->count_e == 1 && map2->count_p == 1)
		return (0);
	else
	{
		ft_printf("Error\nplayer = 1, exit = 1, item >= 1\n");
		return (-1);
	}
}
