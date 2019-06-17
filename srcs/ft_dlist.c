/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:57:09 by brichard          #+#    #+#             */
/*   Updated: 2019/06/17 14:20:54 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_del(void *content)
{
	ft_memdel(&content);
}

void	ft_dlstdelone(t_dlist **alst, void (*del)(void*))
{
	if (!del || !alst || !*alst)
		return ;
	del((*alst)->content);
	ft_memdel((void**)alst);
}

void	ft_dlstdel(t_dlist **alst, void (*del)(void*))
{
	if (!alst || !*alst || !del)
		return ;
	if ((*alst)->next)
		ft_dlstdel(&((*alst)->next), del);
	ft_dlstdelone(alst, del);
}

void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	if (!alst || !new)
		return ;
	if (*alst)
		(*alst)->prev = new;
	new->next = *alst;
	new->prev = NULL;
	*alst = new;
}

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*new;

	new = NULL;
	if (!(new = (t_dlist*)ft_memalloc(sizeof(t_dlist))))
		return (NULL);
	if (content == 0 || content_size == 0)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = (void*)ft_memalloc(content_size)))
		{
			free(new);
			return (0);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
