/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdembits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:09:20 by vdembits          #+#    #+#             */
/*   Updated: 2018/11/22 15:52:03 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define IF_MALL_NULL(x) if (!x) {free(x); return (NULL);}

int		g_a;

int		**turn_to_i(char ****tetriminos, int size);
void	del_map(char ***map);
int		if_valid(char *file_name, char ****tetriminos);
char	***get_tetrimino(int fd, int n);
int		tetrimino_is_valid(char **tetr);
int		res(int **ttrmns);
void	del_map(char ***map);
void	print_map(char **map);
#endif
