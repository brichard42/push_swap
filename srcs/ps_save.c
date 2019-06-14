/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:58:12 by brichard          #+#    #+#             */
/*   Updated: 2019/06/14 15:13:55 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	if (!alst || !new)
		return ;
	if (*alst)
		(*alst)->prev = new;
	new->next = *alst;
	new->prev = NULL;
	*alst = new;
}

static t_dlist	*ft_dlstnew(void const *content, size_t content_size)
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

void	ps_save(t_env *env, char *act)
{
	t_dlist *new;

	new = NULL;
	if (!(new = ft_dlstnew((void*)act, ft_strlen(act) + 1)))
		exit(-1); // degueu
	ft_dlstadd(&(env->inst), new);
}
