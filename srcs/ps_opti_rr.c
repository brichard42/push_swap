/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:03:51 by brichard          #+#    #+#             */
/*   Updated: 2019/07/19 16:40:06 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_count_rab(t_dlist *inst, int *rab)
{
	rab[0] = 0;
	rab[1] = 0;
	while (inst->next && ft_strequ("ra", (char*)inst->content))
	{
		++rab[0];
		inst = inst->next;
	}
	while (inst->next && ft_strequ("rb", (char*)inst->content))
	{
		++rab[1];
		inst = inst->next;
	}
}

static void	ps_count_rba(t_dlist *inst, int *rab)
{
	rab[0] = 0;
	rab[1] = 0;
	while (inst->next && ft_strequ("rb", (char*)inst->content))
	{
		++rab[1];
		inst = inst->next;
	}
	while (inst->next && ft_strequ("ra", (char*)inst->content))
	{
		++rab[0];
		inst = inst->next;
	}
}

static void	ps_replace_rr(t_dlist **inst, int rr)
{
	t_dlist	*tmp;

	if (rr == 0)
		return ;
	tmp = (*inst)->next;
	(*inst)->next = (*inst)->next->next;
	if ((*inst)->next->next)
		(*inst)->next->next->prev = *inst;
//	ft_dlstdelone(&tmp, ps_del);
	ft_strcpy((char*)(*inst)->content, "rr");
	ps_replace_rr(inst, rr - 1);
}

void	ps_count_rr(t_dlist **inst)
{
	int	rr[2];
	int i;
	int res;
	t_dlist *tmp;

	tmp = *inst;
	res = 0;
	if (ft_strequ("ra", (char*)(*inst)->content))
	{
		ps_count_rab(*inst, rr);
		if (rr[0] > rr[1])
		{
			i = rr[0] - rr[1];
			while (i)
			{
				tmp = tmp->next;
				--i;
			}
		}
		res = (rr[0] > rr[1] ? rr[1] * 2 : rr[0] * 2);
	}
	else if (ft_strequ("rb", (char*)(*inst)->content))
	{
		ps_count_rba(*inst, rr);
		if (rr[1] > rr[0])
		{
			i = rr[1] - rr[0];
			while (i)
			{
				tmp = tmp->next;
				--i;
			}
		}
		res = (rr[1] > rr[0] ? rr[0] * 2 : rr[1] * 2);
	}
	ps_replace_rr(&tmp, res);
}
