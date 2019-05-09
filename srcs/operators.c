/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:41:09 by brichard          #+#    #+#             */
/*   Updated: 2019/05/09 18:13:44 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_env *env)
{
	int tmp;

	if (env->a.size <= 1)
		return ;
	tmp = env->a.stack[0];
	env->a.stack[0] = env->a.stack[1];
	env->a.stack[1] = tmp;
}

void	sb(t_env *env)
{
	int tmp;

	if (env->b.size <= 1)
		return ;
	tmp = env->b.stack[0];
	env->b.stack[0] = env->b.stack[1];
	env->b.stack[1] = tmp;
}

void	ss(t_env *env)
{
	sa(env);
	sb(env);
}
