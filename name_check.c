/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:49:44 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/26 16:35:50 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_xpm_file(char *str, struct t_map *map)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nuse a good xpmfile. stp :)\n");
		ft_free_map(map);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	actual_checking(struct t_map *map)
{
	check_xpm_file("img/apple.xpm", map);
	check_xpm_file("img/exit.xpm", map);
	check_xpm_file("img/grass.xpm", map);
	check_xpm_file("img/player.xpm", map);
	check_xpm_file("img/wall.xpm", map);
}
// int	file_name(char *file, char *filename)
// {
// 	int		i;
// 	char	*ext;

// 	i = 0;
// 	ext = ".xpm";
// 	while (*(file + i) != '.')
// 		i++;

// 	while (*(file + i) || *ext)
// 	{
// 		if (*(file + i) != *ext)
// 		{
// 			ft_printf("Error\nInvalid File name or File Extenstion\n");
// 			return (1);
// 		}
// 		ext++;
// 		i++;
// 	}
// 	return (0);
// }