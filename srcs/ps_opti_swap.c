/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:39:59 by brichard          #+#    #+#             */
/*   Updated: 2019/07/19 13:11:14 by brichard         ###   ########.fr       */
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

void		ps_opti_swap(t_dlist **inst, char *next_swap)
{
	//ajouter l'annulation de deux sa ou deux sb
	if (ft_strequ(next_swap, (char*)(*inst)->next->content))
		ps_replace_ss(inst);
}
