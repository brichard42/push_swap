/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti_inst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:56:15 by brichard          #+#    #+#             */
/*   Updated: 2019/07/19 16:39:22 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_check_inst(t_dlist **inst)
{
	//ft_printf("| %s |\n", (*inst)->content);
	if (!inst || !(*inst) || !(*inst)->next)
		return ;
	if (ft_strequ("sa", (char*)(*inst)->content))
		ps_opti_swap(inst, "sb");
	else if (ft_strequ("sb", (char*)(*inst)->content))
		ps_opti_swap(inst, "sa");
	else if (ft_strequ("pa", (char*)(*inst)->content)
			|| ft_strequ("pb", (char*)(*inst)->content))
		ps_opti_push(inst);
	ps_check_inst(&(*inst)->next);
}
