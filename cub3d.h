/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:06:09 by museker           #+#    #+#             */
/*   Updated: 2023/11/27 10:38:27 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <time.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

#define MOVE_SPEED 1
#define ROT_SPEED  1
#define	FRAME_PER_SEC  2
#define PIX 16
#define screenWidth 800
#define screenHeight 800


typedef struct s_ch 
{
	double		ch_pos[3]; // 0 = x pos | 1 = y pos | 3 = (char)direction

	// t_raycast
	double	cam_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side1;
	double	wall_dist;

	// t_wall
	int	side2;
	int	tex_x;
	int	line_h;
	int	draw_start;
	int	draw_end;

	// t_image
	void			*img_ptr;
	int				bpp;
	int				size_l;
	int				endian;
	unsigned int	*data;

	//t_mlx
	int		**tmp;
	int		*texture[4];

	// t_vec
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	pln_x;
	double	pln_y;

	// t_cub
	int		fl;
	int		ce;
	int		h;
	int		w;
}	t_ch;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*north_wall;
	void	*west_wall;
	void	*south_wall;
	void	*east_wall;
	void	*sky;
	void	*floor;
	void	*kare;
	void	*duvar;
}	t_game;

typedef struct s_data
{
	char	**all_map;
	char	**map;
	char	**redirect;
	char	***r_paths;
	int		file_width;
	int		file_height;
	int		map_width;
	int		map_height;
	int		win_width;
	int		win_height;
	int		map_location;
	int		*f;
	int		*c;
	t_game	g;
	t_ch	*ch;
}	t_data;

// ---------------------------  main.c  ----------------------------//
void	ft_init(t_data *data, char *address);

// ---------------------  parser/check_map.c  ---------------------//
void	ft_error(char *str, int i, int j);
int		ft_strlen_one_zero_map(t_data *data, char **s);
void	ft_check_one_zero_map(t_data *d);
void	ft_check_redirects(t_data *d);
void	ft_checkmap(t_data *data);

// ---------------------  parser/check_map2.c  ---------------------//
void	is_connected_map(t_data *d);
int		get_value_redirect(t_data *d, char *redirect);
void	check_player(t_data *data);
int		get_value_redirect(t_data *d, char *redirect);

// ---------------------  parser/check.c  ---------------------//
void	ft_checkdirect(t_data *data);
int		two_pointer_character_size(char **s);
char *two_pointer_to_one_pointer(char **str);
void	split_direct(t_data *d);

// ---------------------  parser/get_map.c -------------------------//
void	print_double_pointer(char **str);
void	print_int_pointer(int *a);
int		map_size(char **s);
void	get_all_map_size(t_data *data, char *address);
void	set_redirects(t_data *data);
void	ft_getmap(t_data *d, int i);
void	get_all_map(t_data *data, char *address);

void	check_value_of_redirect(char ***s);
void	ch_direction(t_data *d);

// ---------------------  raycasting/init.c -------------------------//
void	init_cub3d(t_ch *c);
void	init_vec(t_ch *v, char c, int x, int y);
void	init_texture(t_data *d);
void	init_tmp(t_ch *m);
void	init_mlx(t_data *d);

// ---------------------  raycasting/raycast.c -------------------------//
void	init_raycast(t_ch *c, int x);
void	calc_ray(t_ch *c, int x);
void	dda(t_data *d);

// ---------------------  raycasting/run_util.c -------------------------//
void	my_xpm_to_img(t_data *d, int dir, char *wall);
void	draw_floor_ceil(t_ch *c);

// ---------------------  raycasting/run.c -------------------------//
double	calc_dis(t_ch *c);
void	calc_wall(t_ch *c);
void	map_line(t_ch *c, int x);
void	draw(t_data *d);
int		draw_game(t_data *d);

// ---------------------  raycasting/move.c -------------------------//
void	rotate(t_ch *v, int opt);
void	move_ws(t_data *d, double opt);
void	move_ad(t_data *d, double opt);
int		close_win(t_data *d);
int		key_code(int keycode, t_data *d);
void	set_color(int *texture, int *c_or_f);
#endif


// #ifndef CUB3D_H
// # define CUB3D_H

// /*STDINT includes __uint8_t instead of saying unsigned char for the
// floor and ceiling structs*/
// # include <stdint.h>

// /*This is to more easily parse the 2d map array given so that we may call
// If Map[0][0] == Wall instead of Map[0][0] == 1, it brings a bit of clarity
// and structure

// NP is the only special character, which is non playable, it will fill
// parts of the map in parsing, that are "empty" spaces but not walls within the
// map

// North, East, South, West, are all player character identifiers, only one
// may exist on the map at a time, and this determines the orientation of the
// player upon starting*/
// enum e_mapDefintion
// {
// 	nonPlayable = -1,
// 	empty = 0,
// 	wall = 1,
// 	north,
// 	east,
// 	south,
// 	west
// };

// /*Both the floor and the ceiling have identical structs. Seperated for clarity
// as they are seperate entities. Both will be parsed to contain an
// RGB value between 0-255 for each color respectfully.*/
// typedef union u_rgba
// {
// 	unsigned int	rgba;
// 	struct {
// 		__uint8_t	r;
// 		__uint8_t	g;
// 		__uint8_t	b;
// 		__uint8_t	a;
// 	};
// }				t_rgba;

// /*This contains the path to each texture, one for each, north
// east, south, west. Where the math section will then be able to open the
// textures on their side to get the images.

// This struct can be changed to hold open file descriptors if you wish instead */
// typedef struct s_textures
// {
// 	char	*north;
// 	char	*east;
// 	char	*south;
// 	char	*west;
// }				t_textures;

// /*This struct contains basic information for the map,
// including the direction character the player will be facing at start*/
// typedef struct s_map
// {
// 	unsigned int	direction;
// 	unsigned int	player_x;
// 	unsigned int	player_y;
// 	unsigned int	max_cols;
// 	unsigned int	max_rows;
// }				t_map;

// /*This is the struct that contains all the information. Holding the
// floor, ceiling, and texture structs. as well as containing the 2d array of
// the parsed map.*/
// typedef struct s_cubed
// {
// 	t_rgba			floor;
// 	t_rgba			ceiling;
// 	t_textures		textures;
// 	t_map			info;
// 	char			*map_file;
// 	int				**map;
// }				t_cubed;

// #endif
