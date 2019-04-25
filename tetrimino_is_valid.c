/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_is_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:14:04 by oandrosh          #+#    #+#             */
/*   Updated: 2018/11/21 12:34:37 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	neibors(char **tetr, int i, int j)
{
	int	n;

	n = 0;
	if (i > 0)
		n = tetr[i - 1][j] == '#' ? n + 1 : n;
	if (i < 3)
		n = tetr[i + 1][j] == '#' ? n + 1 : n;
	if (j > 0)
		n = tetr[i][j - 1] == '#' ? n + 1 : n;
	if (j < 3)
		n = tetr[i][j + 1] == '#' ? n + 1 : n;
	return (n);
}

int			tetrimino_is_valid(char **tetr)
{
	int i;
	int j;
	int	count;
	int n;

	i = 0;
	count = 0;
	n = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr[i][j] == '#')
			{
				count++;
				n += neibors(tetr, i, j);
			}
			j++;
		}
		i++;
	}
	if (n > 5 && count == 4)
		return (1);
	return (-1);
}
