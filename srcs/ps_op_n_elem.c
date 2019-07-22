/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_n_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:27:42 by brichard          #+#    #+#             */
/*   Updated: 2019/07/22 15:43:36 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push_n_elem(t_env *env, int n, int id)
{
	while (n)
	{
		if (id == 0)
			pa(env, ps_save);
		else
			pb(env, ps_save);
		--n;
	}
}

void	ps_rotate_n_elem(t_env *env, int n, int id)
{
	while (n)
	{
		if (id == 0)
			ra(env, ps_save);
		else
			rb(env, ps_save);
		--n;
	}
}

void	ps_inverse_rotate_n_elem(t_env *env, int n, int id)
{
	while (n)
	{
		if (id == 0)
			rra(env, ps_save);
		else
			rrb(env, ps_save);
		--n;
	}
}
