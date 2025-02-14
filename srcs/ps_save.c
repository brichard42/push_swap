/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:58:12 by brichard          #+#    #+#             */
/*   Updated: 2019/08/27 16:19:53 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_save(t_env *env, char *act)
{
	t_dlist *new;

	new = NULL;
	if (!(new = ft_dlstnew((void*)act, ft_strlen(act) + 1)))
	{
		ps_delstacks(env);
		ft_dlstdel(&env->inst, ps_del);
		exit(-1);
	}
	ft_dlstadd(&(env->inst), new);
}
