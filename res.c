/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:21:30 by oandrosh          #+#    #+#             */
/*   Updated: 2018/11/21 12:47:50 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**drawing(void)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = (char**)malloc(sizeof(char**) * (g_a));
	while (i < g_a)
	{
		map[i] = (char*)malloc(g_a + 1);
		j = 0;
		while (j < g_a)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][g_a] = '\0';
		i++;
	}
	return (map);
}

static void		clear(char **map, int z)
{
	int i;
	int j;

	i = 0;
	while (i < g_a)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'A' + z)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

static int		fill(char **map, int cor, int *tetr, int z)
{
	int i;
	int j;

	i = cor / 100;
	j = cor % 100;
	if (i + tetr[4] > g_a || j + tetr[5] > g_a)
		return (0);
	if (map[i + tetr[0] / 10][j + tetr[0] % 10] == '.' &&
			map[i + tetr[1] / 10][j + tetr[1] % 10] == '.' &&
			map[i + tetr[2] / 10][j + tetr[2] % 10] == '.' &&
			map[i + tetr[3] / 10][j + tetr[3] % 10] == '.')
	{
		map[i + tetr[0] / 10][j + tetr[0] % 10] = 'A' + z;
		map[i + tetr[1] / 10][j + tetr[1] % 10] = 'A' + z;
		map[i + tetr[2] / 10][j + tetr[2] % 10] = 'A' + z;
		map[i + tetr[3] / 10][j + tetr[3] % 10] = 'A' + z;
		return (1);
	}
	else
		return (0);
}

static	int		arrange(char **map, int **tetr, int z)
{
	int	i;
	int	j;

	i = 0;
	if (tetr[z][0] == -1)
		return (1);
	while (i < g_a)
	{
		j = 0;
		while (map[i][j])
		{
			if ((fill(map, i * 100 + j, tetr[z], z)) == 1)
			{
				if (arrange(map, tetr, z + 1) == 1)
					return (1);
				else
					clear(map, z);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int				res(int **ttrmns)
{
	char	**map;

	while (1)
	{
		map = drawing();
		if (arrange(map, ttrmns, 0) == 1)
		{
			print_map(map);
			return (0);
		}
		del_map(&map);
		g_a++;
	}
}
