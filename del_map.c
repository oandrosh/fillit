/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdembits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:08:44 by vdembits          #+#    #+#             */
/*   Updated: 2018/11/19 17:21:46 by vdembits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_map(char ***map)
{
	int	i;

	i = 0;
	while (i < g_a)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
}
