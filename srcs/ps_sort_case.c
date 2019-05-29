/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:34:34 by brichard          #+#    #+#             */
/*   Updated: 2019/05/29 17:33:56 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_three_case_table(int a, int b, int c)
{
	if (a < b && b < c && c > a)
		return (1);
	else if (a < b && b > c && c > a)
		return (2);
	else if (a > b && b < c && a < c)
		return (3);
	else if (a < b && b > c && c < b)
		return (4);
	else if (a > b && b < c && c < a)
		return (5);
	else
		return (6);
}

static void	ps_sort_three_0(t_env *env, int cases)
{
	if (cases == 2)
	{
		rra(env);
		sa(env);
	}
	else if (cases == 3)
		sa(env);
	else if (cases == 4)
		rra(env);
	else if (cases == 5)
		ra(env);
	else if (cases == 6)
	{
		sa(env);
		rra(env);
	}
}

static void	ps_sort_three_1(t_env *env, int cases)
{
	if (cases == 1)
	{
		rb(env);
		sb(env);
	}
	else if (cases == 2)
		rb(env);
	else if (cases == 3)
		rrb(env);
	else if (cases == 4)
		sb(env);
	else if (cases == 5)
	{
		sb(env);
		rb(env);
	}
}

static void	ps_sort_three(t_env *env, int id)
{
	int	cases;
	t_stack	stck;

	stck = (id == 0 ? env->a : env->b);
	cases = ps_three_case_table(stck.stack[0], stck.stack[1], stck.stack[2]);
	if (id == 0)
		ps_sort_three_0(env, cases);
	else if (id == 1)
		ps_sort_three_1(env, cases);
}

void		ps_sort_case(t_env *env, int high, int id)
{
	if (high == 1)
	{
		if (id == 0 && env->a.stack[0] > env->a.stack[1])
			sa(env);
		else if (id == 1 && env->b.stack[0] < env->b.stack[1])
			sb(env);
	}
	else if (high == 2)
		ps_sort_three(env, id);
}
