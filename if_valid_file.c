/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdembits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:03:00 by vdembits          #+#    #+#             */
/*   Updated: 2018/11/22 14:42:28 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	if_file(int fd, int *count)
{
	int		i;
	int		flag;
	char	buf[1];

	i = 1;
	flag = 1;
	*count = 1;
	while (read(fd, buf, 1) > 0 && flag)
	{
		flag = 0;
		if (i % 21 == 0 && *buf == '\n')
		{
			i = 0;
			flag = 1;
			(*count)++;
		}
		else if (i % 5 == 0 && *buf == '\n')
			flag = 1;
		else if (*buf == '.' || *buf == '#')
			flag = 1;
		i++;
	}
	if (i != 21 || !flag)
		return (-1);
	return (1);
}

int			if_valid(char *file_name, char ****tetriminos)
{
	int		fd;
	int		trmn_number;
	int		i;

	i = -1;
	fd = open(file_name, O_RDONLY);
	if (if_file(fd, &trmn_number) == -1)
		return (-1);
	close(fd);
	if (trmn_number > 26)
		return (-1);
	fd = open(file_name, O_RDONLY);
	if (!(*tetriminos = get_tetrimino(fd, trmn_number)))
		return (-1);
	close(fd);
	while (++i < trmn_number)
	{
		if (tetrimino_is_valid((*tetriminos)[i]) == -1)
			return (-1);
	}
	return (trmn_number);
}
