/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:48:58 by brichard          #+#    #+#             */
/*   Updated: 2019/05/21 14:51:26 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_env *env)
{
	int tmp;

	ft_putendl("rra");
	if (env->a.size < 2)
		return ;
	tmp = env->a.stack[env->a.size - 1];
	down_slide(env->a.stack, env->a.size);
	env->a.stack[0] = tmp;
//	print_stack(env->a, env->b);
}

void	rrb(t_env *env)
{
	int tmp;

	ft_putendl("rrb");
	if (env->b.size < 2)
		return ;
	tmp = env->b.stack[env->b.size - 1];
	down_slide(env->b.stack, env->b.size);
	env->b.stack[0] = tmp;
//	print_stack(env->a, env->b);
}

void	rrr(t_env *env)
{
	ft_putendl("rrr");
	rra(env);
	rrb(env);
//	print_stack(env->a, env->b);
}
