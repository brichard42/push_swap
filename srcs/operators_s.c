/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:49:12 by brichard          #+#    #+#             */
/*   Updated: 2019/05/21 14:51:04 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_env *env)
{
	int tmp;

	ft_putendl("sa");
	if (env->a.size < 2)
		return ;
	tmp = env->a.stack[0];
	env->a.stack[0] = env->a.stack[1];
	env->a.stack[1] = tmp;
	//print*_stack(env->a, env->b);
}

void	sb(t_env *env)
{
	int tmp;

	ft_putendl("sb");
	if (env->b.size < 2)
		return ;
	tmp = env->b.stack[0];
	env->b.stack[0] = env->b.stack[1];
	env->b.stack[1] = tmp;
	//print*_stack(env->a, env->b);
}

void	ss(t_env *env)
{
	ft_putendl("ss");
	sa(env);
	sb(env);
	//print*_stack(env->a, env->b);
}
