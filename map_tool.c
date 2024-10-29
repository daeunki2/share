/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:33:32 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/28 15:40:55 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_name(char *file)
{
	int		i;
	char	*ext;

	i = 0;
	ext = ".ber";
	while (*(file + i) != '.')
		i++;
	while (*(file + i) || *ext)
	{
		if (*(file + i) != *ext)
		{
			return (-1);
		}
		ext++;
		i++;
	}
	return (0);
}

int	map_first_last(char *line)
{
	int	idx;
	int	len;

	idx = 0;
	len = ft_strlen(line);
	while (idx < len)
	{
		if (line[idx] != '1')
		{
			ft_printf("Error\nMissig wall. I'm sad.\n");
			return (-1);
		}
		idx++;
	}
	return (0);
}

int	map_middle(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[0] != '1' || line[len - 1] != '1')
	{
		ft_printf("Error\nMissing wall too sad.\n");
		return (-1);
	}
	return (0);
}

int	map_main(struct t_map *map2)
{
	int	idx;
	int	lines_num;

	idx = 0;
	map_read(map2);
	if (map_invalid(map2) != 0)
		return (-1);
	if (map_component(map2) != 0)
		return (-1);
	map2->map_lines = ft_split(map2->map_total, '\n');
	if (map_line_len(map2) != 0)
		return (-1);
	if (map_first_last(map2->map_lines[idx]) != 0)
		return (-1);
	idx++;
	lines_num = lines_number(map2);
	while (idx < lines_num - 1)
	{
		if (map_middle(map2->map_lines[idx]) != 0)
			return (-1);
		idx++;
	}
	if (map_first_last(map2->map_lines[idx]) != 0)
		return (-1);
	return (0);
}
