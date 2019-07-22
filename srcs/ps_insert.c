/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:41:03 by brichard          #+#    #+#             */
/*   Updated: 2019/07/22 16:16:07 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_insert(t_env *env, int id)
{
	t_stack	*cur;
	t_stack	*isrt;
	int		i;

	cur = (id == 0 ? &env->a : &env->b);
	isrt = (id == 1 ? &env->a : &env->b);
	i = isrt->size;
	while (i)
	{
		print_stack(env->a, env->b);
		if (cur->stack[0] > isrt->stack[0])
		{
			ps_push_n_elem(env, 1, (id == 0 ? 1 : 0));
			--i;
		}
		else if (cur->stack[0] < isrt->stack[0])
			ps_rotate_n_elem(env, 1, id);
	}
}
