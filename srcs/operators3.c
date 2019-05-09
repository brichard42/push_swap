/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:11:23 by brichard          #+#    #+#             */
/*   Updated: 2019/05/09 17:06:23 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_env *env)
{
	int tmp;

	if (env->a.size <= 1)
		return ;
	tmp = env->a.stack[env->a.size - 1];
	up_slide(env->a.stack, env->a.size);
	env->a.stack[0] = tmp;
}

void	rb(t_env *env)
{
	int tmp;

	if (env->b.size <= 1)
		return ;
	tmp = env->b.stack[env->b.size - 1];
	up_slide(env->b.stack, env->b.size);
	env->b.stack[0] = tmp;
}

void	rr(t_env *env)
{
	ra(env);
	rb(env);
}
