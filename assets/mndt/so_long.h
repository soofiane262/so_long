/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:33:03 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:33:04 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <time.h>
# include <fcntl.h>
# include "../../mlx/mlx.h"
# include "../../libft/libft.h"
# include "../../libft/get_next_line.h"

typedef struct s_params
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*font_ptr;
	void	*walls_ptr[21];
	void	*exit_ptr[2];
	void	*collec_ptr;
	void	*player_r_ptr;
	void	*player_l_ptr;
	int		player_d;
}			t_params;
typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		pos[2];
	int		collec;
	int		moves;
	int		lose;
}			t_map;
typedef struct s_img
{
	int		font_w;
	int		font_h;
	int		player_w;
	int		player_h;
	int		walls_w;
	int		walls_h;
	int		exit_w;
	int		exit_h;
	int		collec_w;
	int		collec_h;
}			t_img;
typedef struct s_all
{
	t_params	*param;
	t_img		*img;
	t_map		*map;
}			t_all;
void	ft_make_ptrs(t_all *all);
void	ft_make_walls(t_all *all);
void	ft_make_exits(t_all *all);
void	ft_make_player(t_all *all);
int		ft_put_all(t_all *all);
int		ft_destroy_key_hook(int key, t_all *all);
void	ft_win(t_all *all);
void	ft_win_ext(t_all *all);
void	ft_lose(t_all *all);
void	ft_putmoves(t_all *all);
void	ft_put_outer_walls(t_all *all);
void	ft_put_outer_walls_ext00(t_all *all);
void	ft_put_outer_walls_ext01(t_all *all);
void	ft_put_outer_walls_ext02(t_all *all);
void	ft_put_outer_walls_ext03(t_all *all);
void	ft_put_font_walls(t_all *all);
int		ft_put_exit(t_all *all);
void	ft_put_exit_closed(t_all *all);
void	ft_put_exit_open(t_all *all);
void	ft_put_collec(t_all *all);
int		ft_put_player(t_all *all);
int		ft_destroy_x(t_all *all);
int		ft_key_hook(int key, t_all *all);
void	ft_move_up(t_all *all);
void	ft_move_down(t_all *all);
void	ft_move_left(t_all *all);
void	ft_move_right(t_all *all);
void	ft_error(char *str);
void	ft_check_map(t_map *map, char *map_file);
void	ft_check_walls(char **map, int *len);
void	ft_check_chars(char **map, int *len);
void	ft_check_char_ext00(char c, int *i2, int *i3, int *i4);
void	ft_check_char_ext01(char ***map, int i2, int i3, int i4);
char	**ft_make_map(char *map_file);
char	**ft_alloc_to_map(char **map, int map_fd, int size);
char	*ft_map_line_dup(char *temp);
void	ft_free_map(char **map);
void	ft_check_mlx_imgs(t_all *all);
void	ft_map_error(char ***map, int map_fd, char *error, int t);
void	ft_make_map_ext(char ***map, int *i, char **temp, int map_fd);
void	ft_init(t_all *all);
void	ft_init_integers(int *i0, int *i1, int *i2, int *i3);
#endif
