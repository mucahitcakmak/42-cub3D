#include "cub3d.h"

void	ft_init(t_data *data, char *address)
{
	data->file_width = 0;
	data->file_height = 0;
	data->map_height = 0;
	data->win_width = 0;
	data->win_height = 0;
	data->map_location = 0;
	get_all_map_size(data, address);
	data->all_map = ft_calloc(data->file_height + 1, sizeof(char *));
	data->map = malloc(sizeof(char *) * (data->file_height + 1));
	data->redirect = malloc(sizeof(char *) * (data->file_height + 1));
	get_all_map(data, address);
	set_directions(data);
	ft_getmap(data, data->map_location - 1);
	ft_checkmap(data);
}

int main(int argc, char **argv)
{
    t_data *data;

	if (argc != 2)
		return 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return 0;
	ft_init(data, argv[1]);
	print_double_pointer(data->map);
	// print_double_pointer(data->redirect);
	return 0;
}
