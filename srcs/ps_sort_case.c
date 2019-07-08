/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:34:34 by brichard          #+#    #+#             */
/*   Updated: 2019/07/08 18:33:28 by brichard         ###   ########.fr       */
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
		ra(env, ps_save);
		sa(env, ps_save);
		rra(env, ps_save);
	}
	else if (cases == 3)
		sa(env, ps_save);
	else if (cases == 4)
	{
		ra(env, ps_save);
		sa(env, ps_save);
		rra(env, ps_save);
		sa(env, ps_save);
	}
	else if (cases == 5)
	{
		sa(env, ps_save);
		ra(env, ps_save);
		sa(env, ps_save);
		rra(env, ps_save);
	}
	else if (cases == 6)
	{
		sa(env, ps_save);
		ra(env, ps_save);
		sa(env, ps_save);
		rra(env, ps_save);
		sa(env, ps_save);
	}
}

static void	ps_sort_three_1(t_env *env, int cases)
{
	if (cases == 1)
	{
		sb(env, ps_save);
		rb(env, ps_save);
		sb(env, ps_save);
		rrb(env, ps_save);
		sb(env, ps_save);
	}
	else if (cases == 2)
	{
		sb(env, ps_save);
		rb(env, ps_save);
		sb(env, ps_save);
		rrb(env, ps_save);
	}
	else if (cases == 3)
	{
		rb(env, ps_save);
		sb(env, ps_save);
		rrb(env, ps_save);
		sb(env, ps_save);
	}
	else if (cases == 4)
		sb(env, ps_save);
	else if (cases == 5)
	{
		rb(env, ps_save);
		sb(env, ps_save);
		rrb(env, ps_save);
	}
}

static void	ps_sort_three_glob(t_env *env, int id)
{
	int	cases;
	t_stack	x;

	if (id == 0)
	{
		x = env->a;
		cases = ps_three_case_table(x.stack[0], x.stack[1], x.stack[2]);
		ps_sort_three_0(env, cases);
	}
	else if (id == 1)
	{
		x = env->b;
		cases = ps_three_case_table(x.stack[0], x.stack[1], x.stack[2]);
		ps_sort_three_1(env, cases);
	}
}

static void	ps_sort_three_little(t_env *env, int id)
{
	int	cases;
	t_stack	x;

	if (id == 0)
	{
		x = env->a;
		cases = ps_three_case_table(x.stack[0], x.stack[1], x.stack[2]);
		if (cases == 2)
		{
			sa(env, ps_save);
			rra(env, ps_save);
		}
		else if (cases == 3)
			sa(env, ps_save);
		else if (cases == 4)
			rra(env, ps_save);
		else if (cases == 5)
			ra(env, ps_save);
		else if (cases == 6)
		{
			sa(env, ps_save);
			rra(env, ps_save);
		}
	}
	else
	{
		x = env->b;
		cases = ps_three_case_table(x.stack[0], x.stack[1], x.stack[2]);
		if (cases == 1)
		{
			sb(env, ps_save);
			rrb(env, ps_save);
		}
		else if (cases == 2)
			rb(env, ps_save);
		else if (cases == 3)
			rrb(env, ps_save);
		else if (cases == 4)
			sb(env, ps_save);
		else if (cases == 5)
		{
			rrb(env, ps_save);
			sb(env, ps_save);
		}
	}
}

void		ps_sort_case(t_env *env, int high, int id)
{
	if (high == 1)
	{
		if (id == 0 && env->a.stack[0] > env->a.stack[1])
			sa(env, ps_save);
		else if (id == 1 && env->b.stack[0] < env->b.stack[1])
			sb(env, ps_save);
	}
	else if (high == 2 && ((id == 0 && (int)env->a.size != high + 1) || (id == 1 && (int)env->b.size != high + 1)))
		ps_sort_three_glob(env, id);
	else
		ps_sort_three_little(env, id); // C'ESTBUGGY
}
