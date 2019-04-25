/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_to_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:41:15 by oandrosh          #+#    #+#             */
/*   Updated: 2018/11/21 12:41:30 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	create_new(int ***new, int size)
{
	int	i;

	i = 0;
	*new = (int**)malloc((size + 1) * sizeof(int*));
	while (i < size)
	{
		(*new)[i] = (int*)malloc(6 * sizeof(int));
		i++;
	}
	(*new)[size] = (int*)malloc(sizeof(int));
	(*new)[size][0] = -1;
}

static void	add(char **c, int *new)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	z = -1;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (c[i][j] == '#')
				new[++z] = 10 * i + j;
			j++;
		}
		i++;
	}
}

static void	optimal(int *tetr)
{
	int	i;
	int	min_row;
	int	min_column;

	min_row = tetr[0] / 10;
	min_column = tetr[0] % 10;
	tetr[4] = min_row;
	tetr[5] = min_column;
	i = 0;
	while (++i < 4)
	{
		if (min_row > tetr[i] / 10)
			min_row = tetr[i] / 10;
		if (min_column > tetr[i] % 10)
			min_column = tetr[i] % 10;
		if (tetr[4] < tetr[i] / 10)
			tetr[4] = tetr[i] / 10;
		if (tetr[5] < tetr[i] % 10)
			tetr[5] = tetr[i] % 10;
	}
	while (--i >= 0)
		tetr[i] -= min_row * 10 + min_column;
	tetr[4] -= min_row - 1;
	tetr[5] -= min_column - 1;
}

int			**turn_to_i(char ****tetriminos, int size)
{
	int	z;
	int	**new_tetr;

	create_new(&new_tetr, size);
	z = 0;
	while (z < size)
	{
		add((*tetriminos)[z], new_tetr[z]);
		optimal(new_tetr[z]);
		z++;
	}
	return (new_tetr);
}
