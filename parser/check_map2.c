/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:07:18 by mucakmak          #+#    #+#             */
/*   Updated: 2023/12/11 01:43:04 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	is_connected_map(t_data *d, int i, int j)
{
	while (d->map[++i])
	{
		j = -1;
		while (d->map[i][++j])
		{
			if (d->map[i][j] == '1')
			{
				if ((j -1 >= 0 && (d->map[i][j - 1] == '1' || d->map[i][j - 1]
					== '0' || c_o_z_m(d, i, j - 1))) || (i - 1 >= 0
					&& (d->map[i - 1][j] == '1' || d->map[i - 1][j] == '0'
					|| c_o_z_m(d, i - 1, j))) || (j + 1 <= d->map_width + 1 &&
					(d->map[i][j + 1] == '1' || d->map[i][j + 1] == '0'
					|| c_o_z_m(d, i, j + 1))) || (i + 1 <= d->map_height + 1
					&& (d->map[i + 1][j] == '1' || d->map[i + 1][j] == '0'
					|| c_o_z_m(d, i + 1, j))) || (i - 1 == -1 && (d->map[0][j]
					== '1' || d->map[0][j] == '0')) || (j - 1 == -1 &&
					(d->map[i][0] == '1' || d->map[i][0] == '0')))
					continue ;
				else
					ft_error("Map is not valid", i, j);
			}
		}
	}
}

void	check_player2(t_data *d, int i, int j)
{
	if (d->map[i][j] != 'W' && d->map[i][j] != 'N' &&
		d->map[i][j] != '*' && d->map[i][j] != 'E' &&
		d->map[i][j] != 'S' && d->map[i][j] != '0' &&
		d->map[i][j] != '1' && d->map[i][j] != '.' && d->map[i][j] != '/')
		ft_error("Invalid argument in map!", i, j);
}

void	check_player(t_data *d)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (d->map[++i])
	{
		j = -1;
		while (d->map[i][++j])
		{
			if ((d->map[i][j] == 'W' || d->map[i][j] == 'N'
				|| d->map[i][j] == 'E' || d->map[i][j] == 'S') && ++count)
			{
				d->ch->ch_pos[0] = i;
				d->ch->ch_pos[1] = j;
				d->ch->ch_pos[2] = d->map[i][j];
				d->map[i][j] = '0';
			}
			check_player2(d, i, j);
		}
	}
	if (count != 1)
		ft_error("Map is not valid!", -1, -1);
}

int	get_value_redirect(t_data *d, char *redirect)
{
	int	i;

	i = -1;
	while (d->r_paths[++i])
		if (!ft_strncmp(d->r_paths[i][0], redirect,
			ft_strlen(d->r_paths[i][0])))
			return (i);
	return (-1);
}

void	ft_check_get_map(t_data *d, int i)
{
	char	*s;

	while (d->all_map[i])
	{
		s = ft_strtrim(d->all_map[i], " \n");
		if (s && s[0])
		{
			free(s);
			ft_error("Map is not valid!", i, -1);
		}
		free(s);
		i++;
	}
}
