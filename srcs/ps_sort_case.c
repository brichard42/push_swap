/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:34:34 by brichard          #+#    #+#             */
/*   Updated: 2019/07/22 16:51:11 by brichard         ###   ########.fr       */
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
	else if (a < b && b > c && c < a)
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

static void	ps_sort_three_a(t_env *env, int x, int y, int z)
{
	if (x > y && y > z)
	{
		sa(env, ps_save);
		sa(env, ps_save);
	}
	else if (y > z && z > x)
	{
		sa(env, ps_save);
		sa(env, ps_save);
	}
	else if (y > x && x > z)
		sa(env, ps_save);
	else if (x > z && z > y)
		ra(env, ps_save);
	else if (z > x && x > y)
		sa(env, ps_save);
}

static void	ps_sort_three_b(t_env *env, int x, int y, int z)
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

void		ps_sort_three_glob(t_env *env, int id)
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

void		ps_sort_case(t_env *env, int high, int id)
{
	if (high == 1)
	{
		if (id == 0 && env->a.stack[0] > env->a.stack[1])
			sa(env, ps_save);
		else if (id == 1 && env->b.stack[0] < env->b.stack[1])
			sb(env, ps_save);
	}
	else if (high == 2)// && ((id == 0 && env->a.size != 3) || (id == 1 && env->b.size != 3)))
		ps_sort_three_glob(env, id);
	//else if (high == 2 && id == 0)
		//ps_sort_three_a(env, env->a.stack[0], env->a.stack[1], env->a.stack[2]);
	//else if (high == 2 && id == 1)
		//ps_sort_three_b(env, env->b.stack[0], env->b.stack[1], env->b.stack[2]);
}
