/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:13:56 by brichard          #+#    #+#             */
/*   Updated: 2019/06/19 12:16:46 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_count_papb(t_dlist *inst, int *papb)
{
	papb[0] = 0;
	papb[1] = 0;
	while (inst->next && ft_strequ("pa", (char*)inst->content))
	{
		++papb[0];
		inst = inst->next;
	}
	while (inst->next && ft_strequ("pb", (char*)inst->content))
	{
		++papb[1];
		inst = inst->next;
	}
}

static void	ps_count_papb(t_dlist *inst, int *papb)
{
	papb[0] = 0;
	papb[1] = 0;
	while (inst->next && ft_strequ("pb", (char*)inst->content))
	{
		++papb[1];
		inst = inst->next;
	}
	while (inst->next && ft_strequ("pa", (char*)inst->content))
	{
		++papb[0];
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
	ft_dlstdelone(&tmp, ps_del);
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
	if (ft_strequ("pa", (char*)(*inst)->content))
	{
		ps_count_papb(*inst, rr);
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
	else if (ft_strequ("pb", (char*)(*inst)->content))
	{
		ps_count_papb(*inst, rr);
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
