/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:18:36 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/26 17:58:11 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define KEY_ESC 65307       // 우분투 ESC 키
# define KEY_W 119           // 우분투 W 키
# define KEY_S 115           // 우분투 S 키
# define KEY_A 97            // 우분투 S 키
# define KEY_D 100           // 우분투 S 키
# define PRESS_RED_BUTTON 33 //

typedef struct t_map
{
	int		fd;
	char	*map_total;
	char	**map_lines;
	int		count_e;
	int		count_p;
	int		count_c;
	void	*mlx;
	void	*win;
	int		map_h;
	int		map_w;
	int		win_h;
	int		win_w;
	int		p_x;
	int		p_y;
	int		total_move;
	void	*img_player;
	void	*img_map;
	void	*img_wall;
	void	*img_exit;
	void	*img_apple;
}			t_map;
// get_next_line_utils.c
size_t		ft_strlen(const char *s);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
// get_nextline.c
char		*ft_get_line(char *stt);
char		*ft_file_read(int fd, char *backup, char *buf);
char		*ft_get_backup(char *buffer);
char		*get_next_line(int fd);
// ft_split.c
char		**ft_split(char const *s, char c);
int			ft_wordcount(char *str, char sep);
int			ft_wordlen(char *substr, char sep);
int			ft_issep(char *s, char c);
char		*ft_substr(char *s, unsigned int start, size_t len);
// map_read.c
void		map_read(struct t_map *map2);
int			map_line_len(struct t_map *map2);
int			lines_number(struct t_map *map2);
int			map_invalid(struct t_map *map2);
int			map_component(struct t_map *map2);
int			file_name(char *av);
// map_tool.c
int			map_first_last(char *line);
int			map_middle(char *line);
int			map_main(struct t_map *map2);
// map_print.c
void		draw_img(char a, struct t_map *par, int x, int y);
int			drawmap(struct t_map *map2);
void		set_struct(struct t_map *map2, char *av);
// MOVE.C
void		find_player(struct t_map *map2);
void		player_move_left(struct t_map *map2);
void		player_move_right(struct t_map *map2);
void		player_move_up(struct t_map *map2);
void		player_move_down(struct t_map *map2);
// key_press.c
int			key_press(int keycode, struct t_map *map2);
// free_error.c
int			map_red_exit(t_map *p);
int			map_esc(t_map *map);
int			ft_exit(t_map *map);
void		ft_free_map(t_map *map);
void		*ft_free_strs(t_map *data);
// dfs.c
int			dfs(int x, int y, char **map, char find_char);
int			has_valid_path(t_map *data);
char		**ft_copy_map(char **map, int map_h);
void		free_strs(char **data);
int			erroe_out(char *message);
// set_up.c
void		initialize_images(struct t_map *map2);
void		initialize_map(struct t_map *map2);
void		initialize_window(struct t_map *map2);
void		set_struct(struct t_map *map2, char *av);
//name_check.c
void		actual_checking(struct t_map *map);
void		check_xpm_file(char *str, struct t_map *map);

#endif