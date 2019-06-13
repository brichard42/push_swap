/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:48:49 by brichard          #+#    #+#             */
/*   Updated: 2019/06/13 15:22:32 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_env *env, void (*f)(t_env *, char *))
{
	int tmp;

	if (f)
		f(env, "ra");
	if (env->a.size < 2)
		return ;
	tmp = env->a.stack[0];
	up_slide(env->a.stack, env->a.size);
	env->a.stack[env->a.size - 1] = tmp;
}

void	rb(t_env *env, void (*f)(t_env *, char *))
{
	int tmp;

	if (f)
		f(env, "rb");
	if (env->b.size < 2)
		return ;
	tmp = env->b.stack[0];
	up_slide(env->b.stack, env->b.size);
	env->b.stack[env->b.size - 1] = tmp;
}

void	rr(t_env *env, void (*f)(t_env *, char *))
{
	if (f)
		f(env, "rr");
	ra(env, NULL);
	rb(env, NULL);
}
