/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:16:05 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/26 14:15:05 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, struct t_map *map2)
{
	if (keycode == KEY_W || keycode == XK_Up)
		player_move_up(map2);
	else if (keycode == KEY_S || keycode == XK_Down)
		player_move_down(map2);
	if (keycode == KEY_A || keycode == XK_Left)
		player_move_left(map2);
	else if (keycode == KEY_D || keycode == XK_Right)
		player_move_right(map2);
	else if (keycode == KEY_ESC)
	{
		map_esc(map2);
	}
	drawmap(map2);
	return (0);
}
