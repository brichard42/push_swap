/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three_glob.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:36:00 by brichard          #+#    #+#             */
/*   Updated: 2019/08/27 16:57:09 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_sort_three_abc(t_env *env)
{
	sa(env, ps_save);
	ra(env, ps_save);
	sa(env, ps_save);
	rra(env, ps_save);
	sa(env, ps_save);
}

static void	ps_sort_three_0(t_env *env, int a, int b, int c)
{
	if (a < b && b > c && c > a)
	{
		ra(env, ps_save);
		sa(env, ps_save);
		rra(env, ps_save);
	}
	else if (a > b && b < c && a < c)
		sa(env, ps_save);
	else if (a < b && b > c && c < a)
	{
		ra(env, ps_save);
		sa(env, ps_save);
		rra(env, ps_save);
		sa(env, ps_save);
	}
	else if (a > b && b < c && c < a)
	{
		sa(env, ps_save);
		ra(env, ps_save);
		sa(env, ps_save);
		rra(env, ps_save);
	}
	else if (a > b && b > c && c < a)
		ps_sort_three_abc(env);
}

static void	ps_sort_three_cba(t_env *env)
{
	sb(env, ps_save);
	rb(env, ps_save);
	sb(env, ps_save);
	rrb(env, ps_save);
	sb(env, ps_save);
}

static void	ps_sort_three_1(t_env *env, int a, int b, int c)
{
	if (a < b && b < c && c > a)
		ps_sort_three_cba(env);
	else if (a < b && b > c && c > a)
	{
		sb(env, ps_save);
		rb(env, ps_save);
		sb(env, ps_save);
		rrb(env, ps_save);
	}
	else if (a > b && b < c && a < c)
	{
		rb(env, ps_save);
		sb(env, ps_save);
		rrb(env, ps_save);
		sb(env, ps_save);
	}
	else if (a < b && b > c && c < a)
		sb(env, ps_save);
	else if (a > b && b < c && c < a)
	{
		rb(env, ps_save);
		sb(env, ps_save);
		rrb(env, ps_save);
	}
}

void		ps_sort_three_glob(t_env *env, int id)
{
	if (id == 0)
		ps_sort_three_0(env, env->a.stack[0], env->a.stack[1], env->a.stack[2]);
	else if (id == 1)
		ps_sort_three_1(env, env->b.stack[0], env->b.stack[1], env->b.stack[2]);
}
