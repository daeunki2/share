/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:09:24 by daeunki2          #+#    #+#             */
/*   Updated: 2024/07/01 17:30:45 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dfs(int x, int y, char **map, char find_char)
{
	int	count;

	if (map[y][x] == '1')
		return (0);
	if (find_char == 'C' && map[y][x] == 'E')
		return (0);
	if (map[y][x] != 'V')
	{
		count = 0;
		if (map[y][x] == find_char)
			count = 1;
		map[y][x] = 'V';
		count += dfs(x - 1, y, map, find_char);
		count += dfs(x, y + 1, map, find_char);
		count += dfs(x + 1, y, map, find_char);
		count += dfs(x, y - 1, map, find_char);
		return (count);
	}
	return (0);
}

int	has_valid_path(t_map *data)
{
	char	**map_temp_c;
	char	**map_temp_e;
	int		c_number;
	int		e_number;

	map_temp_c = ft_copy_map(data->map_lines, data->map_h);
	if (!map_temp_c)
		return (-1);
	map_temp_e = ft_copy_map(data->map_lines, data->map_h);
	if (!map_temp_e)
	{
		free_strs(map_temp_c);
		return (-1);
	}
	c_number = dfs(data->p_x, data->p_y, map_temp_c, 'C');
	free_strs(map_temp_c);
	e_number = dfs(data->p_x, data->p_y, map_temp_e, 'E');
	free_strs(map_temp_e);
	if (c_number != data->count_c)
		return (erroe_out("it is not possilbe to get all the items."));
	if (e_number != 1)
		return (erroe_out("it is not possilbe to reach the exit."));
	return (0);
}

char	**ft_copy_map(char **map, int map_h)
{
	int		i;
	char	**temp;

	i = 0;
	temp = NULL;
	temp = (char **)malloc((map_h + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	while (i < map_h)
	{
		temp[i] = ft_strdup(map[i]);
		if (!temp[i])
		{
			free_strs(temp);
			return (NULL);
		}
		i++;
	}
	temp[map_h] = NULL;
	return (temp);
}

void	free_strs(char **data)
{
	int	i;

	i = 0;
	while (data[i] != NULL)
	{
		free(data[i]);
		i++;
	}
	free(data);
}

int	erroe_out(char *message)
{
	ft_printf("Error\n%s\n", message);
	return (-1);
}

// int	dfs(int x, int y, char **map, char find_char)
// {
// 	int	count;

// 	if (map[y][x] == '1')
// 		return (0);
// 	if (map[y][x] != 'V')
// 	{
// 		if (map[y][x] == find_char)
// 		{
// 			map[y][x] = 'V';
// 			return (1);
// 		}
// 		map[y][x] = 'V';
// 		count = 0;
// 		count += dfs(x - 1, y, map, find_char);
// 		count += dfs(x, y + 1, map, find_char);
// 		count += dfs(x + 1, y, map, find_char);
// 		count += dfs(x, y - 1, map, find_char);
// 		return (count);
// 	}
// 	return (0);
// }