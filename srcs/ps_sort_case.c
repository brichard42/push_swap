/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:34:34 by brichard          #+#    #+#             */
/*   Updated: 2019/08/27 17:18:37 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_sort_case(t_env *env, int high, int id)
{
	if (high == 1)
	{
		if (id == 0 && env->a.stack[0] > env->a.stack[1])
			sa(env, ps_save);
		else if (id == 1 && env->b.stack[0] < env->b.stack[1])
			sb(env, ps_save);
	}
	else if (high == 2 && ((id == 0 && env->a.size > 3)
				|| (id == 1 && env->b.size > 3)))
		ps_sort_three_glob(env, id);
	else if (high == 2 && id == 0)
		ps_sort_three_a(env, env->a.stack[0], env->a.stack[1], env->a.stack[2]);
	else if (high == 2 && id == 1)
		ps_sort_three_b(env, env->b.stack[0], env->b.stack[1], env->b.stack[2]);
}
