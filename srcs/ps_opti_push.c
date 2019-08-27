/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:13:56 by brichard          #+#    #+#             */
/*   Updated: 2019/08/27 15:41:36 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ps_opti_pa_to_pb(t_dlist **inst)
{
	int		pa;
	int		pb;
	int		ret;
	t_dlist	*tmp;

	pa = ps_count_pa(*inst, NULL);
	pb = ps_count_pb(*inst, skip_pa);
	if ((ret = pa - pb) > 0)
	{
		if (!(tmp = skip_pa((*inst), ret)))
			return ;
		ps_del_nodes(&tmp, pb * 2);
	}
	else
		ps_del_nodes(inst, pa * 2);
}

static void		ps_opti_pb_to_pa(t_dlist **inst)
{
	int		pa;
	int		pb;
	int		ret;
	t_dlist	*tmp;

	pb = ps_count_pb(*inst, NULL);
	pa = ps_count_pa(*inst, skip_pb);
	if ((ret = pb - pa) > 0)
	{
		if (!(tmp = skip_pb((*inst), ret)))
			return ;
		ps_del_nodes(&tmp, pa * 2);
	}
	else
		ps_del_nodes(inst, pb * 2);
}

void			ps_opti_push(t_dlist **inst)
{
	if (ft_strequ("pa", (char*)(*inst)->content))
		ps_opti_pa_to_pb(inst);
	else if (ft_strequ("pb", (char*)(*inst)->content))
		ps_opti_pb_to_pa(inst);
}
