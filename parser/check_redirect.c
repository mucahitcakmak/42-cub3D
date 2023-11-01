#include "../cub3d.h"

void	two_pointer_free(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	split_direct(t_data *d)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	d->r_paths = malloc(sizeof(char **) * 7);
	while (d->redirect[++i])
	{
		if (d->redirect[i][0] == '\n')
			continue ;
		d->r_paths[++j] = ft_split(d->redirect[i], ' ');
		if (!d->r_paths[j] || !d->r_paths[j][0] || !d->r_paths[j][1] || d->r_paths[j][1][0] == '\n')
			ft_error("Invalid direction paths!", -1, -1);
		if (ft_strnstr(d->r_paths[j][0], "C", ft_strlen(d->redirect[i])) ||
			ft_strnstr( d->r_paths[j][0], "F", ft_strlen(d->redirect[i])))
		{
			two_pointer_free(d->r_paths[j]);
			j--;
			continue;
		}
	}
	d->r_paths[++j] = NULL;
}

void	check_value_of_redirect(char ***s)
{
	int		i;
	char	*p;
	int		j;

	i = -1;
	while (s[++i])
	{
		p = s[i][1];
		j = i;
		while (s[++j])
			if (!ft_strncmp(s[j][1], p, ft_strlen(s[j][1])))
				ft_error("Error: redirect is not valid elma :)", -1, -1);
	}
}


void	ft_checkdirect(t_data *data)
{
	split_direct(data);
	check_value_of_redirect(data->r_paths);
}

