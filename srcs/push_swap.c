/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:14:38 by brichard          #+#    #+#             */
/*   Updated: 2019/06/14 15:12:43 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_inst(t_dlist *inst)
{
	if (!inst)
		return ;
	if (inst->next)
		print_inst(inst->next);
	ft_putendl((char*)inst->content);
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac < 2)
		return (0);
	ft_bzero((void*)&env, sizeof(t_env));
	if (!(parse_arg(&env, ac, av)))
	{
		ft_memdel((void*)&env.a.stack);
		ft_memdel((void*)&env.b.stack);
		return (usage());
	}
	ps_quicksort(&env, env.size - 1, 0);
	print_inst(env.inst);
	return (0);
}
