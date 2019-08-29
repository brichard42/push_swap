/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:35:45 by brichard          #+#    #+#             */
/*   Updated: 2019/08/28 15:56:17 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static t_list	*find_fd(const size_t fd, t_list **begin)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *begin;
	while (tmp)
	{
		if (tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(new = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = (void*)ft_strnew(sizeof(char))))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	new->content_size = fd;
	new->next = NULL;
	ft_lstadd(begin, new);
	return (new);
}

static int		read_fd(t_list **current, char sep)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	while ((ret = read((int)(*current)->content_size, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = (char*)(*current)->content;
		if (!((*current)->content = \
					(void*)ft_strjoin((char*)(*current)->content, buff)))
			return (-1);
		ft_memdel((void **)&tmp);
		if (ft_strchr((char*)(*current)->content, sep))
			break ;
	}
	return (ret);
}

int				get_next_line(const int fd, char **line, char sep)
{
	char			*eol;
	int				ret;
	static t_list	*begin = NULL;
	t_list			*current;

	if (fd < 0 || !(current = find_fd(fd, &begin)))
		return (-1);
	if ((ret = read_fd(&current, sep)) == -1)
		return (-1);
	if (ret == 0 && (ft_strlen((char*)current->content)) == 0)
	{
		ft_lstdelone(&current, &ft_del_cont);
		return (0);
	}
	if ((eol = ft_strchr((char*)current->content, sep)) == NULL)
		eol = ft_strchr((char*)current->content, '\0');
	if ((*line = ft_strsub((char*)current->content, 0, \
					eol - (char*)current->content)) == NULL
			|| !(eol = (*eol != '\0' ? ft_strdup(eol + 1) : ft_strdup(eol))))
		return (-1);
	ft_memdel(&current->content);
	if (!(current->content = (void*)ft_strdup(eol)))
		return (-1);
	ft_memdel((void **)&eol);
	return (1);
}
