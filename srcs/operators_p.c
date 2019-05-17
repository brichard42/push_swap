/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:48:34 by brichard          #+#    #+#             */
/*   Updated: 2019/05/17 13:45:51 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		pa(t_env *env)
{
	if (env->b.size == 0 || env->size == 0)
		return ;
	++env->a.size;
	down_slide(env->a.stack, env->a.size);
	env->a.stack[0] = env->b.stack[0];
	up_slide(env->b.stack, env->b.size);
	--env->b.size;
}

void		pb(t_env *env)
{
	if (env->a.size == 0 || env->size == 0)
		return ;
	++env->b.size;
	down_slide(env->b.stack, env->b.size);
	env->b.stack[0] = env->a.stack[0];
	ft_printf("%c | %d | %d\n", 'b', env->b.size, env->size);
	up_slide(env->a.stack, env->a.size);
	--env->a.size;
}
