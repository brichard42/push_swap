/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:23:47 by brichard          #+#    #+#             */
/*   Updated: 2019/08/27 16:25:08 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_three_a(t_env *env, int x, int y, int z)
{
	if (x > y && y > z)
	{
		sa(env, ps_save);
		rra(env, ps_save);
	}
	else if (y > z && z > x)
	{
		rra(env, ps_save);
		sa(env, ps_save);
	}
	else if (y > x && x > z)
		rra(env, ps_save);
	else if (x > z && z > y)
		ra(env, ps_save);
	else if (z > x && x > y)
		sa(env, ps_save);
}

void	ps_sort_three_b(t_env *env, int x, int y, int z)
{
	if (x < y && y < z)
	{
		sb(env, ps_save);
		rrb(env, ps_save);
	}
	else if (y < z && z < x)
	{
		rrb(env, ps_save);
		sb(env, ps_save);
	}
	else if (y < x && x < z)
		rrb(env, ps_save);
	else if (x < z && z < y)
		rb(env, ps_save);
	else if (z < x && x < y)
		sb(env, ps_save);
}
