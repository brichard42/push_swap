/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti_inst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:56:15 by brichard          #+#    #+#             */
/*   Updated: 2019/08/27 15:25:28 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_check_inst(t_dlist **inst)
{
	if (!inst || !(*inst) || !(*inst)->next)
		return ;
	else if (ft_strequ("pa", (char*)(*inst)->content)
			|| ft_strequ("pb", (char*)(*inst)->content))
		ps_opti_push(inst);
	ps_check_inst(&(*inst)->next);
}
