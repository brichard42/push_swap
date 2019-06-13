/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:48:58 by brichard          #+#    #+#             */
/*   Updated: 2019/06/13 15:22:32 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_env *env, void (*f)(t_env *, char *))
{
	int tmp;

	if (f)
		f(env, "rra");
	if (env->a.size < 2)
		return ;
	tmp = env->a.stack[env->a.size - 1];
	down_slide(env->a.stack, env->a.size);
	env->a.stack[0] = tmp;
}

void	rrb(t_env *env, void (*f)(t_env *, char *))
{
	int tmp;

	if (f)
		f(env, "rrb");
	if (env->b.size < 2)
		return ;
	tmp = env->b.stack[env->b.size - 1];
	down_slide(env->b.stack, env->b.size);
	env->b.stack[0] = tmp;
}

void	rrr(t_env *env, void (*f)(t_env *, char *))
{
	if (f)
		f(env, "rrr");
	rra(env, NULL);
	rrb(env, NULL);
}
