/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:13:56 by brichard          #+#    #+#             */
/*   Updated: 2019/07/19 16:56:04 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_dlist	*skip_pa(t_dlist *inst, int n)
{
	while (inst && n-- && ft_strequ("pa", (char*)inst->content))
		inst = inst->next;
	return (inst);
}

static t_dlist	*skip_pb(t_dlist *inst, int n)
{
	while (inst && n-- && ft_strequ("pb", (char*)inst->content))
		inst = inst->next;
	return (inst);
}

static int		ps_count_pa(t_dlist *inst, t_dlist *(*f)(t_dlist*, int))
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

static int		ps_count_pb(t_dlist *inst, t_dlist *(*f)(t_dlist*, int))
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

static void	ps_del_nodes(t_dlist **inst, int n)
{
	t_dlist	*tmp;

	if (n == 0 || !inst || !*inst)
		return ;
	tmp = (*inst);
	if ((*inst = (*inst)->prev))
		(*inst)->next = (*inst)->next->next;
	if ((*inst)->next)
		(*inst)->next->prev = (*inst);
	ft_dlstdelone(&tmp, ps_del);
	ps_del_nodes(&(*inst)->next, --n);
}

void		ps_opti_push(t_dlist **inst)
{
	int		pa;
	int		pb;
	int		ret;
	t_dlist	*tmp;

	if (ft_strequ("pa", (char*)(*inst)->content))
	{
		pa = ps_count_pa(*inst, NULL);
		pb = ps_count_pb(*inst, skip_pa);
		//ft_printf("pa | npa = %d npb = %d\n", pa, pb);
		if ((ret = pa - pb) > 0)
		{
			if (!(tmp = skip_pa((*inst), ret)))
				return ;
			//ft_printf("izdisworking?\n");
			ps_del_nodes(&tmp, pb * 2);
		}
		else
			ps_del_nodes(inst, pa * 2);
	}
	else if (ft_strequ("pb", (char*)(*inst)->content))
	{
		pb = ps_count_pb(*inst, NULL);
		pa = ps_count_pa(*inst, skip_pb);
		//ft_printf("pb | npb = %d npa = %d\n", pb, pa);
		if ((ret = pb - pa) > 0)
		{
			if (!(tmp = skip_pb((*inst), ret)))
				return ;
			ps_del_nodes(&tmp, pa * 2);
		}
		else
			ps_del_nodes(inst, pb * 2);
	}
}
