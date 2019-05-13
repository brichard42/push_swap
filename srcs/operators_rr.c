/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:48:58 by brichard          #+#    #+#             */
/*   Updated: 2019/05/13 17:49:02 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_env *env)
{
	int tmp;

	if (env->a.size < 2)
		return ;
	tmp = env->a.stack[env->a.size - 1];
	down_slide(env->a.stack, env->a.size);
	env->a.stack[0] = tmp;
}

void	rrb(t_env *env)
{
	int tmp;

	if (env->b.size < 2)
		return ;
	tmp = env->b.stack[env->b.size - 1];
	down_slide(env->b.stack, env->b.size);
	env->b.stack[0] = tmp;
}

void	rrr(t_env *env)
{
	rra(env);
	rrb(env);
}
