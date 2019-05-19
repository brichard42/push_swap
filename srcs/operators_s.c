/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:49:12 by brichard          #+#    #+#             */
/*   Updated: 2019/05/19 18:58:56 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_env *env)
{
	int tmp;

	if (env->a.size < 2)
		return ;
	tmp = env->a.stack[0];
	env->a.stack[0] = env->a.stack[1];
	env->a.stack[1] = tmp;
	print_stack(env->a, env->b);
}

void	sb(t_env *env)
{
	int tmp;

	if (env->b.size < 2)
		return ;
	tmp = env->b.stack[0];
	env->b.stack[0] = env->b.stack[1];
	env->b.stack[1] = tmp;
	print_stack(env->a, env->b);
}

void	ss(t_env *env)
{
	sa(env);
	sb(env);
	print_stack(env->a, env->b);
}
