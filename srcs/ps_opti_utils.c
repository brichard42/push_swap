/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:41:54 by brichard          #+#    #+#             */
/*   Updated: 2019/08/27 15:45:24 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*skip_pa(t_dlist *inst, int n)
{
	while (inst && n-- && ft_strequ("pa", (char*)inst->content))
		inst = inst->next;
	return (inst);
}

t_dlist	*skip_pb(t_dlist *inst, int n)
{
	while (inst && n-- && ft_strequ("pb", (char*)inst->content))
		inst = inst->next;
	return (inst);
}

int		ps_count_pa(t_dlist *inst, t_dlist *(*f)(t_dlist*, int))
{
	int	i;

	if (f)
		if (!(inst = f(inst, INT_MAX)))
			return (0);
	i = 0;
	while (inst && ft_strequ("pa", (char*)inst->content))
	{
		++i;
		inst = inst->next;
	}
	return (i);
}

int		ps_count_pb(t_dlist *inst, t_dlist *(*f)(t_dlist*, int))
{
	int	i;

	if (f)
		if (!(inst = f(inst, INT_MAX)))
			return (0);
	i = 0;
	while (inst && ft_strequ("pb", (char*)inst->content))
	{
		++i;
		inst = inst->next;
	}
	return (i);
}

void	ps_del_nodes(t_dlist **inst, int n)
{
	t_dlist	*tmp;

	if (n == 0 || !inst || !*inst)
		return ;
	ps_del_nodes(&(*inst)->next, n - 1);
	tmp = (*inst);
	if ((*inst)->prev)
	{
		(*inst) = (*inst)->prev;
		(*inst)->next = tmp->next;
	}
	else
		(*inst) = (*inst)->next;
	(*inst)->prev = NULL;
	tmp->next->prev = (*inst);
	ft_dlstdelone(&tmp, ps_del);
}
