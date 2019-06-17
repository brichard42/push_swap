/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti_inst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:56:15 by brichard          #+#    #+#             */
/*   Updated: 2019/06/17 18:39:00 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_count_rab(t_dlist *inst)
{
	int	ra;
	int rb;

	ra = 0;
	rb = 0;
	while (inst->next && ft_strequ("ra", (char*)inst->content))
	{
		++ra;
		inst = inst->next;
	}
	while (inst->next && ft_strequ("rb", (char*)inst->content))
	{
		++rb;
		inst = inst->next;
	}
	if (ra == rb)
		return (ra);
	else
		return (ra > rb ? rb : ra);
}

static int	ps_count_rba(t_dlist *inst)
{
	int	ra;
	int rb;

	ra = 0;
	rb = 0;
	while (inst->next && ft_strequ("rb", (char*)inst->content))
	{
		++rb;
		inst = inst->next;
	}
	while (inst->next && ft_strequ("ra", (char*)inst->content))
	{
		++ra;
		inst = inst->next;
	}
	if (ra == rb)
		return (ra);
	else
		return (ra > rb ? rb : ra);
}

static int	ps_count_rr(t_dlist *inst)
{
	if (ft_strequ("ra", (char*)inst->content))
		return (ps_count_rab(inst));
	else if (ft_strequ("rb", (char*)inst->content))
		return (ps_count_rba(inst));
	return (0);
	
}

static void	ps_replace_rr(t_dlist **inst, int rr)
{
	t_dlist	*tmp;

	ft_printf("COUNT IS: %d \n", rr);
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

static void	ps_replace_ss(t_dlist **inst)
{
	t_dlist	*tmp;

	tmp = (*inst)->next;
	(*inst)->next = (*inst)->next->next;
	if ((*inst)->next->next)
		(*inst)->next->next->prev = *inst;
	ft_dlstdelone(&tmp, ps_del);
	ft_strcpy((char*)(*inst)->content, "ss");
}

void		ps_check_inst(t_dlist **inst)
{
	if (!inst || !(*inst))
		return ;
	if ((*inst)->next)
	{
		if (ft_strequ("sa", (char*)(*inst)->content)
				&& ft_strequ("sb", (char*)(*inst)->next->content))
			ps_replace_ss(inst);
		else if (ft_strequ("sb", (char*)(*inst)->content)
				&& ft_strequ("sa", (char*)(*inst)->next->content))
			ps_replace_ss(inst);
		else if (ft_strequ("ra", (char*)(*inst)->content)
				|| ft_strequ("rb", (char*)(*inst)->content))
			ps_replace_rr(inst, ps_count_rr(*inst));
		ps_check_inst(&(*inst)->next);
	}
}
