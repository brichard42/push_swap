/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:44:43 by brichard          #+#    #+#             */
/*   Updated: 2019/05/16 18:06:51 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_t_op.h"
#include "../libft/includes/libft.h"

int			ps_hach(char *op)
{
	size_t	s;
	size_t	i;
	int		res;

	res = 0;
	s = ft_strlen(op);
	i = 0;
	while (i < s)
		res += op[i++];
	ft_printf("%s | %d\n", op, res%11);
	return (res % 11);
}

void		ps_init_op_tab(t_op *op_tab)
{
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

