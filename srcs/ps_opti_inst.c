/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti_inst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:56:15 by brichard          #+#    #+#             */
/*   Updated: 2019/07/08 16:48:39 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
//		else if (ft_strequ("ra", (char*)(*inst)->content)
//				|| ft_strequ("rb", (char*)(*inst)->content)) // useless AF
			ps_count_rr(inst);
		ps_check_inst(&(*inst)->next);
	}
}
