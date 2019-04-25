/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdembits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 12:26:48 by vdembits          #+#    #+#             */
/*   Updated: 2018/11/10 12:59:43 by vdembits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*makeline(char **line, char *s)
{
	int		size;
	char	*new;
	int		i;

	size = 0;
	i = 0;
	if (s[0] == '\n')
		i++;
	while (s[i + size] != '\n' && s[i + size])
		size++;
	*line = ft_strnew(size);
	new = ft_strdup(s + i + size);
	if (!*line || !new)
		return (NULL);
	while (--size > -1)
		(*line)[size] = s[i + size];
	ft_strdel(&s);
	return (new);
}

static char		*strrejoin(char *s1, char const *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (new);
}

static t_list	*get_file(int fd, t_list **all_files)
{
	t_list	*curr_file;

	curr_file = *all_files;
	while (curr_file)
	{
		if (fd == (int)curr_file->content_size)
			return (curr_file);
		curr_file = curr_file->next;
	}
	if (!(curr_file = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(all_files, curr_file);
	curr_file = *all_files;
	return (curr_file);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			*buf;
	static t_list	*all_files;
	t_list			*curr;

	MALLCHECK((buf = ft_strnew(BUFF_SIZE)));
	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	MALLCHECK((curr = get_file(fd, &all_files)));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		MALLCHECK((curr->content = strrejoin(curr->content, buf)));
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	ft_strdel(&buf);
	if ((ret < BUFF_SIZE && ((char *)(curr->content))[0] == '\0') || (((char *)
		(curr->content))[0] == '\n' && ((char *)(curr->content))[1] == '\0'))
		return (0);
	MALLCHECK((curr->content = makeline(line, (char *)curr->content)));
	return (1);
}
