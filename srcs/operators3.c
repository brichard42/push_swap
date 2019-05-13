/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:11:23 by brichard          #+#    #+#             */
/*   Updated: 2019/05/13 14:06:38 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_env *env)
{
	int tmp;

	if (env->a.size < 2)
		return ;
	tmp = env->a.stack[0];
	up_slide(env->a.stack, env->a.size);
	env->a.stack[env->a.size - 1] = tmp;
}

void	rb(t_env *env)
{
	int tmp;

	if (env->b.size < 2)
		return ;
	tmp = env->b.stack[0];
	up_slide(env->b.stack, env->b.size);
	env->b.stack[env->b.size - 1] = tmp;
}

void	rr(t_env *env)
{
	ra(env);
	rb(env);
}
