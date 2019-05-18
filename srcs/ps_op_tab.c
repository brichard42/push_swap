/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:44:43 by brichard          #+#    #+#             */
/*   Updated: 2019/05/18 14:02:34 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_t_op.h"
#include "../libft/includes/libft.h"

int			ps_hach(char *op)
{
	if (ft_strequ(op, "pa"))
		return (0);
	else if (ft_strequ(op, "pb"))
		return (1);
	else if (ft_strequ(op, "sa"))
		return (2);
	else if (ft_strequ(op, "sb"))
		return (3);
	else if (ft_strequ(op, "ss"))
		return (4);
	else if (ft_strequ(op, "ra"))
		return (5);
	else if (ft_strequ(op, "rb"))
		return (6);
	else if (ft_strequ(op, "rr"))
		return (7);
	else if (ft_strequ(op, "rra"))
		return (8);
	else if (ft_strequ(op, "rrb"))
		return (9);
	else if (ft_strequ(op, "rrr"))
		return (10);
	return (11);
}

void		ps_init_op_tab(t_op *op_tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		op_tab[i++] = NULL;
	op_tab[ps_hach("pa")] = pa;
	op_tab[ps_hach("pb")] = pb;
	op_tab[ps_hach("sa")] = sa;
	op_tab[ps_hach("sb")] = sb;
	op_tab[ps_hach("ss")] = ss;
	op_tab[ps_hach("ra")] = ra;
	op_tab[ps_hach("rb")] = rb;
	op_tab[ps_hach("rr")] = rr;
	op_tab[ps_hach("rra")] = rra;
	op_tab[ps_hach("rrb")] = rrb;
	op_tab[ps_hach("rrr")] = rrr;
}
