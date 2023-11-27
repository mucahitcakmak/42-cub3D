
#include "cub3d.h"

void	mlx_define(t_data *data)
{
	int	x;
	int	y;
	data->g.mlx = mlx_init();
	data->g.win = mlx_new_window(data->g.mlx, screenWidth, screenHeight, "ELMA.TXT");
	data->g.sky = mlx_xpm_file_to_image(data->g.mlx, "textures/sky_eagle.xpm", &x,&y);
	data->g.floor = mlx_xpm_file_to_image(data->g.mlx, "textures/floor_wood.xpm", &x,&y);
	data->g.north_wall = mlx_xpm_file_to_image(data->g.mlx, "textures/north_pillar.xpm", &x,&y);
	data->g.east_wall = mlx_xpm_file_to_image(data->g.mlx, "textures/east_greystone.xpm",&x,&y);
	data->g.west_wall = mlx_xpm_file_to_image(data->g.mlx, "textures/west_mossy.xpm", &x, &y);
	data->g.south_wall = mlx_xpm_file_to_image(data->g.mlx, "textures/south_bluestone.xpm", &x, &y);
	data->g.kare = mlx_xpm_file_to_image(data->g.mlx, "textures/kare.xpm", &x, &y);
	data->g.duvar = mlx_xpm_file_to_image(data->g.mlx, "textures/duvar.xpm", &x, &y);

	init_vec(data->ch, data->ch->ch_pos[2], data->ch->ch_pos[0], data->ch->ch_pos[1]);
	init_mlx(data);
	mlx_hook(data->g.win, 2, 1L << 0, key_code, data);
	mlx_loop_hook(data->g.mlx, draw_game, data);
	// mlx_hook(data->g.win, 17, 0L, close_game, NULL);		
	mlx_loop(data->g.mlx);
}


void	ft_init(t_data *data, char *address)
{

	get_all_map_size(data, address);
	data->all_map = ft_calloc(data->file_height + 1, sizeof(char *));
	data->map = malloc(sizeof(char *) * (data->file_height + 1));
	data->redirect = malloc(sizeof(char *) * (data->file_height + 1));
	get_all_map(data, address);
	set_redirects(data);
	ft_getmap(data, data->map_location - 1);
	ft_checkmap(data);
	ft_checkdirect(data);
}

int main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (0);
	data = malloc(sizeof(t_data));
	data->ch = malloc(sizeof(t_ch));
	if (!data)
		return (0);
	ft_init(data, argv[1]);
	mlx_define(data);
	return (0);
}
















































// void	mlx_define(t_data *data)
// {
// 	int	x;
// 	int	y;
// 	data->g.mlx = mlx_init();
// 	data->g.win = mlx_new_window(data->g.mlx, 1024, 510, "ELMA.TXT");
// 	data->g.sky = mlx_xpm_file_to_image(data->g.mlx, "textures/sky_eagle.xpm", &x,&y);
// 	data->g.floor = mlx_xpm_file_to_image(data->g.mlx, "textures/floor_wood.xpm", &x,&y);
// 	data->g.north_wall = mlx_xpm_file_to_image(data->g.mlx, "textures/north_pillar.xpm", &x,&y);
// 	data->g.east_wall = mlx_xpm_file_to_image(data->g.mlx, "textures/east_greystone.xpm",&x,&y);
// 	data->g.west_wall = mlx_xpm_file_to_image(data->g.mlx, "textures/west_mossy.xpm", &x, &y);
// 	data->g.south_wall = mlx_xpm_file_to_image(data->g.mlx, "textures/south_bluestone.xpm", &x, &y);
// 	data->g.kare = mlx_xpm_file_to_image(data->g.mlx, "textures/kare.xpm", &x, &y);
// 	data->g.duvar = mlx_xpm_file_to_image(data->g.mlx, "textures/duvar.xpm", &x, &y);
// 	px=150; py=400; pa=90;
// 	mlx_hook(data->g.win, 2, 1L << 0, key_code, data);
// 	mlx_loop_hook(data->g.mlx, draw_player, data);
// 	mlx_hook(data->g.win, 17, 0L, close_game, NULL);		
// 	mlx_loop(data->g.mlx);
// }

// void	ft_init(t_data *data, char *address)
// {
// 	data->file_width = 0;
// 	data->file_height = 0;
// 	data->map_height = 0;
// 	data->win_width = 0;
// 	data->win_height = 0;
// 	data->map_location = 0;
// 	data->ch->planeX = 0;
// 	data->ch->planeY = 0.66;
// 	data->ch->time = 0;
// 	data->ch->oldTime = 0;
// 	get_all_map_size(data, address);
// 	data->all_map = ft_calloc(data->file_height + 1, sizeof(char *));
// 	data->map = malloc(sizeof(char *) * (data->file_height + 1));
// 	data->redirect = malloc(sizeof(char *) * (data->file_height + 1));
// 	get_all_map(data, address);
// 	set_redirects(data);
// 	ft_getmap(data, data->map_location - 1);
// 	ft_checkmap(data);
// 	ft_checkdirect(data);
// }

// int main(int argc, char **argv)
// {
// 	t_data	*data;

// 	if (argc != 2)
//         ft_error("Invalid arguman!", -1, -1);
// 	data = malloc(sizeof(t_data));
// 	data->ch = malloc(sizeof(t_ch));
// 	if (!data)
// 		return (0);
// 	ft_init(data, argv[1]);
// 	mlx_define(data);
// 	return (0);
// }