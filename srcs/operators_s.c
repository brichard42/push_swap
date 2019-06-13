/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:49:12 by brichard          #+#    #+#             */
/*   Updated: 2019/06/13 15:22:20 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_env *env, void (*f)(t_env *, char *))
{
	int tmp;

	if (f)
		f(env, "sa");
	if (env->a.size < 2)
		return ;
	tmp = env->a.stack[0];
	env->a.stack[0] = env->a.stack[1];
	env->a.stack[1] = tmp;
}

void	sb(t_env *env, void (*f)(t_env *, char *))
{
	int tmp;

	if (f)
		f(env, "sb");
	if (env->b.size < 2)
		return ;
	tmp = env->b.stack[0];
	env->b.stack[0] = env->b.stack[1];
	env->b.stack[1] = tmp;
}

void	ss(t_env *env, void (*f)(t_env *, char *))
{
	if (f)
		f(env, "ss");
	sa(env, NULL);
	sb(env, NULL);
}
