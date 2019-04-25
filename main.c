/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:28:32 by oandrosh          #+#    #+#             */
/*   Updated: 2018/11/21 14:31:13 by vdembits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		n;
	char	***tetriminos;
	int		**ttrmns;

	g_a = 1;
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (0);
	}
	if ((n = if_valid(av[1], &tetriminos)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	while (g_a * g_a < n * 4)
		g_a++;
	ttrmns = turn_to_i(&tetriminos, n);
	res(ttrmns);
	return (0);
}
