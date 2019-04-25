/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdembits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:43:04 by vdembits          #+#    #+#             */
/*   Updated: 2018/11/22 14:45:22 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		***create_tetrimino(int count)
{
	int		i;
	char	***tetriminos;

	i = 0;
	IF_MALL_NULL((tetriminos = (char ***)malloc(sizeof(char **) * (count + 1))));
	while (i < count)
	{
		IF_MALL_NULL((tetriminos[i] = (char **)malloc(sizeof(char *) * 4)));
		i++;
	}
	return (tetriminos);
}

char			***get_tetrimino(int fd, int n)
{
	int		i;
	int		j;
	char	*line;
	char	***tetriminos;

	i = 0;
	j = -1;
	IF_MALL_NULL((tetriminos = create_tetrimino(n)));
	while (get_next_line(fd, &line) == 1)
	{
		if (++j != 4)
			tetriminos[i][j] = ft_strdup(line);
		else
		{
			i++;
			j = -1;
		}
		free(line);
	}
	tetriminos[n] = NULL;
	return (tetriminos);
}
