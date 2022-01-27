/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ext02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:36:36 by sel-mars          #+#    #+#             */
/*   Updated: 2022/01/16 23:36:38 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(0);
}

void	ft_init_integers(int *i, int *j, int *k, int *l)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*l = 0;
}

char	**ft_alloc_to_map(char **map, int map_fd, int size)
{
	int		i;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (size + 2));
	if (!ret)
		ft_map_error(map, map_fd, "Allocation error for map");
	i = 0;
	while (i < size)
	{
		ret[i] = ft_strdup(map[i]);
		if (!ret[i++])
			ft_map_error(map, map_fd, "Allocation error for map");
	}
	while (--i >= 0)
	{
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
	map = NULL;
	return (ret);
}

void	ft_free_map(char **map)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			map[i++] = NULL;
		}
		free(map);
		map = NULL;
	}
}

void	ft_map_error(char **map, int map_fd, char *error)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			map[i++] = NULL;
		}
		free(map);
		map = NULL;
	}
	if (map_fd != -2)
		close(map_fd);
	ft_error(error);
}
